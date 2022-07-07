#include<stdio.h>
#include<stdlib.h>

#pragma(push,1)
typedef struct sll{
	int data;
	struct sll* next;
}node;
#pragma pop

node* start=NULL;//dangling pointer,to remove danglingness assign NULL

node* createNode(int n){
	node *newnode;
	int no_of_nodes,data_element;
	
	printf("Enter how many node you want to create in sll?");
	scanf("%d",&no_of_nodes);
	
	newnode=(node*)malloc(sizeof(node));
	
	printf("Enter data:");
	scanf("%d",&data_element);
	
	newnode->data=data_element;
	temp->next=NULL;
	
	start=newnode;
	
	for(i=2;i<n;i++){
		newnode=(node*)malloc(sizeof(node));
		
		printf("Enter data:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
	
		
		if(i==2){
			start->next=newnode;
		}
		else{
			while(t1->next != NULL)	{
				t1=t1->next;
			}
			t1->next=temp;
		}
		
	}
	

}
int main(){
	int n;
	
	start=create_sll(n);
	return 0;
}
