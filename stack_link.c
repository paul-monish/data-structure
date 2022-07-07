#include<stdio.h>
#include<stdlib.h>

typedef struct sll{
	int data;
	struct sll *next;
}node;


node *start=NULL;
node *temp;
void createNode(){
	node *trav=start;
	temp=(node*)malloc(sizeof(node));
	
	printf("Enter data:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(start==NULL){
		
		start=temp;
	}
	else{
		while(trav->next!=NULL){
			trav=trav->next;
		}
		trav->next=temp;
	}
	
}

void displayNode(){
	
	node *trav=start;
	while(trav->next==NULL){
			printf("%d",trav->data);
			trav=trav->next;
		}
		
	
}
int main(){
	int n,i;
	printf("How many node you want to create?");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		createNode();
	}
	printf("data are:");
	displayNode();
return 0;	
}

