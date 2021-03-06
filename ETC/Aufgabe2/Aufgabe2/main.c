//
//  main.c
//  Aufgabe2
//
//  Created by Adrian Reimer on 01.04.19.
//  Copyright © 2019 Adrian Reimer. All rights reserved.
//

#include <stdio.h>
#include "include/awesome.h"


// >>> AUFG 2 <<<
 #define ZWEI_PI 3.14 + 3.14
// --> macro name can not start with a number
// --> surround Addition by round Brackets / define as complete int  (^ before * before +-)
#define TWO_PI (3.14 + 3.14)

//#define MAX(a, b) (a > b ? a : b)

// --> double evaluation problem
// https://stackoverflow.com/questions/39439181/what-is-double-evaluation-and-why-should-it-be-avoided
#define MAX(a, b) \
    ({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })
// https://gcc.gnu.org/onlinedocs/gcc-4.9.2/gcc/Typeof.html#Typeof

#define MANY_THINGS(a) something(a); something_else(a)
// --> what if something(a) is called different in later versions ?


// >>> AUFG 1 <<<
// backwards compatibility
#if __awesome_ver >= 3
#define something_awesome do_something_awesome
#endif

#if __awesome_ver < 3
#define do_something_awesome something_awesome
#endif

#if __awesome_ver < 2
#error Needs awesome version 2 or higher
#endif

#undef DEBUG
#ifdef DEBUG
#define DEBUG_P(format,arg...) printf(format,##arg)
#else
#define DEBUG_P(format,arg...)
#endif

// gcc -Wall -DDEBUG main.c
// ./a.out

void something(int a){
    printf("%d\n",a);
}

void something_else(int a){
    printf("%d\n",a*2);
}

int main(int argc, char **argv) {
    //printf("test %d\n",);
    DEBUG_P("%d\n",MAX(1,2));
    DEBUG_P("starting\n");
    DEBUG_P("%d\n",something_awesome(42));
    MANY_THINGS(12);
    return 0;
}

// >>> AUFG 3 <<<

//  %:include <stdio.h>
//  #define MAIN_RETURN int
//  #define MAIN_ARGS int argc, char** argv
//  MAIN_RETURN ma\
//  in(MAIN_ARGS) ??<
//  printf("He\
//         llo world!??/n");
//  %>

//  #include <stdio.h>
//  int main(int argc, char** argv) {
//  printf("Hello world!\n");
//  }

