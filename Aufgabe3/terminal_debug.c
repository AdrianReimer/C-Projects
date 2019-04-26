#include "qp_port.h"
#include "bsp.h"

#include "display.h"
#include "systick.h"
#include "nxt_avr.h"
#include "nxt_motors.h"
#include "bsp_code/nxt_motors.h"
#include "i2c.h"
#include "sonar.h"
#include "sound.h"
#include "trace32/udmon3.h"
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <terminal_debug.h>

// Codeword replacement struct
typedef struct {
    char *name;
    int  *adr;
} VAR_T;
// example variables
int var1 = 23456;
int var2 = 1711;
// fill struct array
VAR_T variablen[2] = {{"var1",&var1},{"var2",&var2}};

// read 
typedef enum
{
	IDLE,
	ACCESS1, ACCESS2, ACCESS3,
	ADDRESS1, ADDRESS2,
	INT1,
	HEX1,
	VAR1,
	COUNT1
}readMemorySystemState;

// State Machines
static readMemorySystemState readMemoryState = IDLE;
static readMemorySystemState writeMemoryState = IDLE;

// variables
static char c;
static char speicherzugriffsbreite = 'w';
static int speicheradresse;
static char var_name[50];
static int count = 1;
static int number = 0;
static U32 *pointer;
static U16 *pointer2;
static U8 *pointer3;

// globale variablen
int globale_bss = 123;
	
void readStateMachine();
void d_print();
void clearTerminal();
int concatenate(int x, int y);

void terminalFunction (void) 
{
	if (TERM_READ((unsigned char *) &c) != -1)
	{
		if ( c == ',' ) {
			clearTerminal();
		}
		if(readMemoryState == IDLE && writeMemoryState == IDLE)
		{
			if (c == 'd') {
				readMemoryState = ACCESS1;
				printf("%c",c);
			} else if (c == 's') {
				writeMemoryState = ACCESS1;
				printf("%c",c);
			}
		} else if (readMemoryState != IDLE) {
			readStateMachine();
		} else if (writeMemoryState != IDLE) {
			writeStateMachine();
		}  
	}		
}

void readStateMachine() {
	switch (readMemoryState)
	{
		case IDLE:
		{
			// do nothing
		}
		break;
		case ACCESS1:
		{
			if (c == '.') {
				printf("%c",c);
				readMemoryState = ACCESS2;
			} else if (c == ' ') {
				printf("%c",c);
				readMemoryState = ADDRESS1;
			}
		}
		break;
		case ACCESS2:
		{
			switch (c) 
			{
				case 'w':
				case 'W':
				case 's':
				case 'S':
				case 'b':
				case 'B':
					printf("%c",c);
					speicherzugriffsbreite = c;
					readMemoryState = ACCESS3;
				break;								
			}
		}
		break;
		case ACCESS3:
		{
			if (c == ' ') {
				printf("%c",c);
				readMemoryState = ADDRESS1;
			}
		}
		break;
		case ADDRESS1:
		{
			if (c == '0') {
				// Integer or Hex
				readMemoryState = ADDRESS2;
				printf("%c",c);
			} else if (c >= '1' && c <= '9') {
				// Integer
				readMemoryState = INT1;
				speicheradresse = concatenate(speicheradresse, (c - '0'));
				printf("%c",c);
			} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				// variable
				strcat(var_name, c);
				readMemoryState = VAR1;
				printf("%c",c);
			}
		}
		break;
		case ADDRESS2:
		{
			if (c == 'x') {
				// Hex
				readMemoryState = HEX1;
				printf("%c",c);
			} else if (c >= '0' && c <= '9') {
				// Integer
				readMemoryState = INT1;
				speicheradresse = concatenate(speicheradresse, (c - '0'));
				printf("%c",c);
			}
		}
		break;
		case INT1:
		{
			if(c >= '0' && c <= '9')
			{
				speicheradresse = concatenate(speicheradresse, (c - '0'));
				printf("%c",c);
			} else if (c == ' ') {
				readMemoryState = COUNT1;
				printf("%c",c);
			} else if (c == 13) {
				d_print();
			}
		}
		break;
		case HEX1:
		{
			if (c >= '0' && c <= '9')
			{
				speicheradresse = concatenate(speicheradresse, (c - '0'));
				printf("%c",c);
			} else if (c >= 'A' && c <= 'F') {
				speicheradresse = concatenate(speicheradresse, (c - 'A'+10));
				printf("%c",c);
			} else if (c == ' ') {
				readMemoryState = COUNT1;
				printf("%c",c);
			}
		}
		break;
		case VAR1:
		{
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))
			{
				strcat(var_name, c);
				printf("%c",c);
			} else if (c == ' ') {
				readMemoryState = COUNT1;
				printf("%c",c);
			} else if( c == 13) {
				d_print();
			}
		}
		break;
		case COUNT1:
		{
			if(c >= '0' && c <= '9')
			{
				count = (c - '0');
				printf("%c",c);
			} else if (c == 13) {
				d_print();
			}
		}
		break;
		default:
		break;
	}
}

