#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}

int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}
void line(char c,int length,int direction)
{
    int xdirection,ydirection;
    switch (direction)
    {
    case 8:
        xdirection=0;
        ydirection=-1;
        break;

    case 2:
        xdirection=0;
        ydirection=1;
        break;

    case 4:
        xdirection=-1;
        ydirection=0;
        break;

    case 6:
        xdirection=1;
        ydirection=0;
        break;

    case 9:
        xdirection=1;
        ydirection=-1;
        break;

    case 7:
        xdirection=-1;
        ydirection=-1;
        break;

    case 3:
        xdirection=1;
        ydirection=1;
        break;

    case 1:
        xdirection=-1;
        ydirection=1;
        break;
    }

    for (int i=0;i<length;i++)
    {
        gotoxy(wherex()+xdirection,wherey()+ydirection);
        printf("%c",c);
        gotoxy(wherex()-1,wherey());
    }

}
int main()
{
    int direction=9;
    gotoxy(8,8);
    line('*',4,direction);
    gotoxy(10,10);
    return 0;
}
