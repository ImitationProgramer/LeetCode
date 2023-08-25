#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[10000];
    int i = 0;
    do
    {
        scanf("%s", str[i]);
        i++;
    } while (strcmp(str, '\0') != 0);
}
