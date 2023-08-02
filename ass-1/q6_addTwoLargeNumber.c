#include<stdio.h>
int main(){
	int i,j,k=0,carry=0,digitNum=0,n1=0,n2=0,sum,digit;
	int num1[100],num2[100],ans[100];

	char snum1[100],snum2[100];
	printf("Enter Two large number : ");
	scanf("%s%s",snum1,snum2);
	
	for(i=0;snum1[i]!='\0';i++)
		n1++;
	for(i=0;snum2[i]!='\0';i++)
		n2++;
	for(i=0;i<n1;i++)
		num1[i]=(snum1[i]-'0');
	for(i=0;i<n2;i++)
		num2[i]=(snum2[i]-'0');
	i=n1-1,j=n2-1;

	//Summing two number and store it in new array
	
	while(i>=0&&j>=0){
		sum=num1[i]+num2[j]+carry;
		digit=sum%10;
		carry=sum/10;
		ans[k++]=digit;
		i--;
		j--;
	}
	while(i>=0){
		sum=carry+num1[i];
		digit=sum%10;
		carry=sum/10;
		ans[k++]=digit;
		i--;
	}
	while(j>=0){
		sum=carry+num2[j];
		digit=sum%10;
		carry=sum/10;
		ans[k++]=digit;
		j--;
	}
	if(carry!=0)
		ans[k++]=carry;
	digitNum=k;
	//Printing summation of two large value
	for(i=digitNum-1;i>=0;i--)
		printf("%d",ans[i]);
	printf("\n");
	return 0;
}

