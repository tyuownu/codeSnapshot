/*************************************************************************
    > File Name: rotate_string.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 01/11/2015 - 15:25:39
 ************************************************************************/
/*
 * discrible: Input a string, move some chars from head to tail.
 * e.g. origin string: "abcdef", and k=2, output: "cdefab".
 * time complexity: O(n), space complexity: O(1)
 *
*/
#include<iostream>
using namespace std;

// origin method(what we thought at first time.)
void LeftShiftOne(char* s, const int n)
{
    char temp = s[0];
    for(int i = 0; i < n-1; i++)
        s[i] = s[i+1];
    s[n-1] = temp;
}

void LeftRotateString(char *s, const int n, int k)
{
    while(k--)
    {
        LeftShiftOne(s, n);
    }
}

/*
 * analyses: time complexity: O(k*n) 
 *           space complexity: O(1)
 */

// improve algorithm
void ReverseString(char* s, int begin, int end)
{
    while(begin<end)
    {
        char temp = s[begin];
        s[begin] = s[end];
        s[end] = temp;
        begin++;
        end--;
    }
}

void RotateString(char *s, const int n, int k)
{
    k %= n;
    ReverseString(s, 0, k-1);
    ReverseString(s, k, n-1);
    ReverseString(s, 0, n-1);
}

// analyses: time complexity: O(n), space complexity: O(1)
// string=XY.  ->(X^TY^T)^T=YX.

int main()
{
    char p[]="abcdef";
    LeftRotateString(p, 6, 2);
    cout<<p<<endl;

    char q[]="abcdef";
    RotateString(q, 6, 2);
    cout<<q<<endl;
    return 0;
}

// Think the following question. 
// Input: "I am a student."
// Output: "student. a am I"
// see rotate_line.cpp.   string = A B C D, (A^T B^T C^T D^T)^T = D C B A. 
// notice the '\0'
