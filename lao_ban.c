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

int X[7]={10,2,5,2,10,2,2};// X[i]= Y;
int length=6;
int Xmax[100000000]={};

int maxX(int i,int hightbefore);

int main()
{
    int Max=maxX(0,0);
    // diện tích lớn nhất chứa cạnh đầu tiên. 

    // tính diện tích lớn nhất có thể thu dc từ cách cạnh sau
  
    for (int i = 1; i <= length; i++)
    {
        if (X[i] > X[i-1])   // nếu độ cao cạnh sau nhỏ hoac bằng  cạnh truoc do bỏ qua
        {
        Max= maxX(i,X[i-1]+1) > Max? maxX(i,X[i-1]+1):Max;
        }        
    }

    printf("\n%d",Max);
    return 0;
}
int maxX(int i,int highbefore) 
{  
     // find max of  each hight;
    int maxY=X[i];
    for(int y=highbefore; y <=X[i] ; y++)//xét từ ô sau cao hơn ô truoc
    {
        int j=i;
        while ((j+1<=length)&&(X[j+1]>=y))// tính chiều ngang lớn nhất có thể thu dc
        {
            j=j+1;            
        }
        // diện tích hình chữ nhật chiều dài y, chiều rông (j-i+1)
        maxY= (y*(j-i+1) > maxY ? y*(j-i) : maxY );        
    }
    return maxY;
}