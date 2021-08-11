/*
* 2021-8-8 
* writen by TonyNomoney
*/

#include "fuminux.h"
#include "fuminux_screen.h"

/*
* 描点
*/
void drawPoint(int x, int y, char ch) {
	screen[x][y] = ch;
}

/*
* 绘制直线,但是没有[补偿],即有空缺的直线
* x1,y1必须大于等于x0,y0
*/
void drawLine(int x0, int y0, int x1, int y1, char ch) {
	int height = y1 - y0;
	int width = x1 - x0;
	float hpw = height / width;
	float wph = width / height;
	int x, y = 0;

	if (height == 0) {
		while (x0 + x <= x1) {
			screen[x0 + x][y0] = ch;
			x++;
		}
	}

	if (width == 0){
		while (y0 + y <= y1) {
			screen[x0][y0+y] = ch;
			y++;
		}
	}

	if (height - width > 0) {
		while (x0 + x < x1) {
			screen[x0 + x][y0 + (int)(hpw * x)] = ch;
			x++;
		}
	}
	else {
		while (y0 + y < y1) {
			screen[x0 + (int)(wph * y)][y0 + y] = ch;
			y++;
		}
	}
	

}


#include <string.h>
/*
* 在某位置插入字符串
*/
void insertWord(int x, int y, char word[]) {
	int ptr=0;
	while (ptr< strlen(word)) {
		screen[x + ptr][y] = word[ptr];
		ptr++;
	}
}

/*
* 绘制矩形
*/
void fillBlock(int x0, int y0, int x1,int y1,char ch) {
	int x, y = 0;
	while (x0 + x < x1) {
		while (y0 + y < y1) {
			screen[x0+x][x0+y] = ch;
			y++;
		}
		y = 0;
		x++;
	}
}

/*
*填充整个屏幕
*/
void fillAll(char ch) {
	int x, y = 0;
	int maxx = getNumberOfColumn();
	int maxy = getNumberOfRow();
	while (x < maxx) {
		while (y < maxy) {
			screen[x][y] = ch;
			y++;
		}
		y = 0;
		x++;
	}
}


#include <fstream> 
#include<sstream>
#include<iomanip>
/*
* 从txt文件读入屏幕内容
*/
void readFile(char filename[]) {
	char c;
	int x = 0;
	int y = 0;
	int maxx = getNumberOfColumn();
	ifstream in(filename);
	string line;
	if (in)
	{
		int x,y = 0;
		while (getline(in, line))
		{
			istringstream istrline(line);
			char c;
			while (istrline >> c) {
				x++;
				screen[x][y] = c;
			}
			x = 0;
			y++;
		}
	}
	else {
		cout << "No such a file" << endl;
		cout << "No such a file" << endl;
		cout << "No such a file" << endl;
		cout << "No such a file" << endl;
		cout << "No such a file" << endl;
	}
	in.close();



}