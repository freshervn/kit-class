#include "stdio.h"
#include "stdlib.h"
#include <time.h> //
typedef struct horse
{
    int x;
    int y;
    struct horse *next;

} HORSE; // struct để lưu những tọa độ đã đi qua.
HORSE *Head = NULL;
HORSE *way=NULL;
int targetX = 7, targetY = 7;
int horseX = 0, horseY = 0;
void Plush(int x, int y); // cộng ô đã đi vào danh sách;
void WayPlush(int x, int y);// gi lại đường đi
void printfway();// in đường đi
void Printf(HORSE *taill);
int  Check(int x,int y);
int minstep(int numStep,HORSE *Taill);

int main(int argc, char const *argv[])
{
     srand(time(0)); 
    
    Plush(horseX,horseY);
    minstep(1,NULL);
    return 0;
}
void Plush(int x, int y)
{
    HORSE *newElement = (HORSE *)malloc(1 * sizeof(HORSE));
    newElement->x = x;
    newElement->y = y;
    newElement->next = Head;
    Head = newElement;
}
void WayPlush(int x, int y){
    HORSE *newElement = (HORSE *)malloc(1 * sizeof(HORSE));
    newElement->x = x;
    newElement->y = y;
    newElement->next = way;
    way = newElement;
}
void Printf(HORSE *taill)
{
    HORSE *newElement = (HORSE *)malloc(sizeof(HORSE));
    newElement = Head;
    while (newElement != taill)
    {
        printf("%d,%d\n", newElement->x, newElement->y);
        newElement = newElement->next;
    }
}
void printfway(int x, int y){
     HORSE *newElement = (HORSE *)malloc(sizeof(HORSE));
    newElement = way;
    while (newElement != NULL)
    {
        printf("%d,%d\n", newElement->x, newElement->y);
        newElement = newElement->next;
    }
}
int  Check(int X,int Y){
    HORSE * Check_This=(HORSE*)malloc(sizeof(HORSE));
    Check_This=Head;
    do
    {
        if ((Check_This->x==X)&&(Check_This->y==Y))
        {
            return 0;
        }
        Check_This=Check_This->next;
    } while (Check_This!=NULL);
    return 1;
    
}
int minstep(int numStep,HORSE *Taill)
{
    HORSE * Element=(HORSE*)malloc(sizeof(HORSE));
    HORSE * new_taill=Head;
    Element=Head;
    while (Element!=Taill)// duyệt tất cả các ô có trước đó
    {
        if (Element->x+2<=7) // đi sang 
        {
            if (Element->y+1<=7)// đi xuống
            {
                if (Element->x+2==targetX&&Element->y+1==targetY)// ô đích
                {
                    printf("\n%d",numStep);
                    return numStep;
                }
                else if (Check(Element->x+2,Element->y+1))// ko phải ô đích và ko phải ô đã đi qua
                {
                    Plush(Element->x+2,Element->y+1);// thêm 1 ô có thể đi
                }                                
            }
            if (Element->y-1>=0)
            {
                if (Element->x+2==targetX&&Element->y-1==targetY)
                {
                    printf("\n%d",numStep);
                    return numStep;
                }
                else if (Check(Element->x+2,Element->y-1))
                {
                    Plush(Element->x+2,Element->y-1);
                }                
            }            
        }
        if (Element->x-2>=0) // đi sang 
        {
            if (Element->y+1<=7)// đi xuống
            {
                if (Element->x-2==targetX&&Element->y+1==targetY)// ô đích
                {
                    printf("\n%d",numStep);
                    return numStep;
                }
                else if (Check(Element->x-2,Element->y+1))// ko phải ô đích
                {
                    Plush(Element->x-2,Element->y+1);// thêm 1 ô có thể đi
                }                                
            }
            if (Element->y-1>=0)
            {
                if (Element->x-2==targetX&&Element->y-1==targetY)
                {
                    printf("\n%d",numStep);
                    return numStep;
                }
                else if (Check(Element->x-2,Element->y-1))
                {
                    Plush(Element->x-2,Element->y+1);
                }    
            }
        }
        if (Element->y+2<=7)
        {
            if (Element->x+1<=7)
            {
                if ((Element->x+1==targetX)&&(Element->y+2==targetY))
                {
                    printf("\n%d",numStep);
                    return numStep;
                }
                else if (Check(Element->x+1,Element->y+2))
                {
                    Plush(Element->x+1,Element->y+2);
                }                
            }
            if (Element->x-1>=0)
            {
                if ((Element->x-1==targetX)&&(Element->y+2==targetY))
                {
                    printf("\n%d",numStep);
                    return numStep;
                }
                else if (Check(Element->x-1,Element->y+2))
                {
                    Plush(Element->x-1,Element->y+2);
                }                
            }
        }
        if (Element->y-2>=0)
        {
            if (Element->x+1<=7)
            {
                if ((Element->x+1==targetX)&&(Element->y-2==targetY))
                {
                    printf("\n%d",numStep);
                    return numStep;
                }
                else if (Check(Element->x+1,Element->y-2))
                {
                    Plush(Element->x+1,Element->y-2);
                }                
            }
            if (Element->x-1>=0)
            {
                if ((Element->x-1==targetX)&&(Element->y-2==targetY))
                {
                    printf("\n%d",numStep);
                    return numStep;
                }
                else if (Check(Element->x-1,Element->y-2))
                {
                    Plush(Element->x-1,Element->y-2);
                }                
            }
        }
        Element=Element->next;
    }
    if(new_taill!=Head){
    Printf(new_taill);
    printf("\n");
    minstep(numStep+1,new_taill);
    }
}
