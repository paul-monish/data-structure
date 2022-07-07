#include<stdio.h>
#include<stdlib.h>
/*structure of polynomial*/
typedef struct node{
	float coeff;
	int expo;
	struct node* next;
}node;
/*function to create a node*/
node* insert(node* head,float co,int ex){
	node* temp;
	node* newP=malloc(sizeof(node));
	newP->coeff=co;
	newP->expo=ex;
	newP->next=NULL;
	
	if(head==NULL || ex > head->expo){
		newP->next=head;
		head=newP;
	}
	else{
		temp=head;
		while(temp->next !=NULL && temp->next->expo >= ex){
			temp=temp->next;
		}
		newP->next=temp->next;
		temp->next=newP;
	}
	return head;
}
/*function to input polynomial*/
node* create(node* head){
	int n,i;
	float coeff;
	int expo;
	
	printf("Enter the number of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the coefficient for term %d:",i+1);
		scanf("%f",&coeff);
		
		printf("Enter the exponent for term %d:",i+1);
		scanf("%d",&expo);
		
		head=insert(head,coeff,expo);
		
	}
	return head;
}
/*function to display polynomial*/
void print(node* head){
	if(head==NULL)
		printf("No Polynomial!!");
	else{
		node* temp=head;
		while(temp!=NULL){
			printf("(%.1fx^%d)",temp->coeff,temp->expo);
			temp=temp->next;
			if(temp!=NULL)
				printf(" + ");
			else
				printf("\n");
		}
	}
}

void polyAdd(node* head1,node* head2){
	node* ptr1=head1;
	node* ptr2=head2;
	node* head3=NULL;
	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->expo == ptr2->expo){
			head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->expo > ptr2->expo){
			head3=insert(head3,ptr1->coeff,ptr1->expo);
			ptr1=ptr1->next;
		}
		else if(ptr1->expo < ptr2->expo){
			head3=insert(head3,ptr2->coeff,ptr2->expo);
			ptr2=ptr2->next;
		}
	}
	while(ptr1!=NULL){
		head3=insert(head3,ptr1->coeff,ptr1->expo);
		ptr1=ptr1->next;
	}
	while(ptr2!=NULL){
		head3=insert(head3,ptr2->coeff,ptr2->expo);
		ptr2=ptr2->next;
	}
	printf("Added Polynomial is: ");
	print(head3);
}

int main(){
	node* head1=NULL;
	node* head2=NULL;
	printf("Enter the first polynomial:\n ");
	head1=create(head1);
	printf("Enter the second polynomial:\n ");
	head2=create(head2);
	
	polyAdd(head1,head2);
	return 0;
	
}
