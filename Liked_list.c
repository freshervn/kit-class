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
void FindKey(int key);
int main()
{

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {

        plus(i, rand() % 100 + 1, "ABCD");
    }

    Printf(Head);
    FindKey(6);

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
void FindKey(int key)
{
    LinkedList *newElement=malloc(sizeof(LinkedList));
    newElement=Head;
    while (newElement!=NULL)
    {
        if (newElement->key==key)
        {
           
        printf("\n key= %d", newElement->key);

        printf("\n data1= %d", newElement->data1);

        printf("\n data2 =%s", newElement->data2);

        printf("\n");
         return;
        }
        newElement=newElement->next_poiter;
       
    }
    printf("key= %d \nNot found they key you want",key);
    
}
