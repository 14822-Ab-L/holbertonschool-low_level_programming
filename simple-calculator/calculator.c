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
		case 3:
		case 4:
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
