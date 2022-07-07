#include<stdio.h>
#include<stdlib.h>
int a[50],n;
void insertData();
void deleteData();
void replaceData();
void searchData();
void displayData();
int  main(){
	int i;
	char ch;
	printf("Enter the number of an array:");
	scanf("%d",&n);
	printf("Enter the element of this array:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(1){
		printf("\n=======================================================\n");
			printf("\nPlease select which operation you want to perform?\n"
			"Press a for insert\n"
			"press b for delete\n"
			"press c for replace\n"
			"press d for search\n"
			"press e for display\n"
			"press f for exit\n");
	printf("\nEnter your choice:");
	scanf(" %c",&ch);
	switch(ch){
		case 'a':insertData();break;
		case 'b':deleteData();break;
		case 'c':replaceData();break;
		case 'd':searchData();break;
		case 'e':displayData();break;
		case 'f':exit(0);
		default:printf("Your choice is wrong!!Please choise above this option...");
	}
		
	}

	return 0;
}
void insertData(){
	int pos,ele,i;
	printf("Enter position where you want to insert?");
	scanf("%d",&pos);
	printf("Enter data you want to insert:");
	scanf("%d",&ele);
	
	for(i=n-1;i>=pos-1;i--){
		a[i+1]=a[i];
	}
	a[pos-1]=ele;
	n++;
	
}
void deleteData(){
	int pos,ele,i;
	if(pos>n){
		printf("delete is not possible.");
	}
	else{
		printf("Enter position where you want to delete?");
		scanf("%d",&pos);
		
		
		for(i=pos-1;i<=n;i++){
			a[i]=a[i+1];
		}
		n--;
		
	}
	
}
void replaceData(){
	int pos,ele,i;
	if(pos>n){
		printf("replace is not possible.");
	}
	else{
		printf("Enter position where you want to replace?");
		scanf("%d",&pos);
		printf("Enter data you want to be replaced?");
		scanf("%d",&ele);
		a[pos-1]=ele;
		
	}
	
}
void searchData(){
	int ele,pos,flag,i;
	printf("Enter value to be searched?");
	scanf("%d",&ele);
	flag=0;
	for(i=0;i<n;i++){
		if(a[i]==ele){
			flag=1;
			pos=i+1;
			break;
		}
		
	}

	if(flag==1){
		printf("element will be found at postion %d",pos);
		
	}
	else{
			printf("element will be not found");
	}
	
}
void displayData(){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
