#include<stdio.h>
#include<stdlib.h>
int stk[50],max,top=-1;

void push(int);
int pop();
void display();

int main(){
	int x,n;
	char ch;
	
	printf("Enter the size of STACK:");
	scanf("%d",&max);
		
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
		case 'a':printf("Enter value:");scanf("%d",&x);push(x);break;
		case 'b':n=pop();printf("%d element are poped from STACK",n);break;
		case 'c':display();break;
		case 'd':exit(0);
		default:printf("Your choice is wrong!!Please choise above this option...");
			
	}
	}
	
	return 0;
}

void push(int n){
	if(top==max-1){
		printf("STACK overflow!!");
	}
	else{
		stk[++top]=n;
	}
	
}

int pop(){
	int n;
	if(top==-1){
		printf("STACK underflow!!");
	}
	else{
		n=stk[top--];
	}
	return n;
}
void display(){
	int i=0;
	printf("STACK elements are:");
	for(;i<max;i++){
		printf("%d",stk[i]);
	}
}
