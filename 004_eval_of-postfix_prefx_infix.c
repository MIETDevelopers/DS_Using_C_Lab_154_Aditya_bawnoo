//creation date:3 July 2021;
//purpose:To solve postfix expressions using stack
//Author:Aditya Bawnoo
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define Size_operator 10
#define Size_operand 10
int top_operand = -1;
int top_operator = -1;
char operator_stack[10];
int operand_stack[10];
void push_operand(int);
void push_operator(char);
int pop_operand();
char pop_operator();
int evaluation();
int main()
{
	char exp[20];
	int i;
	char digit;
	int number;
	printf("enter postfix expression\n");
	scanf("%s", exp);
	printf("entered postfix expression %s\n", exp);
	for (i = 0; exp[i] != '\0'; i++)
	{
		digit = exp[i];
		if (isdigit(digit))
		{
			number = digit - '0';
			push_operand(number);
		}
		else
		{
			push_operator(digit);
		}
	}
	evaluation();
	printf("%d\n", operand_stack[0]);
}
void push_operator(char digit)
{
	if (top_operator == Size_operator - 1)
	{
		printf("Stack Overflow");
	}
	else
	{
		top_operator++;
		operator_stack[top_operator] = digit;
	}
}
void push_operand(int operand)
{
	if (top_operand == Size_operand - 1)
	{
		printf("Stack Overflow");
	}
	else
	{
		top_operand++;
		operand_stack[top_operand] = operand;
	}
}
int pop_operand()
{
	int operand;
	if (top_operand == -1)
	{

		exit(0);
	}
	else
	{
		operand = operand_stack[top_operand];
		top_operand--;
	}
	return operand;
}
char pop_operator()
{
	char operator;
	if (top_operator == -1)
	{
		printf("No operator in stack\n");
		exit(0);
	}
	else
	{
		operator= operator_stack[top_operator];
		top_operator--;
	}
	return operator;
}
int evaluation()
{
	int operand_1, operand_2, result;
	char operator;
	if (top_operand == -1)
	{
		printf("no more operator in stack");
		exit(0);
	}
	else
	{
		for (int i = top_operator; top_operator > -1; i++)
		{
			operator= pop_operator();
			operand_1 = pop_operand();
			operand_2 = pop_operand();
			switch (operator)
			{
			case '+':
				result = operand_1 + operand_2;

				break;
			case '-':
				result = operand_1 - operand_2;

				break;
			case '*':
				result = operand_1 * operand_2;

				break;
			case '/':
				result = operand_1 / operand_2;

				break;
			default:
				printf("undefined operator");
			}
			push_operand(result);
		}
	}
	return operand_stack[0];
}
