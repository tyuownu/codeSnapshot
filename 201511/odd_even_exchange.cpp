/*************************************************************************
    > File Name: odd_even_exchange.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 08/11/2015 - 23:35:11
 ************************************************************************/

// problem: input a array of integer. Let odd in first half, and even in last half. Time complexity: O(n)
#include <iostream>
using namespace std;

void Exchange(int *a, const int begin, const int end)
{
    int left = begin, right = end;
    while(left<right)
    {
        while(a[right] % 2 == 0 && (left<right)) right--;
        while(a[left]%2 == 1 && (left<right)) left++;
        swap(a[left++], a[right--]);
    }

}

int main()
{
    int a[]={2,8,7,1,3,5,6,4};
    Exchange(a, 0, 7);
    for(int i=0; i<8; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;

}
