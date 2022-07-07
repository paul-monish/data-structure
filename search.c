#include<stdio.h>
#include<stdlib.h>
void binarySearch(int a[],int n,int x){
	int f,l,m;
	f=0;
	l=n-1;
	m=(f+l)/2;
	while(f<=l){
		if(a[m]<x){
			f=m+1;
			
		}
		else if(a[m]==x){
			printf("using Binary Search %d Element is found at position %d",x,(m+1));
			break;
		}
		else{
			l=m-1;
		}
		m=(f+l)/2;
	}
	if(f>l){
		printf("%d is not presenet in the array!!",x);
	}
}
int interpolationSearch(int a[],int lo,int hi,int x){
	int pos;
	
	if(lo<=hi && x>=a[lo] && x<=a[hi]){
		//m=(a[hi]-a[lo]);
		if(a[hi]!=a[lo]){
			pos=lo+(x-a[lo])*(hi-lo)/(a[hi]-a[lo]);
			if(a[pos]==x){
				return pos;
			}
			else if(a[pos]>x){
				hi=pos-1;
				interpolationSearch(a,lo,hi,x);
			}
			else{
				lo=pos+1;
				interpolationSearch(a,lo,hi,x);
			}
		}
		else
			return 0;
	
	}
	return -1;	
}
int main(){
	int a[10],i,n,x,pos;
	char ch;
		while(1){
		printf("\n=======================================================\n");
			printf("\nPlease select which operation you want to perform?\n"
			"Press a for binary search\n"
			"press b for interpolation search\n"
			"press e for exit\n");
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
				printf("Enter the element to be searched?");
				scanf("%d",&x);
				binarySearch(a,n,x);
				break;
		case 'b':
				printf("Enter the number of an array:");
				scanf("%d",&n);
				printf("Enter the element of this array:\n");
				for(i=0;i<n;i++){
					scanf("%d",&a[i]);
				}
				printf("Enter the element to be searched?");
				scanf("%d",&x);
				pos=interpolationSearch(a,0,(n-1),x);
				if(pos!=-1)
					printf("using Interpolation Search %d Element is found at position %d",x,(pos+1));
				else
					printf("%d is not presenet in the array!!",x);
				break;
		case 'e':exit(0);
		default:printf("Your choice is wrong!!Please choise above this option...");
	}
}
	return 0;
}
