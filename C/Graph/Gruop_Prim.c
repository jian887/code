#include<stdio.h>

#define MAXSIZE 100


int main()
{
    int point[MAXSIZE];
    int side[MAXSIZE][MAXSIZE];
    int n,count = 1;
    int i,j;
    printf("Please input the number of points: \n");
    scanf("%d",&n);
    printf("Please input point: \n");
    for(i=0 ;i<n ;i++){
        printf("point %d:",i+1);
        scanf("%d",&point[i]);
    }
     printf("Please input the side in adjacent matrix \n");
    for(i=0 ;i<n ;i++){
        printf("No.%d side: \n",i+1);
        for(j=0 ; j<n ;j++){
            scanf("%d",&side[i][j]);
        }
    }
    printf("All points in list:");
        for(i=0 ;i<n ;i++){
        printf("%d \t",point[i]);
    }
    printf("\nAll Side in adjacent matrix \n");
    for(i=0 ;i<n ;i++){
        printf("No.%d side\t",i+1);
        for(j=0 ; j<n ;j++){
            printf("%d\t",side[i][j]);
        }
        printf("\n");
    }
    return 0;
}

