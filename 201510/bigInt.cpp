#include<iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    int a[201][101] = {0};
    a[0][1] = 1;
    for(int i = 1; i <= 200; ++i)
    {
        int tmp = 0;        //用于存储进位
        for(int j=1; j<100; j++)
        {
            a[i][j] = a[i-1][j] * i + tmp;
            tmp = a[i][j] / 10000;
            a[i][j] %= 10000;
        }
    }

    while(scanf("%d", &n) != EOF)
    {
        int k = 100;
        while(!a[n][k--]);    //排除前面为空的数组
        printf("%d", a[n][k + 1]);    //输出结果的前四位
        for(; k > 0; --k){
            printf("%04d", a[n][k]);    //输出其余的所有四位数字，若数字小于四位，则前面用0填充
                                        //最好是用printf可以比较好的控制输出的位数，这个用cout反而不是很好
        }
        printf("\n");
    }
    return 0;
}

