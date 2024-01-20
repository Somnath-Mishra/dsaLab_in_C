#include<stdio.h>
int main(){
    int arr[10];
    int i;
    printf("Enter array element which sized is 10 : ");
    for(i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    arr[2]=arr[3];
    arr[3]=arr[4];
    for(i=4;i<7;i++){
        arr[i]=arr[i+1];
    }
    printf("%d ",arr[4]);
    return 0;
    
}
