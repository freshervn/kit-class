#include "stdio.h"
#include "stdlib.h"
typedef struct text
{
    int x;
    int y;
    int n;
    struct text *next;
} test;
test *headA=NULL;
test *headB=NULL;
void plush( test *head,int x,int y,int z);

void Printf(test *Head)
{
    test *new_element = malloc(sizeof(test));
    new_element = Head;
    while (new_element != NULL)
    {

        printf("\n key= %d", new_element->x);
        printf("\n data1= %d", new_element->y);
        printf("\n data2 =%s", new_element->n);
        printf("\n");
        new_element = new_element->next;
    };
}
int main()
{

    plush(&headA,1,2,3);
    plush(&headA,2,3,4);
    plush(&headB,4,5,6);
    Printf(headA);
    return 0;
}
void plush( test head,int x,int y,int n){
    test * new_element=malloc(sizeof(test));
    new_element->x=x;
    new_element->y=y;
    new_element->n=n;
    new_element->next=head;
    head-new_element;
}
