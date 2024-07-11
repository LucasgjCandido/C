#include<stdio.h>
#include<stdlib.h>


main(){

int a[3][3]={{5,-8,7},
            {6,-4,-7},
            {8,10,12}};

int b[3][3]={{-21,14,76},
            {-8,-12,-15},
            {21,-21,0}};

int i,j,c[3][3],d[3][3],e[3][3];

printf("\nMatriz A=\n\n");
for(i=0;i<=2;i++){
    for(j=0;j<=2;j++){
            printf("%4d", a[i][j]);
    }
    printf("\n");
    }
printf("\nMatriz B=\n\n");
for(i=0;i<=2;i++){
    for(j=0;j<=2;j++){
            printf("%4d", b[i][j]);
    }
    printf("\n");
    }
printf("\nMatriz A + B=\n\n");
    for(i=0;i<=2;i++){
    for(j=0;j<=2;j++){
            c[i][j]=a[i][j]+b[i][j];
            printf("%4d", c[i][j]);
    }
    printf("\n");
    }
    printf("\nMatriz A - B=\n\n");
    for(i=0;i<=2;i++){
    for(j=0;j<=2;j++){
            d[i][j]=a[i][j]-b[i][j];
            printf("%4d", d[i][j]);
    }
    printf("\n");
    }
    printf("\nMatriz E=\n\n");
    for(i=0;i<=2;i++){
    for(j=0;j<=2;j++){
            e[i][j]=c[i][j]+d[i][j];
    if (e[i][j]>0){
        e[i][j]=0;}

    else if (e[i][j]<=0){
        e[i][j]=1;
    }
    }

            printf("%4d", e[i][j]);
    }
printf("\n");
}
