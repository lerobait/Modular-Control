/**
	@file main.c
	Модульний контроль.
	@author Nikulin A.
*/

/**
	Заголовний файл
*/
#include "lib.h"

/**
	Обчислення математичних виразів.
	
	@return код помилки (0)
	
	@param Calculator це структура з полем expression, яке вказує на масив. 
    @param result змінна яка зберігає результат.
*/
    
/**
	Точка входу до програми. Демонстрація рішення.
*/

int main() {
    char mathOp[MAX_MATHOP_LENGTH];
    Calculator calc = { mathOp };
    printf("Enter a math expression: ");
    fgets(mathOp, MAX_MATHOP_LENGTH, stdin);
    int result = calculate(&calc);
    printf("Result: %d\n", result);
    return 0;
}
