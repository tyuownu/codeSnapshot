/*************************************************************************
    > File Name: string_contains.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 02/11/2015 - 12:50:02
 ************************************************************************/

/*
 * Problem: string A and string B. And B.len < A.len. How to define wheather
 * that A contains the chars in B.
 * E.g. A: ABCD  B:BAD   return true;
 * A:ABCD B:BCE  return false.
 * in order to know the method. we suppose the all chars are upper char. [A-Z]
 */

#include <iostream>
using namespace std;

// Method 1. The most simple method.
// time complexity: O(m*n) n for string a's len. m for string b's len.
bool StringContain1(string &a, string &b)
{
    for(int i=0; i < b.length(); i++)
    {
        int j;
        for(j=0; (j < a.length()) && b[i]!=a[j]; j++) ;
        if(j >= a.length())
            return false;
    }
    return true;
}

// Method 2. First quicksort than cmp
// time complexity: O(m*log(m))+O(n*(log(n)))for sort. cmp: O(m+n)
void sort(string &a, int start, int end)
{
    if(start<end)
    {
        int left = start;
        int right = end;
        char temp = a[start];
        while(left < right)
        {
            while((a[right]>=temp) && (left < right)) right--;
            if(left<right) a[left++] = a[right];
            while((a[left] < temp) && (left < right)) left++;
            if(left<right) a[right--] = a[left];
        }
        a[left] = temp;
        sort(a, start, left-1);
        sort(a, left+1, end);
    }
}
bool StringContain2(string &a, string &b)
{
    sort(a, 0, a.length());
    sort(b, 0, b.length());
    for(int pa = 0, pb = 0; pb < b.length(); pb++)
    {
        while((pa < a.length()) && (a[pa] < b[pb]))
            pa++;
        if((pa >= a.length()) || (a[pa] > b[pb]))
            return false;
    }
    return true;
}


// Method 3. It is very hard to think this idea.
// time complexity: O(m+n). Best: O(n)
bool StringContain3(string &a, string &b)
{
    const int vec[26]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    int s = 1;
    for(int i=0; i<a.length(); i++)
    {
        int index = int(a[i]-'A');
        if(s%vec[index]) s *= vec[index];
    }

    for(int j=0; j<b.length(); j++)
    {
        int index = int(b[j]-'A');
        if(s%vec[index]) return false;
    }
    return true;
}

// Using bit manipulation. star: *****
// time complexity: O(n+m). space complexity: O(1)
bool StringContain4(string &a, string &b)
{
    int bit = 0;
    for(int i=0; i < a.length(); i++)
        bit = bit|(1<<(a[i]-'A'));

    for(int j=0; j < b.length(); j++)
    {
        if(!( bit & (1<<(b[j]-'A')) )) 
            return false;
    }
    return true;
}

int main()
{
    string A = "ABCDEDSDD";
    string B = "CDCB";
    cout<<StringContain1(A, B)<<endl
        <<StringContain2(A, B)<<endl
        <<StringContain3(A, B)<<endl
        <<StringContain4(A, B)<<endl;

    return 0;
}
