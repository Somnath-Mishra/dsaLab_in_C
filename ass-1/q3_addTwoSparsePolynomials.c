#include<stdio.h>
typedef struct term
{
    float coeff;
    int expo;
}term;

typedef struct poly
{
    term a[1000];
    int no_of_terms;
}poly;

int main(){
    int i,j,k,l;
    poly p1,p2,p3;
    int n1,n2;
    printf("Enter no of term in polynomials 1 and 2 : ");
    scanf("%d%d",&n1,&n2);
    p1.no_of_terms=n1;
    p2.no_of_terms=n2;
    printf("Enter coeff. and expo in sequential order for polynomials 1 : ");
    for(i=0;i<n1;i++){
        scanf("%f",&p1.a[i].coeff);
        scanf("%d",&p1.a[i].expo);
    }
    
    printf("Enter coeff. and expo in sequential order for polynomials 2 : ");
    for(i=0;i<n2;i++){
        scanf("%f",&p2.a[i].coeff);
        scanf("%d",&p2.a[i].expo);
    }
    for(i=0,j=0,k=0;(i<p1.no_of_terms)&&(j<p2.no_of_terms);k++){
        if(p1.a[i].expo==p2.a[j].expo){
            p3.a[k].coeff=p1.a[i].coeff+p2.a[j].coeff;
            p3.a[k].expo=p1.a[i].expo;
            i++;
            j++;
        }
        else if(p1.a[i].expo<p2.a[j].expo){
            p3.a[k].coeff=p1.a[i].coeff;
            p3.a[k].expo=p1.a[i].expo;
            i++;
        }
        else{
            p3.a[k].coeff=p2.a[j].coeff;
            p3.a[k].expo=p2.a[j].expo;
            j++;
        }
            

    }
    if(i<p1.no_of_terms && k<1000){
        for(l=i;l<p1.no_of_terms;l++,k++){
            p3.a[k].coeff=p1.a[l].coeff;
            p3.a[k].expo=p1.a[l].expo;
            }
    }
    else{
        for(l=j;l<p2.no_of_terms;l++,k++){
            p3.a[k].coeff=p2.a[l].coeff;
            p3.a[k].expo=p2.a[l].expo;
        }
    }
    p3.no_of_terms=k;
    printf("Coeffcient    Exponenet \n");
    for(i=0;i<p3.no_of_terms;i++){
        printf("%f    %d",p3.a[i].coeff,p3.a[i].expo);
        printf("\n");
    }
    return 0;
    }
    
