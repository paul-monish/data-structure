/*7. a) Write a C programs to implement Stack using Single Linked List.*/
#include<stdio.h>
#include<stdlib.h>


typedef struct ssl{
	int data;
	struct ssl *next;
}node;

int no_of_nodes=0;
node *top=NULL;


int count_node(){
	int count=0;
	node *trav=top;
	while(trav->next!=NULL){
		trav=trav->next;
		count++;
	}	
		
	return count;
}

void push(int data){
	node *new_node;
//	if(count_node()==no_of_nodes)
//		printf("STACK Overflow!!");
	if(top==NULL){
		
		new_node=(node*)malloc(sizeof(node));
		new_node->data=data;
		new_node->next=NULL;
		top=new_node;
		
	}
	else{
		new_node=(node*)malloc(sizeof(node));
		new_node->data=data;
		new_node->next=top;
		top=new_node;
	}

	
}
int pop(){
	int item;
	node* temp;
	if(top==NULL)
		printf("STACK Underflow!!");
	else{
		item=top->data;
		temp=top;
		top=top->next;
		free(temp);
		
	}
	return item;
}
void display(){
	node *trav=top;
	if(top==NULL){
		printf("STACK is empty!!");
	}
	else{
		printf("\nLinked List Elements Are:\n");
		while(trav!=NULL){
			printf("%d\n",trav->data);
			trav=trav->next;
		
		}
	
}
}

int main(){
int n,x;
char ch;
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
