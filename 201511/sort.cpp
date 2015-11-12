/*************************************************************************
    > File Name: sort.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 09/11/2015 - 20:40:08
 ************************************************************************/

#include <iostream>
using namespace std;

// algorithm 1: Insert sort
// time complexity: O(n^2)
void InsertSort(int *a, const int begin, const int end)
{
    if(begin < end)
    {
        for(int i=1; i<end; i++)
        {
            int temp = a[i], j;
            for(j=i-1; j>=0 && j<end-1; j--)
            {
                if(temp<a[j])
                    a[j+1] = a[j];
                else
                {
                    break;
                }
            }
            a[j+1] = temp;
        }
    }
}

// algorithm 2: select sort
// time complexity: O(n^2)
void SelectSort(int *a, const int begin, const int end)
{
    if(begin < end)
    {
        for(int i=0; i<end; i++)
        {
            int temp = a[i], index=i;
            for(int j=i+1; j<end; j++)
                if(a[j] < temp)
                {
                    temp = a[j];
                    index = j;
                }
            swap(a[i], a[index]);
        }
    }
}

// algorithm 3: quick sort
// time complexity: O(n*log(n))
void QuickSort(int *a, const int begin, const int end)
{
    if(begin<end)
    {
        int left  = begin;
        int right = end-1;
        int temp = a[left];
        while( left<right )
        {
            while(a[right] >= temp && left < right) right--;
            if(left<right) a[left++] = a[right];

            while(a[left] < temp && left < right) left++;
            if(left<right) a[right--] = a[left];
        }
        a[left] = temp;
        QuickSort(a, begin, left-1);
        QuickSort(a, left+1, end);
    }
}

// algorithm 4: bubble sort
// time complexity: O(n^2)
void BubbleSort(int *a, const int begin, const int end)
{
    for(int i=0; i<end; i++)
    {
        for(int j=end-1; j>=i+1; j--)
            if(a[j]<a[j-1])
                swap(a[j], a[j-1]);
    }
}

// algorithm 5: shell sort
// time complexity: O(n*log(n))
void ShellSort(int *a, const int begin, const int end)
{
    
}

// algorithm 6: heap sort
// time complexity: O(n*log(n)), large-top heap.
void Rotate(int *a, const int k, const int n)
{
    if(k<=(n-1)/2)
    {
        if(a[2*k+1] > a[k]) 
        {
            if(a[2*k+1] < a[2*k+2] && 2*k+2 <= n) 
            {
                swap(a[k], a[2*k+2]);
                Rotate(a, 2*k+2, n);
            }
            else 
            {
                swap(a[k], a[2*k+1]);
                Rotate(a, 2*k+1, n);
            }
        }
        else if(a[2*k+2] > a[k] && 2*k+2 <= n)
        {
            swap(a[k], a[2*k+2]);
            Rotate(a, 2*k+2, n);
        }
        else return ;
    }
}
void BuildHeap(int *a, const int n)
{
    for(int i=(n-1)/2; i>=0; i--)
    {
        Rotate(a, i, n);
    }
}
void HeapSort(int *a, const int begin, const int end)
{
//    BuildHeap(a, end);
    int i;
    for(i=end-1; i>=1; i--)
    {
        BuildHeap(a, i);
        swap(a[0], a[i]);
    }
}

void MergeSort(int *a, const int begin, const int end)
{
    
}

void RadixSort(int *a, const int begin, const int end)
{
    
}
// TODO: shell sort, heap sort, merge sort, radix sort
int main()
{
    int a[]={2,4,1,5,8,3,7,6};
//    SelectSort(a, 0, 8);
//    QuickSort(a, 0, 8);
//    SelectSort(a, 0, 8);
//    BubbleSort(a, 0, 8);
    HeapSort(a,  0, 8);
    for(int i=0; i<8; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
