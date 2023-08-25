#include <stdio.h>
#include <stdlib.h>
char *getletter(int a)
{
    char *dtl1 = malloc(sizeof(char) * a);
    char *dtl2 = malloc(sizeof(char) * a);
    switch (a)
    {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        for (int i = 0; i < 3; i++)
            dtl1[i] = (char)(97 + 3 * (a - 2) + i);
        break;
    case 7:
        for (int i = 0; i < 4; i++)
            dtl2[i] = (char)(112 + i);
        break;
    case 8:
        for (int i = 0; i < 3; i++)
            dtl1[i] = (char)(116 + i);
    case 9:
        for (int i = 0; i < 4; i++)
            dtl2[i] = (char)(119 + i);
        break;
    }
    if (a == 7 || a == 9)
        return (char *)dtl2;
    else
        return (char *)dtl1;
}
int main()
{
    int num;
    scanf("%d", &num);
    int one, two, three, four;
    char alphabet;
    if (num / 1000 > 0)
    {
        four = num / 1000;
        num %= 1000;
        three = num / 100;
        num %= 100;
        two = num / 10;
        one = num % 10;
        alphabet = 'F';
    }
    else if (num / 100 > 0)
    {
        three = num / 100;
        num %= 100;
        two = num / 10;
        one = num % 10;
        alphabet = 't';
    }
    else if (num / 10 > 0)
    {
        two = num / 10;
        one = num % 10;
        alphabet = 'T';
    }
    else if (num % 10 > 0)
    {
        one = num % 10;
        alphabet = 'O';
    }
    else
        alphabet = 'N';

    char *resp = getletter(one);
    char *resp1 = getletter(two);
    char *resp2 = getletter(three);
    char *resp3 = getletter(four);
    switch (alphabet)
    {
    case 'N':
        printf("[]");
        break;
    case 'O':
        // for (int i = 0; i < 3; i++)
        //    dtl[i] = (char)(97 + 3*(one-2) + i);
        printf("[");
        for (int i = 0; i < 3; i++)
            printf("\"%c\"", resp[i]);
        printf("]");
        break;
    case 'T':
        // for (int i = 0; i < 3; i++)
        //{
        //    dtl[i] = (char)(95 + one + i);
        //     dtl1[i] = (char)(95 + two + i);
        // }
        printf("[");
        for (int i = 0; i < 3; i++)
            for (int j = i; j < 3; j++)
                printf("\"%c%c\"", resp1[i], resp[j]);
        printf("]");
        break;
    case 't':
        // for (int i = 0; i < 3; i++)
        // {
        //     dtl[i] = (char)(95 + one + i);
        //     dtl1[i] = (char)(95 + two + i);
        //     dtl2[i] = (char)(95 + three + i);
        // }
        printf("[");
        for (int i = 0; i < 3; i++)
            for (int j = i; j < 3; j++)
                for (int k = j; k < 3; k++)
                    printf("\"%c%c%c\"", resp2[i], resp1[j], resp[k]);
        printf("]");
        break;
    case 'F':
        // for (int i = 0; i < 3; i++)
        // {
        //     dtl[i] = (char)(95 + one + i);
        //     dtl1[i] = (char)(95 + two + i);
        //     dtl2[i] = (char)(95 + three + i);
        //     dtl3[i] = (char)(95 + four + i);
        // }
        printf("[");
        for (int i = 0; i < 3; i++)
            for (int j = i; j < 3; j++)
                for (int k = j; k < 3; k++)
                    for (int l = k; l < 3; l++)
                        printf("\"%c%c%c%c\"", resp3[i], resp2[j], resp1[k], resp[l]);
        printf("]");
        break;
    }

    return 0;
}