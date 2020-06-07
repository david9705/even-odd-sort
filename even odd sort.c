#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(void *a, void *b)  //»¼¼W
{
    return *(int *)a > *(int *)b;
}

int cmp_less(void *a, void *b) //»¼´î
{
    return *(int *)a < *(int *)b;
}




int main(void)
{
    int a[10] = {2, 13, 546, 1, 44, 7, 59, 23, 32, 21, 4};

    int *odd = malloc(sizeof(int) * 10);
    int *even = malloc(sizeof(int) * 10);
    int odd_index = 0, even_index = 0;


    int i = 0;
    for(i = 0 ; i < 10 ; i ++)
    {
        if(a[i] % 2 == 0)
        {
            even[even_index] = a[i];
            even_index++;
        }
        else
        {
            odd[odd_index] = a[i];
            odd_index++;
        }
    }

    qsort(odd, odd_index, sizeof(int), cmp) ;
    qsort(even, even_index, sizeof(int), cmp_less) ;


    for(i = 0 ; i < 10 ; i ++)
    {
        if(i < even_index)
            a[i] = even[i];
        else
            a[i] = odd[i - even_index];
    }

    for(i = 0 ; i < 10 ; i ++)
    {
        printf("%d \n", a[i]);
    }




}
