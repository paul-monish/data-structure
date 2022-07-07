#include<stdio.h>
#include<stdlib.h>

typedef struct BST{
	int data;
	struct BST *left;
	struct BST *right;
} BST;
BST* insert(int data){
	BST* new_root=(BST*)malloc(sizeof(BST));
	new_root->data=data;
	new_root->left=NULL;
	new_root->right=NULL;
	return new_root;
}
BST* create(BST* root,int data){
	if(root==NULL){
		root=insert(data);
	}
	else if(data<=root->data){
		root->left=create(root->left,data);
	}
	else{
		root->right=create(root->right,data);
	}
}

void inorder(BST* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void preorder(BST* root){
	if(root!=NULL){
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(BST* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}
int main(){
	int n,i,data,ch;
	BST* root=NULL;
	printf("How many no. you want to entered?\n");
	scanf("%d",&n);
	
	printf("\nEnter data:\n");
	
	for(i=1;i<=n;i++){
		scanf("%d",&data);
		root=create(root,data);
	}
//	while(1){
//		printf("\nFor displaying tree element choose any one option of them:\n");
//		printf("\n1. Inorder.\n2. Preorder.\n3. Postorder.\n4. Exit.\n");
//		scanf("%d",&ch);
//		switch(ch){
//			case 1: inorder(root);
//					break;
//			case 2: preorder(root);
//					break;
//			case 3: postorder(root);
//					break;
//			case 4: exit(0);
//			default: printf("\nPlease choose coorect option(Above Them!)..\n");
//		}
//		
//	}
	
	printf("\nPreorder:\n");
	preorder(root);
	printf("\nInorder:\n");
	inorder(root);
	printf("\nPostorder:\n");
	postorder(root);
	
	return 0;
}
