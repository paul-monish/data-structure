/*Infix to Postfix conversion using STACK*/
#include<stdio.h>
#include<ctype.h>
char stack[100];
int top = -1;
char x;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
	return stack[top--];
}

int priority(char x)
{
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/' || x=='%')
        return 2;
    return 0;
}
void infix_to_postfix(char *e){
	printf("\nPostfix Expression is: ");
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }
	
}

int main()
{
    char exp[100];
    int i=0;
    printf("Enter the Infix expression : ");
    scanf("%s",exp);
    printf("\n");
    infix_to_postfix(exp);
	return 0;
}
