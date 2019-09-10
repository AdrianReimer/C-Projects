//
// Created by adrianreimer on 9/10/19.
//

/*
    Good morning! Here's your coding interview problem for today.

    This problem was asked by Jane Street.

    Given an arithmetic expression in Reverse Polish Notation, write a program to evaluate it.

    The expression is given as a list of numbers and operands. For example: [5, 3, '+'] should return 5 + 3 = 8.

    For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should return 5,
    since it is equivalent to ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.

    You can assume the given expression is always valid.
 */

#include <stdlib.h>
#include "day38.h"


int revPolNot(char *expression, size_t length)
{
    size_t numberIdx = 0;
    size_t operandIdx = 1;
    char number = expression[numberIdx];
    char operand = expression[operandIdx];
    int absSol = 0;
    while(operandIdx < length) {
        if(operand > '0' && operand < '9') {
            number = expression[++numberIdx];
            operand = expression[++operandIdx];
        } else {
            int partSol = number - '0';
            number = expression[--numberIdx];
            while(number > '0' && number < '9') {
                switch(operand) {
                    case '+':
                        partSol = (number - '0') + partSol;
                        break;
                    case '-':
                        partSol = (number - '0') - partSol;
                        break;
                    case '*':
                        partSol = (number - '0') * partSol;
                        break;
                    case '/':
                        partSol = (number - '0') / partSol;
                        break;
                }
                number = expression[--numberIdx];
                operand = expression[++operandIdx];
            }
            switch(operand) {
                case '-':
                    absSol -= partSol;
                    operand = expression[++operandIdx];
                    break;
                case '*':
                    absSol *= partSol;
                    operand = expression[++operandIdx];
                    break;
                case '/':
                    absSol /= partSol;
                    operand = expression[++operandIdx];
                    break;
                default:
                    absSol += partSol;
                    operand = expression[++operandIdx];
            }
            numberIdx = operandIdx - 1;
        }
    }
    return absSol;
}