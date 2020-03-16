#include "stdio.h"
#include "stdlib.h"
typedef struct horse
{
    int x;
    int y;
    struct horse *next;

} HORSE; // struct để lưu những tọa độ đã đi qua.
HORSE *Head = NULL;
HORSE *Way=NULL;
int targetX = 7, targetY = 7;
int horseX = 0, horseY = 0;

void Plush(int x, int y); // cộng ô đã đi vào danh sách;
void Printf(HORSE *taill);
int  Check(int x,int y);
int minstep(int numStep,HORSE *Taill);

void WayPlush(int x, int y);// gi lại đường đi
int printfway();// in đường đi

int main()
{
    printf("nhap toa do con ngua hien tai");
    scanf("%d %d",&horseX,&horseY);
    printf("\n nhap toa độ ô tới");
    scanf("%d %d",&targetX,&targetY);
    
    Plush(horseX,horseY);
    WayPlush(targetX,targetY);
    minstep(1,NULL);
    WayPlush(horseX,horseY);
    printfway();
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
    newElement->next = Way;
    Way = newElement;
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
int printfway(){
    HORSE *newElement = (HORSE *)malloc(sizeof(HORSE));
    newElement = Way;
    int i=0;
    while (newElement!= NULL)
    {
        printf("%d,%d\n", newElement->x, newElement->y);
        newElement = newElement->next;
        i++;
    }
    printf("so buoc =%d",i-1);
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
                    targetX=Element->x;
                    targetY=Element->y;
                    if (targetX==horseX&&targetY==horseY)
                    {
                       return numStep;
                    }                    
                    WayPlush(Element->x,Element->y);
                    Head=NULL;
                    Plush(horseX,horseY);
                    minstep(1,NULL);
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
                    targetX=Element->x;
                    targetY=Element->y;
                     if (targetX==horseX&&targetY==horseY)
                    {
                       return numStep;
                    }  
                    WayPlush(Element->x,Element->y);
                    Head=NULL;
                    Plush(horseX,horseY);
                    minstep(1,NULL);
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
                    targetX=Element->x;
                    targetY=Element->y;
                     if (targetX==horseX&&targetY==horseY)
                    {
                         return numStep;
                    }  
                    WayPlush(Element->x,Element->y);
                    Head=NULL;
                    Plush(horseX,horseY);
                    minstep(1,NULL);
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
                    targetX=Element->x;
                    targetY=Element->y;
                     if (targetX==horseX&&targetY==horseY)
                    {
                         return numStep;
                    }  

                    WayPlush(Element->x,Element->y);
                    Head=NULL;
                    Plush(horseX,horseY);
                    minstep(1,NULL);
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
                    targetX=Element->x;
                    targetY=Element->y;
                     if (targetX==horseX&&targetY==horseY)
                    {
                     return numStep;
                    }  
                    WayPlush(Element->x,Element->y);
                     Head=NULL;
                    Plush(horseX,horseY);
                    minstep(1,NULL);
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
                    targetX=Element->x;
                    targetY=Element->y;
                     if (targetX==horseX&&targetY==horseY)
                    {
                       return numStep;
                    }  
                    WayPlush(Element->x,Element->y);
                    Head=NULL;
                    Plush(horseX,horseY);
                    minstep(1,NULL);
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
                    targetX=Element->x;
                    targetY=Element->y;
                     if (targetX==horseX&&targetY==horseY)
                    {
                     return numStep;
                    }  
                    WayPlush(Element->x,Element->y);
                   Head=NULL;
                    Plush(horseX,horseY);
                    minstep(1,NULL);
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
                    targetX=Element->x;
                    targetY=Element->y;
                     if (targetX==horseX&&targetY==horseY)
                    {
                         return numStep;
                    }  
                    WayPlush(Element->x,Element->y);
                     Head=NULL;
                    Plush(horseX,horseY);
                    minstep(1,NULL);
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
    minstep(numStep+1,new_taill);
    }
}
