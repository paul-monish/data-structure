/*b) Write a C programs to implement Queue using Single Linked List.*/
#include<stdio.h>
#include<stdlib.h>


typedef struct ssl{
	int data;
	struct ssl *next;
}node;

int no_of_nodes=0;
node *front=NULL,*rear=NULL;




void enque(char data){
	node *new_node;
	new_node=(node*)malloc(sizeof(node));
	new_node->data=data;
	new_node->next=NULL;
	if(front==NULL && rear==NULL){	
		rear=new_node;
		front=new_node;
		
	}
	else{
		rear->next=new_node;
		rear=new_node;
	}

	
}
int delque(){
	char item;
	node* temp=front;
	if(front==NULL){
		printf("QUEUE is empty!!");
		return -1;
	}
		
	else if(front==rear){
		printf("y");
		item=front->data;
		front=NULL;
		rear=NULL;
		free(temp);
		return item;
	}
	else{
		item=front->data;
		front=front->next;
		free(temp);
		return item;
	}
	
}
void display(){
	node *trav=front;
	if(front==NULL){
		printf("QUEUE is empty!!");
	}
	else{
		printf("\nQUEUE Elements Are:\n");
		while(trav!=NULL){
			printf("%c\t",trav->data);
			trav=trav->next;
		}
	
	}
}

int main(){
	char x,n;
	char ch;
	
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
