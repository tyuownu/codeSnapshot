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
    int *max_temp = new int[n];
    int *sum_temp = new int[n];
    max_temp[0] = a[0], sum_temp[0] = a[0];
    for(int i=1; i<n ; i++)
    {
        if(sum_temp[i-1] <= 0)
            sum_temp[i] = a[i];
        else
            sum_temp[i] = a[i] + sum_temp[i-1];

        max_temp[i] = max(max_temp[i-1], sum_temp[i]);
    }
    return max_temp[n-1];
}

int main()
{
    int a[]={1,-2,3,10,-4,7,2,-5};
    cout<<MaxSubArray(a, 8)<<endl;
    return 0;
}
