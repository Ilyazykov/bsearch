#include <stdio.h>

#define SIZE 10

int bsearch_naiv(int *sortedArray, int size, int x, int *res)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (sortedArray[i] > x)
        {
            *res = i;
            return 1;
        }
    }

    return 0;
}

int bsearch(int *sortedArray, int size, int x, int *res)
{
    int start = 0;
    int end = size;
    int temp;

    if (sortedArray[end-1] <= x)
    {
        return 0;
    }
    if (sortedArray[start] > x)
    {
        *res = 0;
        return 1;
    }

    while (end > start + 1)
    {
        temp = (end + start) / 2;
        if (sortedArray[temp] <= x)
        {
            start = temp;
        }
        else
        {
            end = temp;
        }
    }

    *res = end;

    return 1;
}

int main()
{
    int sortedArray[SIZE] = {3,3,3,3,4,4,4,4,4,4};
    int result, isFound;
    int x;

    // Answer is 4
    x = 3;
    isFound = bsearch(sortedArray, SIZE, x, &result);
    if (isFound)
    {
        printf("%d\n", result);
    }
    else
    {
        printf("doesn't found\n");
    }

    // Answer is "doesn't found"
    x = 10;
    isFound = bsearch(sortedArray, SIZE, x, &result);
    if (isFound)
    {
        printf("%d\n", result);
    }
    else
    {
        printf("doesn't found\n");
    }

    return 0;
}
