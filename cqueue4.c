#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int que[MAX],front=-1,rear=-1;

void cenque(char);
char cdelque();
void cdisplay();

int main(){
	char x,n;
	char ch;
	printf("*********Circular Queue operations using array*********");
	while(1){
		printf("\n=======================================================\n");
			printf("\nPlease select which operation you want to perform on CIRCULAR QUEUE?\n"
			"Press a for CENQUE\n"
			"press b for CDELQUE\n"
			"press c for CDISPLAY\n"
			"press d for EXIT\n");
	printf("\nEnter your choice:");
	scanf(" %c",&ch);
	switch(ch){
		case 'a':
				if((front==0 && rear==MAX-1) || (front==rear+1)){
					printf("CQUEUE is full!!");
				}
				else {
					printf("Enter character:");
					scanf(" %c",&x);
					cenque(x);
				}
			
				break;
		case 'b':
				n=cdelque();
				if(n!=-1)
					printf(" %c element are delete from CIRCULAR QUEUE",n);
				break;
		case 'c':cdisplay();break;
		case 'd':exit(0);
		default:printf("Your choice is wrong!!Please choose from above this option...");
			
	}
	}
	
	return 0;
}

void cenque(char n){
		if(rear==-1){
			rear=0;
			front=0;
		}
		else{
			rear = (rear+1)%MAX;
		}
		que[rear]=n;	
}

char cdelque(){
	char n;
	if(front==-1){
		printf("CIRCULAR QUEUE is empty!!");
		return -1;
	}
	else{
		n=que[front];
		if(front == rear){
			front = -1;
			rear = -1;
		}
		else
			front=(front + 1)%MAX;
			
		return n;
	}
	
}
void cdisplay(){
	int i,j;
	if(front==-1 && rear==-1){
		printf("CIRCULAR QUEUE is empty!!");
	}
	if(front>rear){
		for(i=front;i<MAX;i++)
			printf("%c",que[i]);
		for(j=0;j<=rear;j++)
			printf("%c",que[i]);
	}
	else{
		printf("CIRCULAR QUEUE elements are:");
		for(i=front; i<=rear; i=(i+1)){
			printf("%c",que[i]);
		}

	}
	
}
