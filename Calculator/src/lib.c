/**
	@file lib.c
	Модульний контроль.
	@author Nikulin A.
*/

/**
	Заголовний файл
*/
#include "lib.h"

/**
	Функція здійснює обчислення добутку, частки або залишку від ділення з операндами з виразу, починаючи з певної позиції у виразі.
	
	@param result це змінна, яка зберігає проміжний результат обчислення виразу.
    @param operator це змінна, яка зберігає оператор, знак математичної операції, який потрібно застосувати до двох операндів для обчислення результату.
    @param operand це змінна, яка зберігає операнд, числове значення, що використовується разом з оператором для виконання математичної операції та отримання результату.
*/

int calcTerm(Calculator *calc, int *i) {

    int result = calcDegree(calc, i);

    while(calc->expression[*i] == '*' || calc->expression[*i] == '/' || calc->expression[*i] == '%') {

        char operator = calc->expression[(*i)++];
        int operand = calcDegree(calc, i);

        if(operator == '*') {
            result *= operand;
        } else if(operator == '/') {
            result /= operand;
        } else {
            result = result % operand;
        }
    }
    return result;
}

/**
	Функція дозволяє обробляти вирази, що містять степінь числа, або повертає саме число, якщо степінь відсутня.
	
	@param result це змінна, яка зберігає проміжний результат обчислення виразу.
    @param degree це локальна змінна, що містить значення степеня числа, яке буде використовуватися для обчислення значення числа у випадку, якщо вираз містить символ степеня "^".
*/

int calcDegree(Calculator *calc, int *i) {

    int result = calcNum(calc, i);

    if(calc->expression[*i] == '^') {
        (*i)++;
        int degree = calcDegree(calc, i);
        result = pow(result, degree);
    }
    return result;
}

/**
	Функція виконує обчислення математичного виразу, який міститься у дужках, що знаходяться на поточній позиції в рядку виразу.
	
	@param result це змінна, яка зберігає проміжний результат обчислення виразу.
    @param operator це змінна, яка зберігає оператор, знак математичної операції, який потрібно застосувати до двох операндів для обчислення результату.
    @param term це змінна, представляє значення виразу, що йде після оператора додавання (+) або віднімання (-) і передається функції.
*/

int mathOpInBrackets(Calculator *calc, int *i) {

    int result = calcTerm(calc, i);

    while(calc->expression[*i] == '+' || calc->expression[*i] == '-') {

        char operator = calc->expression[(*i)++];
        int term = calcTerm(calc, i);

        if(operator == '+') {
            result += term;
        } else {
            result -= term;
        }
    }
    return result;
}

/**
	Функція призначена для обчислення числових значень в математичному виразі, що подається у вигляді рядка.

    @param result це змінна, яка зберігає проміжний результат обчислення виразу.
    @param sign це змінна, яка використовується для збереження знаку числа, яке знаходиться на поточній позиції в рядку.
*/

int calcNum(Calculator *calc, int *i) {

    int result = 0;
    int sign = 1;

    if(calc->expression[*i] == '-') {
        sign = -1;
        (*i)++;
    }
    if(calc->expression[*i] == '(') {
        (*i)++;
        result = mathOpInBrackets(calc, i);
        (*i)++;
    } else {
        while(isdigit(calc->expression[*i])) {
            result = result * 10 + (calc->expression[(*i)++] - '0');
        }
    }
    return sign * result;
}

/**
	Функція обчислює вираз, який містить від'ємні числа, дужки, операції додавання, віднімання, множення, ділення та залишок від ділення. 

    @param i це цілочислена змінна, яка використовується як індекс для ітерації по символам рядка.
*/

int calculate(Calculator *calc) {

    int i = 0;

    return mathOpInBrackets(calc, &i);
}

