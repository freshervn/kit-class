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
void plush(int upateKey, int updateData1, char *updateData2);
LinkedList *FindKey(int Key);
void InSert(int Key,int NewKey,int NewData1,char *NewData2);
int main()
{

    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        plush(i, rand() % 100 + 1, "ABCD");
    }
    Printf(Head);
    InSert(3,9,100,"new Element");
    Printf(Head);
    return 0;
}

void plush(int updateKey, int updateData1, char *updateData2)
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
LinkedList *FindKey(int key)
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
    return NULL; 
}
void InSert(int Key,int NewKey,int NewData1,char *NewData2)
{
    LinkedList *NewElement=malloc(sizeof(LinkedList));
    if (FindKey(Key)!=NULL)
    {
        NewElement->key=NewKey;
        NewElement->data1=NewData1;
        NewElement->data2=NewData2;
        NewElement->next_poiter=FindKey(Key)->next_poiter;
        FindKey(Key)->next_poiter=NewElement;
    }

}