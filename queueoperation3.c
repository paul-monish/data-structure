#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int que[MAX],front=-1,rear=-1;

void enque(char);
char delque();
void display();

int main(){
	char x,n;
	char ch;
	
//	printf("Enter the size of QUEUE:");
//	scanf("%d",&max);
	
	while(1){
		printf("\n=======================================================\n");
			printf("\nPlease select which operation you want to perform on QUEUE?\n"
			"Press a for ENQUE\n"
			"press b for DELQUE\n"
			"press c for DISPLAY\n"
			"press d for EXIT\n");
	printf("\nEnter your choice:");
	scanf(" %c",&ch);
	switch(ch){
		case 'a':
				printf("Enter character:");
				scanf(" %c",&x);
				enque(x);
				break;
		case 'b':
				n=delque();
				if(n!=-1)
					printf(" %c element are delete from QUEUE",n);
				break;
		case 'c':display();break;
		case 'd':exit(0);
		default:printf("Your choice is wrong!!Please choise above this option...");
			
	}
	}
	
	return 0;
}

void enque(char n){
	if(rear==MAX-1){
		printf("QUEUE is full!!");
	}
	else {
		if(front==-1)
			front=0;
		que[++rear]=n;
	}
	
}

char delque(){
	char n;
	if(front==-1 || front>rear){
		printf("QUEUE is empty!!");
		return -1;
	}
	else{
		n=que[front];
		front++;
		return n;
	}
	
}
void display(){
	int i;
	if(front==-1){
		printf("QUEUE is empty!!");
	}
	else{
		printf("QUEUE elements are:");
		for(i=front;i<=rear;i++){
			printf(" %c",que[i]);
		}
		
	}
	
}
