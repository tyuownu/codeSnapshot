/*************************************************************************
    > File Name: first_appear_once_char.cpp
    > Author: tyu
    > Mail: tyuownu@gmail.com
    > Created Time: 06/11/2015 - 20:42:02
 ************************************************************************/

#include <iostream>
#include <map>
#include <string.h>
using namespace std;

// find the first appear only once char. We define the char are lowercase letters.
// e.g., input="sfenqfdsalids", output='e'.
// algorithm 1: commom method, sort then to find.
void sort(char *str, const int begin, const int end) //quicksort
{
    if(begin < end)
    {
        int left = begin, right = end;
        char temp=str[left];
        while(left < right)
        {
            while((str[right] >= temp)&&(left<right)) right--;
            if(left<right) str[left++] = str[right];

            while((str[left] < temp)&&(left<right)) left++;
            if(left<right) str[right--] = str[left];
        }
        str[left] = temp;
        sort(str, begin, left-1);
        sort(str, left+1, end);
    }
}

char FirstAloneChar1(const char *str, int n)
{
    map<char, int> map_char;
    int j=1;
    // build a map like that.
    // s f e n q d a l i
    // 1 2 3 4 5 6 7 8 9
    // so when we find a lot alone letters we can use this map to define which is first appear.
    for(int i=0; i<n; i++)
    {
        map_char.insert(map<char, int>::value_type(str[i], j++));
    }
    char *str2 = new char[n];
    memcpy(str2, str, n);
    sort(str2, 0, n-1);
    // variable a is letter that we need.
    // index is the first alone letter's index. using map.
    char a;
    int index=100; // beacuse we just use lowercase letter, 26 is enough.
    for(int i=1; i<n-1; i++)
    {
        if(str2[i]>str2[i-1] && str2[i]<str2[i+1])
        {
            if(map_char[str2[i]] < index)
            {
                index = map_char[str2[i]];
                a = str2[i];
            }
        }
    }
    return a;
}

// algorithm 2: using a map alone.
// s f e n q d a l i
// 3 2 1 1 1 2 1 1 1
char FirstAloneChar2(const char *str, int n)
{
    map<char, int> map_char;
    for(int i=0; i<n; i++)
    {
        if(map_char.count(str[i]) == 0)
            map_char.insert(map<char, int>::value_type(str[i], 1));
        else
            map_char[str[i]]++;
    }

    for(int i=0; i<n; i++)
    {
        if(1 == map_char[str[i]])
            return str[i];
    }
}

int main()
{
    char str[]="sfenqfdsalids";
    cout<<FirstAloneChar1(str, 13)<<endl;
    cout<<FirstAloneChar2(str, 13)<<endl;
    return 0;
}
