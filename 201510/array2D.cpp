/*************************************************************************
    > File Name: array2D.c
    > Author: 
    > Mail: 
    > Created Time: 2015年10月27日 星期二 09时37分25秒
 ************************************************************************/

#include <iostream>
#include<stdio.h>

int main()
{
    const int MAXCOL = 3;
    int nRow;
    scanf("%d", &nRow);

    //important
    int *pp_arr = new int[nRow * MAXCOL];
    int (*p)[MAXCOL] = (int(*)[MAXCOL])pp_arr;

    int i,j;
    for(i = 0; i < nRow; i++)
        for(j = 0; j < MAXCOL; j++)
            p[i][j] = i + j;

    for(i = 0; i < nRow; i++)
    {
        for(j = 0; j < MAXCOL; j++)
            printf("%5d", p[i][j]);
        putchar('\n');
    }

    delete[] pp_arr;
    return 0;
}
