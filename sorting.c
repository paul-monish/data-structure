#include<stdio.h>
#include<stdlib.h>
void display(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
void bubbleSort(int a[],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;i++){
			if(a[j]<a[j+1]){
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j+1]=a[j]-a[j+1];
			}
		}
	}
	printf("After Bubble Sorting:\n");
	display(a,n);
	
}
int main(){
	int i,a[10],n;
	char ch;
	printf("Enter the number of an array:");
	scanf("%d",&n);
	printf("Enter the element of this array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(1){
		printf("\n=======================================================\n");
			printf("\nPlease select which operation you want to perform?\n"
			"Press a for bubble sort\n"
			"press b for selection sort\n"
			"press f for exit\n");
	printf("\nEnter your choice:");
	scanf(" %c",&ch);
	switch(ch){
		case 'a':bubbleSort(a,n);break;
		//case 'b':selectionSort(a,n);break;
		case 'f':exit(0);
		default:printf("Your choice is wrong!!Please choise above this option...");
	}
		
	}

	return 0;
}
