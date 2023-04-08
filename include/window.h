#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <windows.h> //界面交换包含句柄坐标等函数
#include <time.h> //包含字体句柄，时间函数
#include <string.h>
/*
* auther: liuqi
* date : 2023/3/28
* @note : 窗口函数

*/


void gotoxy(int x, int y);
int init(void); //界面初始化


#endif // _WINDOW_H_
