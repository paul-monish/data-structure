/*Postfix evaluation*/
#include<stdio.h>
#include<ctype.h>
#include<math.h>
char stack[100];
int top = -1;
void push(int x)
{
    stack[++top] = x;
}

char pop()
{
	return stack[top--];
}


void postfixEvaluation(char *e){
	int a,b,ans;
    while(*e != '\0')
    {
        if(isdigit(*e))
            push(*e-'0');
        else
        {
            a=pop();
            b=pop();
            switch(*e){
            	case '^':ans=pow(b,a);
            			break;
            	case '+':ans=a+b;
            			break;
            	case '-':ans=a-b;
            			break;
            	case '*':ans=a*b;
            			break;
            	case '/':ans=a/b;
            			break;
            		
			}
			push(ans);
        }
        e++;
    }
    
   printf("After postfix evaluation= %d",pop());
	
}

int main()
{
    char exp[100];
    printf("Enter the postfix expression : ");
    scanf("%s",exp);
    printf("\n");
    postfixEvaluation(exp);
	return 0;
}
