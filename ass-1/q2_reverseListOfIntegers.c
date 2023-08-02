#include<stdio.h>
void reverse(int a[],int n){
    int i,temp;
    for(i=0;i<n/2;i++){
        temp=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=temp;
    }
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter value of number of element : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter all array elements : ");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    reverse(arr,n);
    return 0;
}