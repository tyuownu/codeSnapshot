/*************************************************************************
    > File Name: array_2D.c
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 27/10/2015 - 09:37:25
 ************************************************************************/

#include <iostream>
#include<stdio.h>

int main()
{
    const int kMaxcol = 3;
    int n_row;
    scanf("%d", &n_row);

    //important
    int *pp_arr = new int[n_row * kMaxcol];
    int (*p)[kMaxcol] = (int(*)[kMaxcol])pp_arr;

    int i,j;
    for(i = 0; i < n_row; i++)
        for(j = 0; j < kMaxcol; j++)
            p[i][j] = i + j;

    for(i = 0; i < n_row; i++)
    {
        for(j = 0; j < kMaxcol; j++)
            printf("%5d", p[i][j]);
        putchar('\n');
    }

    delete[] pp_arr;
    return 0;
}
