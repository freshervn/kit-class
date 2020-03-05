#include "stdio.h"
int main()
{
    typedef struct this_is_struct
    {
        int data1;
        char data2;
        double data3;
        struct this_is_struct *poiter;
    } MY_STRUCT;
    struct this_is_struct struct1,struct2[1];
    MY_STRUCT *struct3;

    struct1.data1=1;
    struct1.data2='A';
    struct1.data3=3.1415962;
    struct1.poiter=&struct2[0];

    struct2[0].data1=2;
    struct2[0].data2='B';
    struct2[0].data3=2.7182818285;
    struct2[0].poiter=struct3;

    struct3->data1=3;
    struct3->data2='C';
    struct3->data3=1.1412135624;
    struct3->poiter=&struct1;
    
    printf("\n Struct1= %d ",&struct1);
    printf("\n data1= %d",struct1.data1);
    printf("\n data2= %c",struct1.data2);
    printf("\n data3= %f",struct1.data3);
    printf("\n poiter1= %d ",struct1.poiter);

    printf("\n");
    printf("\n struct2[0]= %d ",&struct2[0]);
    printf("\n data1= %d",struct2[0].data1);
    printf("\n data2= %c",struct2[0].data2);
    printf("\n data3= %f",struct2[0].data3);
    printf("\n poiter2= %d ",struct2[0].poiter);

    printf("\n");
    printf("\n Struct3= %d ",&struct3);
    printf("\n data1= %d",struct3->data1);
    printf("\n data2= %c",struct3->data2);
    printf("\n data3= %f",struct3->data3);
    printf("\n poiter2= %d ",struct3->poiter); 
   
   
     return 0;
}