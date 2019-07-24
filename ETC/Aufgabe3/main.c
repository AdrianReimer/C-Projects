/*****************************************************************************
* Product: DPP example
* Last Updated for Version: 4.2.00
* Date of the Last Update:  Jul 23, 2011
*
*                    Q u a n t u m     L e a P s
*                    ---------------------------
*                    innovating embedded systems
*
* Copyright (C) 2002-2011 Quantum Leaps, LLC. All rights reserved.
*
* This software may be distributed and modified under the terms of the GNU
* General Public License version 2 (GPL) as published by the Free Software
* Foundation and appearing in the file GPL.TXT included in the packaging of
* this file. Please note that GPL Section 2[b] requires that all works based
* on this software must also be made publicly available under the terms of
* the GPL ("Copyleft").
*
* Alternatively, this software may be distributed and modified under the
* terms of Quantum Leaps commercial licenses, which expressly supersede
* the GPL and are specifically designed for licensees interested in
* retaining the proprietary status of their code.
*
* Contact information:
* Quantum Leaps Web site:  http://www.quantum-leaps.com
* e-mail:                  info@quantum-leaps.com
*****************************************************************************/
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
//#include "mytypes.h"
#include "trace32/udmon3.h"
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <terminal_debug.h>

	int _read_r (void *r, int fileDesc, char *ptr, int len)
	{
    	    /* GetChar : Your implementation to receive the character 
      	 from the serial port.*/
          //*ptr=GetChar();  
    	       return (1);
	}

	_ssize_t _write_r(void *r, int fileDesc,char *ptr,int len)
	{
	    int i;
 	    /* PutChar : Your implementation to send the character to the 
          serial port.*/
	    for(i=0;i<len;i++)
	    {      
		  TERM_CHAR(*ptr++);
	    } 
	    return len;
	}
	
      S32 globale_bss;
	  S32 globale_bss2;
      S32 globale_data=44;
const U32 globale_const=44;
	
//R0-R12 = User Registers 
//R13 = StackPointer (SP)
//R14 = Link Register (LR) When a call is made to a function the return address is automatically
//                         stored in the link register an dis immediately availabe on return from
//                         the function. this allows quick entry and return into a "leaf" function
//                         (a function that is not going to call further functions). If the function
//                         is part of a brach (i.e. it is going to call other functions) the the
//                         link register must be preserved on the stack
//R15 = Program counter (PC)

extern uint32_t __stack_start__[];   //Definiert in link.ld
extern uint32_t __stack_end__;       //Definiert in link.ld
#define STACK_FILL 0xAAAAAAAA
#define Var2A2L(var) {.str = #var, ptr = &var}

extern volatile U8 dirty;

/*****************************************************/
/* Eigenes Betriebssystem                            */
/*****************************************************/

const int MAX_NUMBER_LENGTH = 4; // change array size || line:168

 unsigned int concatenate(unsigned int zahl1, unsigned int zahl2);
 
 typedef struct {
	char *str;
	void *ptr;
}A2L;

int main(int argc, char *argv[]) 
{
	
	BSP_init();           /* initialize the Board Support Package */
	
	QF_init();     /* initialize the framework and the underlying RT kernel */

	QF_onStartup();  //ISR Initialisieren

	display_init();
	nxt_avr_init();
	nxt_motor_init();
//	i2c_init();
//		sound_init();

	display_clear(0);
	display_string("Hello World");
	display_update();

	display_goto_xy(0,1);
	display_int(globale_bss,3);
	display_int(globale_data,3);
	display_update();
	
	//ANSI Escape sequences - VT100 / VT52
	//http://ascii-table.com/ansi-escape-sequences-vt-100.php
	//\a The “alert” character, Ctrl-g, ASCII code 7 (BEL). (This usually makes some sort of audible noise.)
	//\b Backspace, Ctrl-h, ASCII code 8 (BS).
	//\f Formfeed, Ctrl-l, ASCII code 12 (FF).
	//\n Newline, Ctrl-j, ASCII code 10 (LF).
	//\r Carriage return, Ctrl-m, ASCII code 13 (CR).
	//\t Horizontal TAB, Ctrl-i, ASCII code 9 (HT).
	//\v Vertical tab, Ctrl-k, ASCII code 11 (VT).
	//\nnn The octal value nnn, where nnn stands for 1 to 3 digits between ‘0’ and ‘7’. For example, the code for the ASCII ESC (escape) character is ‘\033’.
	//\xhh...The hexadecimal value hh, where hh stands for a sequence of hexadecimal digits (‘0’–‘9’, and either ‘A’–‘F’ or ‘a’–‘f’). 
	//       Like the same construct in ISO C, the escape sequence continues until 
	//       the first nonhexadecimal digit is seen. (c.e.) However, using more 
	//       than two hexadecimal digits produces undefined results. 
	//       (The ‘\x’ escape sequence is not allowed in POSIX awk.)
	//\/ A literal slash (necessary for regexp constants only). This sequence 
	//       is used when you want to write a regexp constant that contains a 
	//       slash. Because the regexp is delimited by slashes, you need to 
	//       escape the slash that is part of the pattern, in order to tell 
	//       awk to keep processing the rest of the regexp.
	//\"  A literal double quote (necessary for string constants only). 
	//       This sequence is used when you want to write a string constant 
	//       that contains a double quote. Because the string is delimited by 
	//       double quotes, you need to escape the quote that is part of 
	//       the string, in order to tell awk to keep processing the rest
	//       of the string.#define ANSI_BLACK   30
#if 0
#define ANSI_RED     31
#define ANSI_GREEN   32
#define ANSI_YELLOW  33
#define ANSI_BLUE    34
#define ANSI_MAGENTA 35
#define ANSI_CYAN    36
#define ANSI_WHITE   37

#define clrscr()			printf("\33[2J")
#define clreol()			printf("\33[K")
#define normal()			printf("\33[0m")
#define highlight()		printf("\33[1m")
#define blink()			printf("\33[5m")
#define invers()			printf("\33[7m")
#define textcolor(f,b)		printf("\33[%d;%dm", f, b+10)
#define gotoxy(x, y)		printf("\33[%d;%dH", y, x)
#define save_cursor()		printf("\33[s")
#define restore_cursor()	printf("\33[u")
#endif
	

	
	while(1)
	{
		terminalFunction();
	}
}


