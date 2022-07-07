#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct stack{
	int stk[MAX];
	int top;
} s;

void push(int x){
	if(s.top==(MAX-1)){
		printf("STACK overflow!!");
	}
	else{
		s.stk[++s.top]=x;
	}
}

int pop(){
	int item;
	if(s.top==-1){
		return -1;
	}
	else{
		item=s.stk[s.top--];
		return item;
	}
}
void display(){
	int i=s.top;
	printf("\n==================STACK elements are===============\n");
	if(s.top==-1){
		printf("STACK is empty!!");
	}
	
	while(i>=0){
		printf("%d\n",s.stk[i]);
		i--;
	}
}
int main(){
int n,x;
char ch;
s.top=-1;
while(1){
		printf("\n=======================================================\n");
			printf("\nPlease select which operation you want to perform on STACK?\n"
			"Press a for push\n"
			"press b for pop\n"
			"press c for display\n"
			"press d for exit\n");
	printf("\nEnter your choice:");
	scanf(" %c",&ch);
	switch(ch){
		case 'a':printf("Enter value:");
				 scanf("%d",&x);
				 push(x);
				 break;
		case 'b':n=pop();
				if(n==-1){
					printf("STACK Underflow!!");
				}else{
					printf("%d are poped from STACK",n);
				}
				break;
		case 'c':display();
				 break;
		case 'd':printf("You are exit!!");
				exit(0);
		default:printf("Your choice is wrong!!Please choise above this option...");
			
	}
	}
	return 0;
}
