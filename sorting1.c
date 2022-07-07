#include<stdio.h>
#include<stdlib.h>
void display(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
void bubbleSort(int a[],int n){
	int i,j,c=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				a[j]=a[j]^a[j+1];
				a[j+1]=a[j]^a[j+1];
				a[j]=a[j]^a[j+1];
				//c=1;
				//printf("s");
			}
//			if(c==0){
//				printf("No need swaping!!");
//				break;
//			}
				
		}
	}
	printf("After Bubble Sort:\n");
	display(a,n);
	
}

void selectionSort(int a[],int n){
	int pos,i,j;
	for(i=0;i<n-1;i++){
		pos=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[pos]){
				pos=j;
			}
			
		}
		if(pos!=i){
			a[i]=a[i]^a[pos];
			a[pos]=a[i]^a[pos];
			a[i]=a[i]^a[pos];
		}
	}
	printf("After Selection Sort:\n");
	display(a,n);
}

void insertionSort(int a[],int n){
	int i,j,k;
	for(i=1;i<n;i++){
		k=a[i];
		j=i-1;
		while(j>=0 && a[j]>k){
			a[j+1]=a[j];
			--j;
		}
		a[j+1]=k;
	}
	printf("After Insertion Sort:\n");
	display(a,n);
}

void merge(int a[],int first,int mid,int last){
	int b[50];
	int i,j,k;                             
		
		
	i=first;
	j=mid+1;
	k=first;
	while(i<=mid && j<=last){
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	if(i>mid){
		while(j<=last){
			b[k++]=a[j++];
		}
	}
	else{
		while(i<=mid){
			b[k++]=a[i++];
		}
	}
	for(i=first;i<=last;i++)
		a[i]=b[i];
}
void mergesort(int a[],int first,int last){
	int mid;
	if(first<last){
		mid=(first+last)/2;
		mergesort(a,first,mid);
	
		mergesort(a,mid+1,last);
		
		merge(a,first,mid,last);
			printf("f= %d m= %d l= %d \n",first,mid,last);
	}
	
} 
void quicksort(int a[],int first,int last){
	int i,j,pivot,temp;
	if(first<last){
		pivot=first;
		i=first;
		j=last;
		while(i<j){
			while(a[i]<=a[pivot] && i<last)
				i++;
			while(a[j]>a[pivot])
				j--;
			if(i<j){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		quicksort(a,0,j-1);
		quicksort(a,j+1,last);
		
	}
	
}
int main(){
	int i,a[10],n;
	char ch;
	while(1){
		printf("\n=======================================================\n");
			printf("\nPlease select which operation you want to perform?\n"
			"Press a for bubble sort\n"
			"press b for selection sort\n"
			"press c for insertion sort\n"
			"press d for merge sort\n"
			"press e for quick sort\n"
			"press f for exit\n");
	printf("\nEnter your choice:");
	scanf(" %c",&ch);
	switch(ch){
		case 'a':
				printf("Enter the number of an array:");
				scanf("%d",&n);
				printf("Enter the element of this array:\n");
				for(i=0;i<n;i++){
				scanf("%d",&a[i]);
				}
				bubbleSort(a,n);
				break;
		case 'b':
				printf("Enter the number of an array:");
				scanf("%d",&n);
				printf("Enter the element of this array:\n");
				for(i=0;i<n;i++){
				scanf("%d",&a[i]);
				}
				selectionSort(a,n);
				break;
		case 'c':
				printf("Enter the number of an array:");
				scanf("%d",&n);
				printf("Enter the element of this array:\n");
				for(i=0;i<n;i++){
				scanf("%d",&a[i]);
				}
				insertionSort(a,n);
				break;
		case 'd':
				printf("Enter the number of an array:");
				scanf("%d",&n);
				printf("Enter the element of this array:\n");
				for(i=0;i<n;i++){
				scanf("%d",&a[i]);
				}
				mergesort(a,0,n-1);
				printf("\nAfter merge Sort:");
				for(i=0;i<n;i++)
					printf("%d\t",a[i]);
				break;
		case 'e':
				printf("Enter the number of an array:");
				scanf("%d",&n);
				printf("Enter the element of this array:\n");
				for(i=0;i<n;i++){
				scanf("%d",&a[i]);
				}
				quicksort(a,0,n-1);
				printf("\nAfter quick Sort:");
				for(i=0;i<n;i++)
					printf("%d\t",a[i]);
				break;
		case 'f':exit(0);
		default:printf("Your choice is wrong!!Please choise above this option...");
	}
		
	}

	return 0;
}
