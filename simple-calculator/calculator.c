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

    if (option == 0)
    {
        printf("Bye!\n");
    }

    return (0);
}
