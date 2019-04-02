//
//  main.c
//  Aufgabe1
//
//  Created by Adrian Reimer on 24.03.19.
//  Copyright © 2019 Adrian Reimer. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


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
VAR_T variab[]     = {{"var1",&var1},{"var2",&var2},{NULL,NULL}};

// define functions
void format_my_string(char *);
void replace_variables(char *, char *, int *, int *);
void replace_times(char *, char *, int *, int *);

int main(int argc, const char * argv[]) {
    // Text to parse through
    char text[] = "The first variable is &var1 and the second is &var2. Today is the {Date} and the time is {Time}.";
    format_my_string(text);
    return 0;
}

void format_my_string(char *text) {
    int ft_counter = 0; // format counter for formatted String
    int t_counter = 0;
    char ftext[256]; // formatted Text
    for (;t_counter < strlen(text); t_counter++) {
        if (text[t_counter] == '&')
            replace_variables(text,ftext,&t_counter,&ft_counter);
        else if (text[t_counter] == '{') {
            t_counter++;
            replace_times(text,ftext,&t_counter,&ft_counter);
        } else {
            ftext[ft_counter] = text[t_counter];
            ft_counter++;
        }
    }
    printf("%s\n",ftext);
}

void replace_variables(char *text, char *ftext, int *t_counter, int *ft_counter) {
    char lookup[20]; // variable string to lookup and replace
    int l_counter = 0; // rep. lookup counter
    while ((*t_counter)+1 != strlen(text) && text[(*t_counter)+1] != ' ' && text[(*t_counter)+1] != ',' && text[(*t_counter)+1] != '.') {
        lookup[l_counter] = text[(*t_counter)+1];
        l_counter++;
        (*t_counter)++;
    }
    lookup[l_counter]=0;
    for (int i = 0; i < (sizeof(variablen) / sizeof(variablen[0]));i++) {
        if (strcmp(lookup,variablen[i].name) == 0) {
            sprintf(&ftext[*ft_counter],"%d",*variablen[i].adr);
            *ft_counter += floor(log10(abs(*variablen[i].adr))) + 1;
        }
    }
}

void replace_times(char *text, char *ftext, int *t_counter, int *ft_counter) {
    char lookup[20]; // variable string to lookup and replace
    int l_counter = 0; // rep. lookup counter
    while (*t_counter != strlen(text) && text[*t_counter] != '}') {
        lookup[l_counter] = text[*t_counter];
        l_counter++;
        (*t_counter)++;
    }
    char date[12]; // string rep. of date
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (strncmp(lookup,"Date",4) == 0) {
        strftime(date,sizeof(date)-1, "%d.%m.%Y",t); // date to string conv.
    } else if (strncmp(lookup,"Time",4) == 0) {
        strftime(date,sizeof(date)-1, "%H:%M:%S",t); // time to string conv.
    }
    int date_counter = 0;
    while(date[date_counter] != '\0') {
        ftext[*ft_counter] = date[date_counter];
        (*ft_counter)++;
        date_counter++;
    }
}

