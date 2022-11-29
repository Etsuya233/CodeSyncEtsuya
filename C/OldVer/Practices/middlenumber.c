#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Median( ElementType A[], int N ){
    for(int c=0;c<N;c++){   //turn the numbers smaller than 0 to plus
        if(A[c]<0) A[c]=-A[c];
    }

    ElementType min,temp; //min -> the smallest number  temp to save a number
    int cnt=0,location=0;
    for(;cnt<N-1;cnt++){
        min = A[cnt];
        for(int b = cnt+1;b<N;b++){
            if(A[b]<min){
                min=A[b];
                location=b;
            }
        }
        temp=A[cnt];
        A[cnt]=min;
        A[location]=temp;
    }

    ElementType ret = A[N/2];

    return ret;
}