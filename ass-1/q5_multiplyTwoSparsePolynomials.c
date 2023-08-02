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

int  main (){
     int i,j,k=0,l=0,a,b;
    poly p1,p2,p3,p4;
   
    printf("Enter no of term in polynomials 1 and 2 : ");
    scanf("%d%d",&p1.no_of_terms,&p2.no_of_terms);
    printf("Enter coeff. and expo in sequential order for polynomials 1 : ");
    for(i=0;i<p1.no_of_terms;i++){
        scanf("%f",&p1.a[i].coeff);
        scanf("%d",&p1.a[i].expo);
    }
    
    printf("Enter coeff. and expo in sequential order for polynomials 2 : ");
    for(i=0;i<p2.no_of_terms;i++){
        scanf("%f",&p2.a[i].coeff);
        scanf("%d",&p2.a[i].expo);
    }

    //Doing product of two polynomials 

    for(i=0;i<p1.no_of_terms;i++){
        for(j=0;j<p2.no_of_terms;j++,k++){
            p3.a[k].coeff=p1.a[i].coeff*p2.a[j].coeff;
            p3.a[k].expo=p1.a[i].expo+p2.a[j].expo;
        }
    }
    p3.no_of_terms=k;

    //sorting according to exponential of p3 polynomial

    for (i = 0; i < p3.no_of_terms; ++i){
        for (j = i + 1; j < p3.no_of_terms; ++j){
            if (p3.a[i].expo > p3.a[j].expo){
            a = p3.a[i].expo;
            b=p3.a[i].coeff;
            p3.a[i].expo =p3.a[j].expo;
            p3.a[i].coeff=p3.a[j].coeff;
            p3.a[j].expo = a;
            p3.a[j].coeff=b;
        }
    }
    }
    i=0;
    //Summing up which exponent have same
    while(i<p3.no_of_terms){
        int exp=p3.a[i].expo;
        float coef=0;
        while(i<p3.no_of_terms&&exp==p3.a[i].expo){
            coef+=p3.a[i].coeff;
            i++;
        }
        p4.a[l].coeff=coef;
        p4.a[l].expo=exp;
        l++;
    }
    p4.no_of_terms=l;
    //Print ans polynomial
    printf("Coeffcient   Exponenet \n");
    for(i=0;i<p4.no_of_terms;i++){
        printf("%f    %d",p4.a[i].coeff,p4.a[i].expo);
        printf("\n");
    }
    return 0;
}