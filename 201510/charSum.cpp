/*************************************************************************
    > File Name: charSum.cpp
    > Author: 
    > Mail: 
    > Created Time: 2015年10月30日 星期五 20时21分29秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <map>
#include <iterator>
using namespace std;

int main()
{
    char s[1024];
    gets(s);
    map<char, int> m;
    for(int i=0; *(s+i); i++)
        m[s[i]]++;

    for(map<char, int>::iterator it=m.begin(); it!=m.end(); ++it)
        cout<<(*it).first<<" "<<(*it).second<<endl;
    return 0;
}

