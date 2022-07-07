#include<stdio.h>
int flavour(int input1,int input2){
	int mixed_flavour;
	mixed_flavour=input1+input2;
	return mixed_flavour;
}

int  main(){
	int T=0,N,F1,F2,i;
	printf("How many no of flavour has manika?"
	);
	scanf("%d",&N);
	T=N;
	printf("Enter one flavour:");
	scanf("%d",&F1);
	printf("Enter second flavour:");
	scanf("%d",&F2);
	printf("The new Flavour is:%d",flavour(F1,F2));
	if(flavour(F1,F2)>0){
		T++;
	}
	printf("Now total no of flavour is:%d",T);
	return 0;
}
