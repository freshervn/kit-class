#include <windows.h>
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
    gotoxy(6,7);
    printf("Hello world!\n");
    return 0;
}
