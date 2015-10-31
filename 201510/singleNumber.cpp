/*************************************************************************
    > File Name: singleNumber.cpp
    > Author: 
    > Mail: 
    > Created Time: 2015年10月31日 星期六 16时03分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

int singleNumber(int A[], int n)
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
    cout<<singleNumber(a, 13)<<endl;
    return 0;
}
