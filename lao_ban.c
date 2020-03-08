/************************************************************************
*                  lỗ ban                                               *
*                                                                       *
************************************************************************/
/*
    y   ^
        |           000
        |        000000   
        |  000   000000   00000
        |  000   000000   00000
        |  000   000000   00000
        |  00000000000000000000
        |  00000000000000000000 
        .--------------------------------> 
                                          X
*/


#include "stdio.h"

int X[7]={2,1,4,5,1,3,3};// X[i]= Y;
int length=6;
int Xmax[100000000]={};

int maxX(int i,int hightbefore);


int main()
{
    int Max=maxX(0,0);
    for (int i = 1; i <= length; i++)
    {
        if (X[i] > X[i-1])
        {
        Max= maxX(i,X[i-1]+1) > Max? maxX(i,X[i-1]+1):Max;
        }        
    }
    printf("\n%d",Max);
    return 0;
}
int maxX(int i,int highbefore)
{   // find max of  each hight;
    int maxY=X[i];
    for(int y=highbefore; y <=X[i] ; y++)
    {
        int j=i;
        while ( (X[j]>=y) && (j<=length) )
        {
            ++j;            
        }
        maxY= (y*(j-i+1) > maxY ? y*(j-i) : maxY );        
    }
    return maxY;
}