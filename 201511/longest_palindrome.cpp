/*************************************************************************
    > File Name: longgest_palindrome.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 04/11/2015 - 21:13:28
 ************************************************************************/

#include <iostream>
#include <memory.h>
using namespace std;

// function isPalindrome is to define wheather a string
// is a palindrome or not.
bool isPalindrome(const char *str, int n)
{
    int start=0, end=n-1;
    while(start < end)
    {
        if(*(str+start) == *(str+end))
        {
            start++; end--;
        }
        else
            return false;
    }
    return true;
}

// Algorithm 1: For every char, to get it longest palindrome str.
// time complexity: best-> O(n), normal-> O(n^3)
int LongestPalindrome1(const char *str, int n)
{
    int longest=0;
    int width;
    for(int i=0; i<n; i++)
    {
        width = 0;
        int temp_longest=0;   //odd
        while( (i-width)>=0 && (i+width)<n &&(*(str+i-width) == *(str+i+width)) )  
            temp_longest++;

        if(2*temp_longest+1 > longest)
            longest = 2*temp_longest+1;

        temp_longest = 0;  //even
        width = 0;
        while( (i-width)>=0 && (i+width+1)<n && (str[i-width] == str[i+width+1]) )
            temp_longest++;
        if(2*temp_longest > longest)
            longest = 2 * temp_longest;
    }

    return longest;
}

// Algorithm 2: improve method. Called Manacher algorithm
// time complexity: O(n)
// Ingenious: 1. Add other char so every char is be able to odd. 
//              e.g. str="abba", output="^#a#b#b#a#$"
//            2. formula: 
int LongestPalindrome2(const char *str, int n)
{
    if(!*str || 0 == n)
        return 0;
    int longest=0;
    
    // pre_process str.
    char *temp = new char[2*n+3];
    temp[0] = '^';
    for( int i=0; i<n; i++ )
    {
        temp[2*i + 1] = '#';
        temp[2*i + 2] = str[i];
    }
    temp[2*n+1] = '#';
    temp[2*n+2] = '$';
    // end pre_process.

    int *p = new int[2*n+3];
    memset(p, 0, sizeof(p));
    int id = 0, mx = 0;
    for( int i=1; i<2*n+3; i++ )
    {
        int j = 2*id -i;
        if(mx > i)
            p[i] = (mx-i)<p[j] ? (mx-i):p[j];
        else
            p[i] = 0;

        while( i+1+p[i] < 2*n+3 && i-1-p[i] >=0 &&
                (temp[i+1+p[i]] == temp[i-1-p[i]]))
            p[i] += 1;

        if( i + p[i] > mx )
        {
            id = i;
            mx = i+p[i];
        }
        
    }

    for(int i=0; i<2*n+3; i++)
        if(p[i] > longest)
            longest = p[i];

    return longest;

}

int main()
{
    char str[] = "dsafabssbafewqdsageqv";
    cout<<LongestPalindrome2(str, strlen(str))<<endl;
    return 0;
}
