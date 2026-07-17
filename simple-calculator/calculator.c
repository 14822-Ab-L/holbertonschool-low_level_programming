#include <stdio.h>

/**
 * add - Adds two integers together.
 *
 * Return: Nothing.
 */
void add(void)
{
	int num1;
	int num2;

	printf("A: ");
	scanf("%d", &num1);

	printf("B: ");
	scanf("%d", &num2);

	printf("Result: %d\n", num1 + num2);
}

/**
 * subtract - Subtracts two integers.
 *
 * Return: Nothing.
 */
void subtract(void)
{
	int num1;
	int num2;

	printf("A: ");
	scanf("%d", &num1);

	printf("B: ");
	scanf("%d", &num2);

	printf("Result: %d\n", num1 - num2);
}

/**
 * multiply - Multiplies two integers.
 *
 * Return: Nothing.
 */
void multiply(void)
{
	int num1;
	int num2;

	printf("A: ");
	scanf("%d", &num1);

	printf("B: ");
	scanf("%d", &num2);

	printf("Result: %d\n", num1 * num2);
}

/**
 * divide - Divides two integers except 0.
 *
 * Return: Nothing.
 */
void divide(void)
{
	float num1;
	float num2;

	printf("A: ");
	scanf("%f", &num1);

	printf("B: ");
	scanf("%f", &num2);

	if (num2 == 0)
	{
		printf("Error: division by zero\n");
	}
	else
	{
		printf("Result: %.1f\n", num1 / num2);
	}
}

/**
 * main - Entry point of the simple calculator program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int option;

	printf("Simple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");

	printf("Choice: ");
	scanf("%d", &option);

	while (option != 0)
	{
		switch (option)
		{
		case 1:
			add();
			break;
		case 2:
			subtract();
			break;
		case 3:
			multiply();
			break;
		case 4:
			divide();
			break;

		default:
			printf("Invalid choice\n");
			break;
		}

		printf("Choice: ");
		scanf("%d", &option);
	}

	printf("Bye!\n");

	return (0);
}
