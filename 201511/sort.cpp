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
void InsertSort(int *a, const int begin, const int end, const int step)
{
    if(begin < end)
    {
        for(int i=begin+step ; i<end; )
        {
            int temp = a[i], j;
            for(j=i-step; j>=0 && j<end-step; )
            {
                if(temp<a[j])
                    a[j+step] = a[j];
                else
                    break;
                j = j-step;
            }
            a[j+step] = temp;
            i = i+step;
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
// TODO: adding step to InsertSort so can use for shell sort.

void ShellSort(int *a, const int begin, const int end)
{
    int step = end/2;
    int time = 2;
    while(step>=1)
    {
        for(int i=0; i<time; i++)
        {
            InsertSort(a, begin, end, step );
        }
        step = step/2;
        time = time*2;
    }
    
}

// algorithm 6: heap sort
// time complexity: O(n*log(n)), large-top heap.
// Algorithm from : allmycode/sort.git, this is more clear.
void BigHeap(int *a, const int i, const int size)
{
    int left = 2*i +1;
    int right = 2*i +2;
    int index = i;
    if(left < size && a[left]>a[index]) index = left;
    if(right < size && a[right]>a[index]) index = right;
    if(index != i)
    {
        swap(a[index], a[i]);
        BigHeap(a, index, size);
    }
}

void BuildHeap(int *a, const int n)
{
    for(int i=n/2; i>=0; i--)
    {
        BigHeap(a, i, n);
    }
}
void HeapSort(int *a, const int begin, const int end)
{
//    BuildHeap(a, end);
    BuildHeap(a,  end);
    int size = end;
    for(int i=end-1; i>=0; i--)
    {
        swap(a[0], a[i]);
        size--;
        BigHeap(a, 0, i);
    }
}

// Algorithm 7: merge sort.
// time complexity: O(N*log(N))
void SortOrderArr(int *a, const int begin, const int mid, const int end)
{
    int *p = new int[end - begin+1];
    int first_left = begin;
    int second_left = mid+1;
    int i=0;
    while(first_left <= mid && second_left <= end)
    {
        if(a[first_left] < a[second_left]) p[i++] = a[first_left++];
        else p[i++] = a[second_left++];
    }

    if(first_left<=mid)
        while(first_left<=mid)
            p[i++] = a[first_left++];
    else
        while(second_left <= end)
            p[i++] = a[second_left++];

    for(int j=0; j<i; j++)
        a[begin+j] = p[j];
}
void MergeSort(int *a, const int begin, const int end)
{
    if(begin < end)
    {
            int mid = begin + (end-begin)/2;
            MergeSort(a, begin, mid);
            MergeSort(a, mid+1, end);
            SortOrderArr(a, begin, mid, end);
    }
    
}

void RadixSort(int *a, const int begin, const int end)
{
    
}
// TODO: shell sort, merge sort, radix sort
int main()
{
    int a[]={2,4,1,5,8,3,7,6};
//    InsertSort(a, 1, 8, 2);
//    SelectSort(a, 0, 8);
//    QuickSort(a, 0, 8);
//    SelectSort(a, 0, 8);
//    BubbleSort(a, 0, 8);
//    HeapSort(a,  0, 8);
//    MergeSort(a, 0, 7);
    ShellSort(a, 0, 8);
    for(int i=0; i<8; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
