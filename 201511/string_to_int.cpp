/*************************************************************************
    > File Name: test.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 02/11/2015 - 20:20:57
 ************************************************************************/

#include <iostream>
#include <limits.h>
using namespace std;

const int int_max=INT_MAX;
const int int_min=INT_MIN;
int StrToInt(const char *str)
{
    int n=0;
    int sign=1;
    while(*str != 0)
    {
        if(' ' == *str)
        {
            str++;
            continue;
        }
        else if('-' == *str || '+' == *str)
        {
            if('-' == *str)
                sign = -1;
            str++;
            continue;
        }
        int c = *str - '0';
        if( ( n>int_max/10 ) || (int_max/10 == n && c > (int_max%10)) )
        {
            n=int_max;
            return n;
        }

        if( (n<int_min/10) || (int_min/10 == n && sign*c < int_min%10) )
        {
            n=int_min;
            return n;
        }
        n = n*10 + c*sign ;
        ++str;
    }
    return n;
}

int main()
{
    char str[]="-2147483647";
    cout<<StrToInt(str)<<endl;
    cout<<StrToInt("2147483648")<<endl;
    return 0;
}
