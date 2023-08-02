#include <stdio.h>
int main(){
	int n,i,j,row,column;
	printf("Enter value of n :");
	scanf("%d",&n);
    int arr[n];
	printf("Enter row and column value : ");
	scanf("%d%d",&row,&column);
	printf("Enter all element of array :");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	//Printing 1D array using 2D array index
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("%d ",arr[i*column+j]);//1D array index=(i*column)+j
		}
	}
	printf("\n");
	return 0;
}