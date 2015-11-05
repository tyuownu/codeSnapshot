/*************************************************************************
    > File Name: all_permutation.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 05/11/2015 - 22:28:07
 ************************************************************************/

#include <iostream>
using namespace std;

// Algorithm 1: Recursive.
// Everyone should know recursive, but aviod to use it.
bool isSwap(char *str, int begin, int end)
{
    for(int i=begin; i<end; i++)
        if(str[i] == str[end])
            return false;
    return true;
}
void CalcAllPermutationRecursive(char *perm, int from, int to)
{
    if(to<=1)
    {return;}

    if(from == to)
    {
        for(int i=0; i <= to; i++)
            cout<<perm[i];
        cout<<endl;
    }
    else
    {
        for(int j=from; j<=to; j++)
        {
            if(isSwap(perm, from, j))
            {
                swap(perm[j], perm[from]);
                CalcAllPermutationRecursive(perm, from+1, to);
                swap(perm[j], perm[from]);
            }
        }
    }
}

// Algorithm 2: find every string's next string, for example: string="abcd", next_string="abdc".
// It is works, but redundancy. Find more effect way.
void sort(char *str,int  start, int end)  // quicksort
{
    if(start < end)
    {
        int left = start, right = end;
        char temp = str[left];
        while(left < right)
        {
            while(str[right] >= temp && (left < right)) right--;
            if(left < right) str[left++] = str[right];

            while(str[left] <= temp && (left < right)) left++;
            if(left < right) str[right--] = str[left];

        }
        str[left] = temp;
        sort(str, start, left-1);
        sort(str, left+1, end);
    }
}

bool ReverseOrder(char *str, int n)   // to define if a str is a reverse order.
{
    for(int i=1; i<=n ;i++)
        if(str[i]>str[i-1])
            return false;
    return true;
}

void PrintStr(const char *str)    // print string
{
    while(*str)
        cout<<*str++;
    cout<<endl;
}

// this function is to find the last disorder num. 
// e.g., str="defgba", so next = "degabf", "ba" and "gb" is reverse
// order, and "fg" is not.
// so, we first find the location of 'f' and than, order the last 'abf'.
void FindLastDisOrder(char *perm, int from, int to) 
{
    // this is find the location of 'f', if index = -1, it's that there are disorder.
    // index is the location of 'f'
    int index=-1;
    for(int j=to-1; j>=0; j--)
    {
        if(perm[j] < perm[j+1])
        {
            index = j;
            break;
        }
    }

    if(index >= 0)
    {
        int j=index+1;

        // find the 'g', it's define as behind 'f' the most smallest number larger than 'f'
        // in this example is 'g'
        // find the the location of 'g', for swap
        for(int i=index+1;  i <= to; i++)
        {
            if(i+1<= to)
            {
                if(perm[i] > perm[index] && perm[i+1] <= perm[index])
                {
                    j = i;
                    break;
                }
            }
            else
            {
                j = to;
            }

        }

        // swap('f', 'g')
        swap(perm[index], perm[j]);
        // sort the char before 'g'
        sort(perm, index+1, to);
    }
}
void CalcAllPermutationNext(char *perm, int from, int to)
{
    sort(perm, 0, to);
    while(true)
    {
        PrintStr(perm);
        if(ReverseOrder(perm, to)) break;
        FindLastDisOrder(perm, from, to);
    }
}

// TODO: find more effect way to solve the problem, or just rewrite the code so it more concise.
int main()
{
    char str[] = "dfaklft";
//    CalcAllPermutationRecursive(str, 0, 6);
    CalcAllPermutationNext(str, 0, 6);
    return 0;
}

