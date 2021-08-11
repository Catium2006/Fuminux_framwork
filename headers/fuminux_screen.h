#pragma once
/*
������Ļ���ͷ�ļ�
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
��ʼ����Ļ,ȫ�����ո�
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
ˢ��������Ļ,�����Ҫ�������
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

