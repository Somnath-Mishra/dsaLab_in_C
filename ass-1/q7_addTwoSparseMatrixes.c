#include<stdio.h>

typedef struct element{
	int row,col,val;
}element;

typedef struct sparsemat{
	int numOfNonZeroEle,numOfRows,numOfCols;
	element a[100];
}sparsemat;

int main(){
	sparsemat m1,m2,m3;
	int i,j,k=0;
	printf("Enter number of rows and  columns :");
	scanf("%d%d",&m1.numOfRows,&m1.numOfCols);
	m2.numOfRows=m1.numOfRows;
	m2.numOfCols=m1.numOfCols;
	printf("Enter number of non-zero element in matrix1 and matrix2 ");
	scanf("%d%d",&m1.numOfNonZeroEle,&m2.numOfNonZeroEle);
	
	printf("Enter matrix 1 element in this format row col val :");
	for(i=0;i<m1.numOfNonZeroEle;i++)
		scanf("%d%d%d",&m1.a[i].row,&m1.a[i].col,&m1.a[i].val);
	
	printf("Enter matrix 2 element in this format row col val :");
	for(i=0;i<m2.numOfNonZeroEle;i++)
		scanf("%d%d%d",&m2.a[i].row,&m2.a[i].col,&m2.a[i].val);

	i=0,j=0;
	while(i<m1.numOfNonZeroEle&&j<m2.numOfNonZeroEle){
		if(m1.a[i].row==m2.a[j].row){
			if(m1.a[i].col==m2.a[j].col){
				m3.a[k].val=m1.a[i].val+m2.a[i].val;
				m3.a[k].col=m1.a[i].col;
				m3.a[k++].row=m1.a[i].row;
				i++;j++;
			}
			else if(m1.a[i].col<m2.a[j].col){
				m3.a[k].val=m1.a[i].val;
				m3.a[k].col=m1.a[i].col;
				m3.a[k++].row=m1.a[i].row;
				i++;
			}
			else{
				m3.a[k].val=m2.a[j].val;
				m3.a[k].row=m2.a[j].row;
				m3.a[k++].col=m2.a[j].col;
				j++;
			}
		}
		else if(m1.a[i].row<m2.a[j].row){
			m3.a[k].val=m1.a[i].val;
			m3.a[k].row=m1.a[k].row;
			m3.a[k++].col=m1.a[i].col;
			i++;
		}
		else{
			m3.a[k].val=m2.a[j].val;
			m3.a[k].row=m2.a[j].row;
			m3.a[k++].col=m2.a[j].col;
			j++;
		}
	}
	while(i<m1.numOfNonZeroEle){
		m3.a[k].col=m1.a[i].col;
		m3.a[k].row=m1.a[i].row;
		m3.a[k++].val=m1.a[i].val;
		i++;
	}
	while(j<m2.numOfNonZeroEle){
		m3.a[k].col=m2.a[j].col;
		m3.a[k].row=m2.a[j].row;
		m3.a[k++].val=m2.a[j].val;
		j++;
	}
	m3.numOfNonZeroEle=k;
	m3.numOfCols=m1.numOfCols;
	m3.numOfRows=m1.numOfRows;
	for(i=0;i<m3.numOfNonZeroEle;i++){
		printf("At position (%d,%d) value is %d \n",m3.a[i].row,m3.a[i].col,m3.a[i].val);
	}
	
	return 0;
}