void writeStateMachine() {
	switch (writeMemoryState)
	{
		case IDLE:
		{
			// do nothing
		}
		break;
		case ACCESS1:
		{
			if (c == '.') {
				printf("%c",c);
				writeMemoryState = ACCESS2;
			} else if (c == ' ') {
				printf("%c",c);
				writeMemoryState = ADDRESS1;
			}
		}
		break;
		case ACCESS2:
		{
			switch (c) 
			{
				case 'w':
				case 'W':
				case 's':
				case 'S':
				case 'b':
				case 'B':
					printf("%c",c);
					speicherzugriffsbreite = c;
					writeMemoryState = ACCESS3;
				break;								
			}
		}
		break;
		case ACCESS3:
		{
			if (c == ' ') {
				printf("%c",c);
				writeMemoryState = ADDRESS1;
			}
		}
		break;
		case ADDRESS1:
		{
			if (c == '0') {
				// Integer or Hex
				writeMemoryState = ADDRESS2;
				printf("%c",c);
			} else if (c >= '1' && c <= '9') {
				// Integer
				writeMemoryState = INT1;
				speicheradresse = concatenate(speicheradresse, (c - '0'));
				printf("%c",c);
			} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				// variable
				strcat(var_name, c);
				writeMemoryState = VAR1;
				printf("%c",c);
			}
		}
		break;
		case ADDRESS2:
		{
			if (c == 'x') {
				// Hex
				writeMemoryState = HEX1;
				printf("%c",c);
			} else if (c >= '0' && c <= '9') {
				// Integer
				writeMemoryState = INT1;
				speicheradresse = concatenate(speicheradresse, (c - '0'));
				printf("%c",c);
			}
		}
		break;
		case INT1:
		{
			if(c >= '0' && c <= '9')
			{
				speicheradresse = concatenate(speicheradresse, (c - '0'));
				printf("%c",c);
			} else if (c == ' ') {
				writeMemoryState = COUNT1;
				printf("%c",c);
			}
		}
		break;
		case HEX1:
		{
			if (c >= '0' && c <= '9')
			{
				speicheradresse = concatenate(speicheradresse, (c - '0'));
				printf("%c",c);
			} else if (c >= 'A' && c <= 'F') {
				speicheradresse = concatenate(speicheradresse, (c - '0'));
				printf("%c",c);
			} else if (c == ' ') {
				writeMemoryState = COUNT1;
				printf("%c",c);
			}
		}
		break;
		case VAR1:
		{
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <= '9'))
			{
				strcat(var_name, c);
				printf("%c",c);
			} else if (c == ' ') {
				speicheradresse = atoi(var_name);
				writeMemoryState = COUNT1;
				printf("%c",c);
			}
		}
		break;
		case COUNT1:
		{
			if(c >= '0' && c <= '9')
			{
				number = concatenate(number, (c - '0'));
				printf("%c",c);
			} else if (c == 13) {
				int * p_reg = (int *) speicheradresse;
				*p_reg = number;
				printf(" Wert %d in speicherstelle %d ", number, *p_reg);
				writeMemoryState = IDLE;
				
				speicherzugriffsbreite = 'w';
				speicheradresse = 0;
				memset(var_name,0,sizeof(var_name));
				number = 0;
			}
		}
		break;
		default:
		break;
	}
}

void d_print() {
	if (strlen(var_name) > 0) {
		int i = 0;
		for (; i < (sizeof(variablen) / sizeof(variablen[0]));i++) {
			if (strncmp(var_name,variablen[i].name, strlen(variablen[i].name)) == 0) {
				speicheradresse = (int)variablen[i].adr;
			}
		}
	}
	
	pointer = (U32 *)speicheradresse;
	pointer2 = (U16 *)speicheradresse;
	pointer3 = (U8 *)speicheradresse;
	switch (speicherzugriffsbreite) {
		case 'w':
		case 's':
		case 'b':
			printf(" -->  %X : ",speicheradresse);
			break;
		case 'W':
		case 'S':
		case 'B':
			printf(" -->  %d : ",speicheradresse);
			break;
	}
	
	while (count > 0 ) 
	{
		switch (speicherzugriffsbreite) {
			case 'w':
				printf(" %08X  ",*pointer++);
				printf(" %08x  ",*((U32 *)speicheradresse));
				speicheradresse+=4;
				break;
			case 'W':
				printf(" %7d  ",*pointer++);
				break;
			case 's':
				printf(" %04X  ",*pointer2++);
				break;
			case 'S':
				printf(" %5d  ",*pointer2++);
				break;
			case 'b':
				printf(" %2x  ",*pointer3++);
				break;
			case 'B':
				printf(" %3d  ",*pointer3++);
				break;
		}
		count--;
	}
	readMemoryState = IDLE;
	// reset
	speicherzugriffsbreite = 'w';
	speicheradresse = 0;
	memset(var_name,0,sizeof(var_name));
	count = 1;
}

int concatenate(int x, int y) {
    int pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

void clearTerminal()
{
	printf("\e[1;1H\e[2J");
}
	

