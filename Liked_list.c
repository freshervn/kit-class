#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct liked_list
{

    int key;

    int data1;

    char *data2;

    struct liked_list *next_poiter;
} LinkedList;

LinkedList *Head = NULL;

void Printf(LinkedList *Head);
void plus(int updateKey, int updateData1, char *updateData2);
LinkedList *FindKey(LinkedList *Head, int key);
void InSert(LinkedList * Head,int Key,int NewKey,int NewData1, char * NewData2);
int main()
{

    srand(time(0));

    for (int i = 0; i < 10; i++)
    {

        plus(i, rand() % 100 + 1, "ABCD");
    }

    Printf(Head);
    InSert(Head,9,2009,100,"success");
    Printf(Head);

    return 0;
}

void plus(int updateKey, int updateData1, char *updateData2)
{

    LinkedList *new_element = malloc(sizeof(LinkedList));

    new_element->key = updateKey;

    new_element->data1 = updateData1;

    new_element->data2 = updateData2;

    new_element->next_poiter = Head;

    Head = new_element;
}

void Printf(LinkedList *Head)

{

    LinkedList *new_element = malloc(sizeof(LinkedList));

    new_element = Head;

    while (new_element != NULL)
    {

        printf("\n key= %d", new_element->key);

        printf("\n data1= %d", new_element->data1);

        printf("\n data2 =%s", new_element->data2);

        printf("\n");

        new_element = new_element->next_poiter;
    };
}
LinkedList *FindKey(LinkedList * Head, int key)
{
    LinkedList *newElement=malloc(sizeof(LinkedList));
    newElement=Head;
    while (newElement!=NULL)
    {
        if (newElement->key==key)
        {
         return newElement;
        }
        newElement=newElement->next_poiter;
       
    }
    printf("key= %d \nNot found they key you want",key);
    return NULL;
    
}
void InSert(LinkedList * Head,int Key,int NewKey,int NewData1, char * NewData2)
{
    LinkedList *newElement=malloc(sizeof(LinkedList));
    if (FindKey(Head,Key)!=NULL)
    {
        newElement->key=NewKey;
        newElement->data1=NewData1;
        newElement->data2=NewData2;
        newElement->next_poiter=FindKey(Head,Key)->next_poiter;
        FindKey(Head,Key)->next_poiter=newElement;
    }
}
