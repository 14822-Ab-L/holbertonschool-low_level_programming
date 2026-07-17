#include <stdio.h>

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
