#include "stdio.h"
#include "stdlib.h"
typedef struct danhsach
{
    int Number;
    struct danhsach *next_number;
    struct dachsach *befor_number;
} DanhSach;

DanhSach *Head = NULL;
DanhSach *Taill = NULL;

void Plush_DanhDach_On_Top(int number);
void Printf_From_Top(DanhSach *Head);
void Plush_DanhDach_To_Bottom(int number);
void Printf_From_Taill(DanhSach *Taill);

int main()
{
    int request;
    int Element;
    printf("        MENU                \n");
    printf("    chọn chức năng          \n");
    printf(" 1 tạo danh sách            \n");
    printf(" 2 thêm phần tử vào đầu ds  \n");
    printf(" 3 thêm phần tử vào cuối ds \n");
    printf(" 4 EXIT                     \n");
    do
    {
        scanf("%d",&request);

        switch (request)
        {
        case 1:
        Head = NULL;
        Taill = NULL;
        printf("\n nhập số phần tử ban đầu của danh sách");
        int numbers;
        scanf("%d",&numbers);
        for (int i = 0; i < numbers; i++)   
        {
            scanf("%d",&Element);
            Plush_DanhDach_On_Top(Element);
        }
        printf("\n  trương trình đã  nhận dữ liệu ,ấn phim 2,3 để tiếp tục thao tác , ấn 4 để in ra kq , ấn  phim 1 để lập 1 danh sách khác");
            break;
        case 2:
        printf("\nNhập phần tử cần thêm vào ");
        scanf("%d",&Element);
        Plush_DanhDach_On_Top(Element);
        printf("\n  trương trình đã  nhận dữ liệu ,ấn phim 2,3 để tiếp tục thao tác , ấn 4 để in ra kq , ấn  phim 1 để lập 1 danh sách khác");
        break;
        case 3:
        printf("\nNhập phần tử cần thêm vào ");
        scanf("%d",&Element);
        Plush_DanhDach_To_Bottom(Element);
        printf("\n  trương trình đã  nhận dữ liệu ,ấn phim 2,3 để tiếp tục thao tác , ấn 4 để in ra kq , ấn  phim 1 để lập 1 danh sách khác");
        break;
        default:
        break;
        }
    } while (request!=4);
    Printf_From_Top(Head);
    printf("\n");
    Printf_From_Taill(Taill);
    getchar();
    return 0;
}
void Plush_DanhDach_On_Top(int number)
{
    DanhSach *new_poiter = malloc(sizeof(DanhSach));
    new_poiter->Number = number;
    new_poiter->next_number = Head;
    Head = new_poiter;
    new_poiter->befor_number = NULL;
    if (new_poiter->next_number != NULL)
    {
        new_poiter->next_number->befor_number = new_poiter;
    }
    else
    {
        Taill = new_poiter;
    }
}
void Printf_From_Top(DanhSach *Head)
{
    DanhSach *printf_Element = malloc(sizeof(DanhSach));
    printf_Element = Head;
    while (printf_Element != NULL)
    {
        printf("\t%d", printf_Element->Number);
        printf_Element = printf_Element->next_number;
    }
}
void Plush_DanhDach_To_Bottom(int number){
    DanhSach *new_poiter=malloc(sizeof(DanhSach));
    new_poiter->Number=number;
    new_poiter->befor_number=Taill;
    new_poiter->next_number=NULL;
    if (Taill!=NULL)
    {
        Taill->next_number=new_poiter;
    }
    else
    {
        Taill=new_poiter;
        Head=new_poiter;
    }
}
void Printf_From_Taill(DanhSach *Taill)
{
    DanhSach *Printf_Element= malloc(sizeof(DanhSach));
    Printf_Element=Taill;
    while (Printf_Element!=NULL)
    {
         printf("\t%d",Printf_Element->Number);
        Printf_Element=Printf_Element->befor_number;
    }      
}