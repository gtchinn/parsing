#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* NOTE:
 * - you may not use atoi
 * - you may not use *any* built-in functions -- strlen, strcpy, etc.
 * - you may assume all integers have <10 digits
 */

typedef struct
{
    int key[100];
    unsigned int count;
}Stack;

void Initialize(Stack *s)
{
    s->count = 0;
}

void Push(Stack *s, int X)
{
    s->count += 1;
    s->key[s->count - 1] = X;
}

int Pop(Stack *s)
{
    s->count = s->count - 1;
    return s->key[s->count];
}

int checkOp(char *op)
{
    if (op[1] != '\0')
    {
	printf("ERROR: operation may only be + or -\n");
	exit(EXIT_FAILURE);
    }
    if (op[0] != '+' && op[0] != '-' && op[0] != 'x')
    {
	printf("ERROR: operation may only be + or -\n");
	exit(EXIT_FAILURE);
    }
    return 0;
}

int checkStr(char *string)
{
    int i = 0;
    if (string[0] == '-')
    {
	i = 1;
    }
    for (i; i < 11; i++)
    {
	if (string[i + 1] == '\0')
	{
	    break;
	}
	if (string[i] > 57 || string[i] < 48)
	{
	    printf("ERROR: number has character that is outside 0-9\n");
	    exit(EXIT_FAILURE);
	}
    }
}

int strNum(char *num)
{
    int i = 0;
    int char1 = num[0];

    if (char1 == '-')
    {
	if (strlen(num) > 11)
	{
	    printf("ERROR: number has 10 or more digits\n");
	    exit(EXIT_FAILURE);
	}
	i = 1;
    }
    else
    {
	if (strlen(num) > 10) 
	{
	    printf("ERROR: number has 10 or more digits\n");
	    exit(EXIT_FAILURE);
	}
    }
    if (num[0] != '-')
    {
	char1 = char1 - '0';
    }
    for (i; i < 11; i++)
    {
	if (num[i + 1] == '\0')
	{
	    break;
	}
	else
	{
	    if (char1 != '-')
	    {
	        char1 = char1 * 10 + (num[i + 1] - '0');
	    }
	    else
	    {
	        char1 = num[1] - '0';
	        char1 = char1 * 10 + (num[i + 1] - '0');
	    }
	}
    }
    if (num[0] == '-')
    {
	char1 *= -1;
    }
    return char1;
}

int main(int argc, char *argv[])
{
    Stack *my_stack;
    Initialize(my_stack);
    int total;
    int digit;
    int p1, p2;
    for (int i = 1; i < argc; i++)
    {
	char *value = argv[i];
	if (value[0] == '+' || value[0] == '-' || value[0] == 'x')
	{
	    p1 = Pop(my_stack);
	    p2 = Pop(my_stack);
	    if (value[0] == '+')
	    {
		total = p1 + p2;
	    }
	    if (value[0] == '-')
	    {
		total = p2 - p1;
	    }
	    if (value[0] == 'x')
	    {
		total = p2 * p1;
	    }
	    Push(my_stack, total);
	}
	else
	{
	    digit = strNum(value);
	    Push(my_stack, digit);
	}
    }
    printf("The total is %d\n", Pop(my_stack));
}
    /* Turn number1 into an integer.  You will need to do this by
     * looking at the character string one character at a time, and multiplying
     * by 10 as you go.
     * For example: if the string is "214", then I would start by finding the
     * '2'.  I would think (for the time being) the number is 2.  When I go
     * to the next character, I would see the "1".  I would then make the 
     * number 21, by multiplying my previous number (2) by 10 and adding the
     * current number (1) ... 2*10+1 = 21.
     * The next number is 4.  Again, take the previous number (21) times 10
     * and add the current number (4).  This makes 214.
     * The next character is the NULL character.  So we are done parsing the
     * string.  And stop at 214.
     * TRICK #1! --->
     *    char digit = '5';
     *    int digit_as_number = digit - '0'; <--- gives you 5.
     * TRICK #2! --->
     *    when you encounter a '\0', then use break to terminate the loop
     *    right then.
     */

    /* Now figure out which operation to do: plus or minus.
     * You will do this by inspecting the variable named "operation". */

    /* Now turn number2 into an integer. */
 
    /* Perform the operation and print the result */

