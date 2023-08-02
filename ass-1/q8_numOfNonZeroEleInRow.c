#include<stdio.h>

typedef struct element{
	int row,col,val;
}element;

typedef struct sparsemat{
	int numOfNonZeroEle,numOfRows,numOfCols;
	element a[100];
}sparsemat;

int main(){
	sparsemat m;
	int i,j,k=1,count=0,currRow;
	printf("Enter number of rows and  columns :");
	scanf("%d%d",&m.numOfRows,&m.numOfCols);
	
	printf("Enter number of non-zero element in matrix");
	scanf("%d",&m.numOfNonZeroEle);
	
	printf("Enter matrix's  element in this format row col val :");
	for(i=0;i<m.numOfNonZeroEle;i++)
		scanf("%d%d%d",&m.a[i].row,&m.a[i].col,&m.a[i].val);
    i=0;
    while(i<m.numOfNonZeroEle){
        count=0;
        currRow=m.a[i].row;
        while(i<m.numOfNonZeroEle && currRow==m.a[i].row){
            count++;
            i++;
        }
        printf("Number of non-zero element in %d row is %d \n",k++,count);
    }


    return 0;   
}     
	