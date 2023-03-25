//Program to evaluate any given postfix expression.
#include <stdio.h>

void evaluatePostfix(char *postFix)
{
    int n = 0, TOP = -1;
    char stack[10];
    while (postFix[n] != '\0')
    {
        if (isOperator(postFix[n]))
        {
            int A = POP(stack, &TOP) - '0';
            int B = POP(stack, &TOP) - '0';
            int ans = evaluate(A, B, postFix[n]);
            PUSH(stack, &TOP, ans + '0');
        }
        else
            PUSH(stack, &TOP, postFix[n]);
        n++;
    }
    printf("Evaluated answer is: %d", stack[TOP] - '0');
}
int evaluate(int A, int B, char X)
{
    if (X == '/')
        return (B / A);
    else if (X == '*')
        return (B * A);
    else if (X == '+')
        return (B + A);
    else if (X == '-')
        return (B - A);
}
void PUSH(char *stack, int *TOP, char X)
{
    (*TOP)++;
    stack[*TOP] = X;
}
char POP(char *stack, int *TOP)
{
    char X = stack[*TOP];
    (*TOP)--;
    return X;
}
int isOperator(char X)
{
    if (X == '+' || X == '-' || X == '*' || X == '/')
        return 1;
    else
        return 0;
}

void main()
{
    char postFix[20] = "345*+";
    evaluatePostfix(postFix);
}