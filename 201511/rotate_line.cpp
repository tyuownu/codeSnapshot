/*************************************************************************
    > File Name: rotate_line.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 01/11/2015 - 16:34:39
 ************************************************************************/

#include <iostream>
using namespace std;

void ReverseString(char *s, int begin, int end)
{
    while(begin<end)
    {
        char temp = s[begin];
        s[begin++] = s[end];
        s[end--] = temp;
    }
}

void RatoteLine(char *s, const int n)
{
    int i=0;
    while(i<n)
    {
        int k=0;
        while(*(s+i+k) != ' ' && (i+k) < n)
            k++;
        ReverseString(s, i, i+k-1);
        i = i+k+1;
    }
    ReverseString(s, 0, n-1);
}

int main()
{
    char line[]="I am a student.";
    cout<<line<<endl;
    RatoteLine(line, 15);
    cout<<line<<endl;
    return 0;
}
