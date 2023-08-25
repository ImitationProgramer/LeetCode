#include <stdio.h>
#include <stdlib.h>

void fast(int a[], int b[], int n, int *amount, int *f)
{
    if (a[n] < b[n])
    {
        *amount += a[n];
        *f = 0;
    }
    else
    {
        *amount += b[n];
        *f = 1;
    }
}
void normal(int a[], int b[], int n, int c, int *amount, int *f)
{
    if (a[n] + c < c + b[n])
    {
        *amount += a[n] + c;
        *f = 0;
    }
    else
    {
        *amount += b[n] + c;
        *f = 1;
    }
}
void firstnormal(int a[], int b[], int n, int c, int *amount, int *f)
{
    if (a[n] < c + b[n])
    {
        *amount += a[n];
        *f = 0;
    }
    else
    {
        *amount += b[n] + c;
        *f = 1;
    }
    //(a[n]<c+b[n]) ? *amount+=a[n],*f=0 : *amount+=b[n]+c,*f=1;
    // *amount += (a > c +  b ?  c + b : a)
}
void minimumCosts(int *regular, int regularSize, int *express, int expressSize, int expressCost)
{
    int sum = 0, flag = 0;
    int *sumone = (int *)malloc(sizeof(int) * regularSize + 1);
    firstnormal(regular, express, 0, expressCost, &sum, &flag);
    sumone[0] = sum;
    printf("sum0: %d\n", sum);
    printf("flag0 : %d\n", flag);
    for (int i = 1; i < regularSize; i++)
    {
        if (i == regularSize - 1)
        {
            if (flag == 0)
                firstnormal(regular, express, i, expressCost, &sum, &flag);
            else
                fast(regular, express, i, &sum, &flag);
        }
        else
        {
            if (flag == 0)
                normal(regular, express, i, expressCost, &sum, &flag);
            else if (flag == 1)
                fast(regular, express, i, &sum, &flag);
        }
        sumone[i] = sum;
        printf("flag%d: %d\n", i, flag);
        printf("sum%d :%d\n", i, sum);
    }
    for (int i = 0; i < regularSize; i++)
        printf("%d ", sumone[i]);
}
int main()
{
    int A, B, expresscost;
    scanf("%d %d", &A, &B);
    int *regular = (int *)malloc(sizeof(int) * A);
    int *express = (int *)malloc(sizeof(int) * B);
    for (int i = 0; i < A; i++)
        scanf("%d", &regular[i]);
    for (int i = 0; i < B; i++)
        scanf("%d", &express[i]);
    scanf("%d", &expresscost);
    minimumCosts(regular, A, express, B, expresscost);
    return 0;
}