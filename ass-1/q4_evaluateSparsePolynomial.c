#include<stdio.h>
#include<math.h>
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
    int i;
    float x;
    poly p;
    printf("Enter no of term in polynomials 1 and 2 : ");
    scanf("%d",&p.no_of_terms);
    printf("Enter coeff. and expo in sequential order for polynomials : ");
    for(i=0;i<p.no_of_terms;i++){
        scanf("%f",&p.a[i].coeff);
        scanf("%d",&p.a[i].expo);
    }
    printf("Enter value of x : ");
    scanf("%f",&x);
    for(i=p.no_of_terms-1;i>=0;i--){
        
    }
    // printf("%lf",ans);
    return 0;
}