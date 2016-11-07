//sorting algorithms

#include<stdio.h>

void bubblesort(int arr[100],int n){
	int j,i,temp;
	for(i=n-1;i>=0;i--){
		for(j=1;j<=i;j++){
			if(arr[j-1]>arr[j]){
				 temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}



void selectionsort(int arr[100],int n){
	int i,j,temp,min;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
				temp=arr[i];
				arr[i]=arr[min];
				arr[min]=temp;
			}
		}
	
	}
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}


void insertionsort(int arr[100],int n){
	int i,j,index;
	for(i=1;i<n;i++){
		index=arr[i];
		j=i;
		while(j>0 && arr[j-1]>index){
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=index;
	}
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}






int main(){
	int n,i,arr[100];
	printf("\nEnter the number of elements :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int op;
	do{
	
	printf("\n 1 for bubble sort");
	printf("\n 2 for selection sort");
	printf("\n 3 for insertion sort");
	scanf("%d",&op);
	switch(op){
	
	case 1:bubblesort(arr,n);break;
	case 2:selectionsort(arr,n);break;
	case 3:insertionsort(arr,n);break;
}}while(op<=3);
}
