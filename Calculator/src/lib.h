/**
	@file lib.h
	Модульний контроль.
	@author Nikulin A.
*/

#ifndef HEADER_H
#define HEADER_H

/**
	Підключені бібліотеки.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <check.h>
#include <dirent.h>


/**
	Константа зі значенням 1000.
*/
#define MAX_MATHOP_LENGTH 1000

/**
	Структура з полем expression.
*/
typedef struct {
    char *expression;
} Calculator;

/**
	Прототипи функцій.
*/
int calcTerm(Calculator *calc, int *i);
int calcDegree(Calculator *calc, int *i);
int mathOpInBrackets(Calculator *calc, int *i);
int calcNum(Calculator *calc, int *i);
int calculate(Calculator *calc);

#endif
