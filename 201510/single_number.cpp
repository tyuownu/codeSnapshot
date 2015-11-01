/*************************************************************************
    > File Name: single_number.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 31/10/2015 - 16:03:48
 ************************************************************************/

#include<iostream>
using namespace std;

int SingleNumber(int A[], int n)
{
    int ones=0, twos=0;
    for(int i=0; i<n; i++)
    {
        ones=(ones^A[i])&~twos;
        twos=(twos^A[i])&~ones;
        cout<<ones<<" "<<twos<<endl;
    }
    return ones;
}

int main()
{
    int a[]={1,2,3,4,3,1,2,3,5,1,5,2,5};
    cout<<SingleNumber(a, 13)<<endl;
    return 0;
}
