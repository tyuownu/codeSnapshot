/*************************************************************************
    > File Name: max_subarray_sum.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 08/11/2015 - 23:16:27
 ************************************************************************/

#include <iostream>
using namespace std;

int MaxSubArray(int *a, int n)
{
    int *max_temp = new int[n+1];
    int *sum_temp = new int[n+1];
    max_temp[0] = 0, sum_temp[0] = 0;
    for(int i=0; i<n ; i++)
    {
        if(sum_temp[i] < 0)
            sum_temp[i+1] = a[i];
        else
            sum_temp[i+1] = a[i] + sum_temp[i];

        max_temp[i+1] = max(sum_temp[i+1], sum_temp[i]);
    }
    return max_temp[n];
}

int main()
{
    int a[]={1,-2,3,10,-4,7,2,-5};
    cout<<MaxSubArray(a, 8)<<endl;
    return 0;
}
