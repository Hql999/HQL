#include <windows.h>
#pragma comment(lib, "winmm")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAGE_LIMIT 3237 //帧数
char name[20];
char str[40000];
void goto_xy(int x,int y);
int main()
{
    int p;
    int cur = 0;
    
    char temp;
    while(cur < 29){
        sprintf(name,"(%1d).txt",cur);
        p = 0;
        FILE *fp = fopen(name,"r");
        while (fread(&temp,sizeof(char),1,fp) != 0) 
        {
            str[p++] = temp;
        }
        printf("%s", str);
        fclose(fp);
        Sleep(40);
        goto_xy(0,0);
        cur++;
    }
    system("pause"); //等待用户信号
    return 0;
}

void goto_xy(int x, int y)
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hOut, pos);
}

