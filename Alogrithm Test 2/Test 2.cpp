//
//  Test 2.cpp
//  Alogrithm Test 2
//
//  Created by 黄沐 on 2016/9/22.
//  Copyright © 2016年 Mu Huang. All rights reserved.
//

#include "Test 2.hpp"

int A[2005][2005],tot = 0;
void Cover(int x1, int y1, int x2, int y2, int X, int Y);
void test();
void test_example();
int main()
{
    test_example();//样本函数
    test();//函数
    return 0;
}
void Cover(int x1, int y1, int x2, int y2, int X, int Y)
{
    if(x1 == x2 && y1 == y2) return;
    int midx = (x1 + x2)>>1, midy = (y1 + y2)>>1;
    if(X<=midx && Y<=midy) //判断特殊方格在棋盘的左下方
    {
        A[midx][midy+1] = A[midx+1][midy] = A[midx+1][midy+1] = tot++;
        Cover(x1, y1, midx, midy, X, Y);
        Cover(midx+1, y1, x2, midy, midx+1, midy);
        Cover(x1, midy+1, midx, y2, midx, midy+1);
        Cover(midx+1, midy+1, x2, y2, midx+1, midy+1);
    }
    if(X>midx && Y<=midy) //判断特殊方格在棋盘的右下方
    {
        A[midx][midy] = A[midx][midy+1] = A[midx+1][midy+1] = tot++;
        Cover(x1, y1, midx, midy, midx, midy);
        Cover(midx+1, y1, x2, midy, X, Y);
        Cover(x1, midy+1, midx, y2, midx, midy+1);
        Cover(midx+1, midy+1, x2, y2, midx+1, midy+1);
    }
    if(X<=midx && Y>midy) //判断特殊方格在棋盘的左上方
    {
        A[midx][midy] = A[midx+1][midy] = A[midx+1][midy+1] = tot++;
        Cover(x1, y1, midx, midy, midx, midy);
        Cover(midx+1, y1, x2, midy, midx+1, midy);
        Cover(x1, midy+1, midx, y2, X, Y);
        Cover(midx+1, midy+1, x2, y2, midx+1, midy+1);
    }
    if(X>midx && Y>midy)  //判断特殊方格在棋盘的右上方
    {
        A[midx][midy] = A[midx+1][midy] = A[midx][midy+1] = tot++;
        Cover(x1, y1, midx, midy, midx, midy);
        Cover(midx+1, y1, x2, midy, midx+1, midy);
        Cover(x1, midy+1, midx, y2, midx, midy+1);
        Cover(midx+1, midy+1, x2, y2, X, Y);
    }
}
void test()//函数
{
    int n, X, Y;
    printf("请依次输入棋盘的n值: ");
    scanf("%d",&n);
    printf("请输入X坐标: ");//输入特殊点的坐标
    scanf("%d",&X);
    printf("请输入Y坐标: ");
    scanf("%d",&Y);
    n = (1<<n);
    printf("你所输入的棋盘大小为: %d*%d ,特殊方格为 ( %d , %d )，显示如下\n",n,n,X--,Y--);
    A[X][Y] = -1;
    for(int i=0; i<n; i++) //显示棋盘
    {
        for(int j=0; j<n; j++)
            printf("%5d%c",A[i][j],j==n-1?'\n':' ');
    }
    Cover(0, 0, n-1, n-1, X, Y);
    printf("解决方案显示如下:\n");
    for(int i=0; i<n; i++) //显示解决方案
    {
        for(int j=0; j<n; j++)
            printf("%5d%c",A[i][j],j==n-1?'\n':' ');
    }
    for(int i=0; i<n; i++) //初始化
    {
        for(int j=0; j<n; j++)
            A[i][j]=0;
    }
}
void test_example()//样本函数
{
    int n=4, X=3, Y=3;//棋盘大小为16*16 特殊方格为(3,3)
    n = (1<<n);
    printf("测试棋盘大小为: %d*%d ,测试特殊方格为 ( %d , %d )，显示如下\n",n,n,X--,Y--);
    A[X][Y] = -1;
    for(int i=0; i<n; i++) //显示棋盘
    {
        for(int j=0; j<n; j++)
            printf("%5d%c",A[i][j],j==n-1?'\n':' ');
    }
    Cover(0, 0, n-1, n-1, X, Y);
    printf("解决方案显示如下:\n");
    for(int i=0; i<n; i++) //显示解决方案
    {
        for(int j=0; j<n; j++)
            printf("%5d%c",A[i][j],j==n-1?'\n':' ');
    }
    for(int i=0; i<n; i++) //初始化
    {
        for(int j=0; j<n; j++)
            A[i][j]=0;
    }
    puts("");
}

