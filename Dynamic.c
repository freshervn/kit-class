#include "stdio.h"
#include "stdlib.h"
int main()
{
    // initialize  malloc  with interger
    int *prtInt=(int *)malloc( 2*sizeof(int*));
    prtInt[0]=1;
    prtInt[1]=2;
    printf("this is value of prt %d",prtInt);
    printf("\nthis is value of *prt %d",*prtInt);
    printf("\nthis is value of  heap [0]=%d [1]=%d",prtInt[0],prtInt[1]);  

    // initialize with char
    char *prtChar=malloc(2*sizeof(char));
    prtChar[0]='A';
    prtChar[1]='B';
    printf("\n");
    printf("\nthis is value of prt %d",prtChar);
    printf("\nthis is value of *prt %c",*prtChar);
    printf("\nthis is value of  heap [0]=%c [1]=%c",prtChar[0],prtChar[1]); 

    // initialize with struct
    typedef struct prtstruct
    {
        int data;
        char name;
        struct prtstruct *next;        
    } PRTSTRUCT;

    PRTSTRUCT * prtStruct=(PRTSTRUCT *)malloc(2*sizeof(PRTSTRUCT));
    prtStruct[0].data=1;
    prtStruct[0].name='A';
    prtStruct[0].next=&prtStruct[1];

    prtStruct[1].data=2;
    prtStruct[1].name='B';
    prtStruct[1].next=NULL;

    printf("\n");
    printf("\n sizeof(PrtStruct)=%d",sizeof(PRTSTRUCT));
    printf("\n sizeof(int)+ sizeof(char)+sizeof(struct poiter):");
    printf("%d+%d+%d",sizeof(prtStruct[0].data),sizeof(char *),sizeof(prtStruct[0].next));
    printf("\n this is value of prtStruct %d",*prtStruct);
    printf("\n data,name,poiter %d %C %d %c ",prtStruct[0].data,prtStruct[0].name,prtStruct[0].next->data,prtStruct[0].next->name);
    
    free(prtStruct);

    // calloc continous allocated
    int *prtCalloc = calloc(2,sizeof(int));

    if (prtCalloc==NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else 
    {
        printf("\n Memory havebeen success allocated");
    }
    
    return 0;
}
