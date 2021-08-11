#pragma once
/*
用于屏幕相关头文件
TonyNomoney
2021-8-6
*/


using namespace std;
/**
we support no more than 256*256 chars screen
*/
char screen[256][256];

#include<sys/ioctl.h>
#include<termios.h>
#include<signal.h>
#include<unistd.h>
int getNumberOfColumn() {
    struct winsize info;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &info);
    return info.ws_col;
}

int getNumberOfRow() {
    struct winsize info;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &info);
    return info.ws_row;
}

/*
初始化屏幕,全部填充空格
*/
void init() {
    int x, y = 0;
    int maxx = getNumberOfColumn();
    int maxy = getNumberOfRow();
    while (x < maxx) {
        while (y < maxy) {
            screen[x][y] = '_';
            y++;
        }
        y = 0;
        x++;
    }

}



#include <iostream>
/*
刷新整个屏幕,输出需要反向输出
*/
void flush() {
    //system("clear");
    int x, y = 0;
    int maxy = getNumberOfColumn();
    int maxx = getNumberOfRow();
    while (x < maxx) {
        while (y < maxy) {
            cout << screen[y][x];
            y++;
        }
        cout << endl;
        y = 0;
        x++;
    }

}

