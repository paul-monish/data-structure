#include<stdio.h>
#include<stdlib.h>


typedef struct ssl{
	int data;
	struct ssl *next;
}node;


node *start=NULL;

node* create_ssl(){
	node *new_node,*trav;
	int i=0,no_of_nodes,data;
	printf("Enter How many nodes you want to create in Linked List?");
	scanf("%d",&no_of_nodes);
	
	new_node=(node*)malloc(sizeof(node));
	printf("Enter data:");
	scanf("%d",&data);
	new_node->data=data;
	new_node->next=NULL;
	start=new_node;
	i=2;
	while(i<=no_of_nodes){
		trav=new_node;
		new_node=(node*)malloc(sizeof(node));
		printf("Enter data:");
		scanf("%d",&data);
		new_node->data=data;
		new_node->next=NULL;
		trav->next=new_node;
		i++;
	}
	return start;
	
}

void insert_at_beg(){
	node *new_node;
	new_node=(node*)malloc(sizeof(node));
	printf("\nEnter data:");
	scanf("%d",&new_node->data);
	new_node->next=start;
	start=new_node;
	
}
node* traverse(){
	node *trav=start;
	while(trav->next!=NULL)	
		trav=trav->next;
	return trav;
}
void insert_at_end(){
	node *new_node,*trav;
	new_node=(node*)malloc(sizeof(node));
	printf("\nEnter data:");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	trav=traverse();
	trav->next=new_node;
	
}

void insert_at_any(){
	node *trav=start;
	int i=1,pos;
	printf("\nEnter which position you want to insert a node:");
	scanf("%d",&pos);
	while(i!=(pos-1)){
		trav=trav->next;
		i++;
	}
	node *new_node;
	new_node=(node*)malloc(sizeof(node));
	printf("\nEnter data:");
	scanf("%d",&new_node->data);
	new_node->next=trav->next;
	trav->next=new_node;
	
}

void delete_from_beg(){
	node* temp=start;
	start=temp->next;
	free(temp);	
}

void delete_from_end(){
	node *trav=start,*temp;
	while(trav->next->next!=NULL)	
		trav=trav->next;
	temp=trav->next;
	trav->next=trav->next->next;
	free(temp);
}

void delete_at_any(){
	node *trav=start,*temp;
	int i=1,pos;
	printf("\nEnter which position you want to insert a node:");
	scanf("%d",&pos);
	while(i!=(pos-1)){
		trav=trav->next;
		i++;
	}
	temp=trav->next;
	trav->next=trav->next->next;
	free(temp);
	
}
void display(){
	node *trav=start;
	printf("\nLinked List Elements Are:\n");
	while(trav!=NULL){
		printf("%d\t",trav->data);
		trav=trav->next;
	}
}

//void search(){
//	node *trav=start;
//	int s,pos=1,flag=0;
//	printf("\nEnter Searching Element:");
//	scanf("%d",&s);
//	while(trav!=NULL){
//		if(trav->data==s)
//			flag=1;
//		else
//			flag=0;
//		trav=trav->next;
//		pos++;
//	}
//	if(flag==1)
//		printf("%d found at position %d",s,(pos-1));
//	else
//		printf("%d is not exist in Linked List",s);
//}
//void sort(){
//	node *trav=start;
//	int i,j;
//	for(i=0;i<5;i++)
//		for(j=i+1;j<5;j++)
//			if()
//	
//}
int main(){
	char ch,no;
	//sort();
	printf("!==============LINKED LIST==================!\n\n");
	start=create_ssl();
	while(1){
			printf("\n=======================================================\n");
			printf("\nPlease select which operation you want to perform on Linked List?\n"
			"Press a for insert\n"
			"press b for delete\n"
			"press c for traverse\n"
			"press e for exit\n");
	printf("\nEnter your choice:");
	scanf(" %c",&ch);
	switch(ch){
		case 'a':
			printf("\n=======================================================\n");
			printf("\nPlease select which type Insert operation you want to perform on Linked List?\n"
			"Press 1 for insert at beginning\n"
			"press 2 for insert at end\n"
			"press 3 for insert at any position\n"
			"press 4 for exit\n");
			printf("\nEnter your choice:");
			scanf("%d",&no);
			switch(no){
				case 1:
					insert_at_beg();
					break;
				case 2:
					insert_at_end();
					break;
				case 3:
					insert_at_any();
					break;
				case 4:
					printf("You are exit!!");
					exit(0);
					
				default:printf("Your choice is wrong!!Please choise above this option...");	
			}
			break;
		case 'b':
			printf("\n=======================================================\n");
			printf("\nPlease select which type Delete operation you want to perform on Linked List?\n"
			"Press 1 for delete from beginning\n"
			"press 2 for delete from end\n"
			"press 3 for delete at any position\n"
			"press 4 for exit\n");
			printf("\nEnter your choice:");
			scanf("%d",&no);
			switch(no){
				case 1:
					delete_from_beg();
					break;
				case 2:
					delete_from_end();
					break;
				case 3:
					delete_at_any();
					break;
				case 4:
					printf("You are exit!!");
					exit(0);
					
				default:printf("Your choice is wrong!!Please choise above this option...");	
			}
			break;
		case 'c':
			display();
			break;
		case 'e':
			printf("You are exit!!");
			exit(0);
			
		default:printf("Your choice is wrong!!Please choise above this option...");
		}
	}
	return 0;
}
