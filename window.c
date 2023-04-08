#include "window.h"
#include "font.h"
#include <stdio.h>
#include "build.h"
/*
* @note 设置光标位置
*/
void gotoxy(int x, int y)
{
    COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


int init(void)
{
	int yourchoice;
	// 画出界面
	gotoxy(30, 2);
	color(11);
	printf("\t扶丕梯入门测试系统\n");
	printf("\n");
	//color(13);
	printf("\t\t★★★★★★★★  TEST!");
	printf("\t\t★★★★★★★★  TEST!");
	gotoxy(37, 6);
	color(12);
	printf("1.重新生成8个元素的数组\n");
	gotoxy(37, 8);
	printf("2.完成a功能\n");
	gotoxy(37, 10);
	printf("3.完成b功能\n");
	gotoxy(37, 12);
	printf("4.完成c功能\n");
	gotoxy(37, 14);
	printf("5.完成d功能\n");
	gotoxy(37, 16);
	printf("6.完成e功能\t\n");
	gotoxy(37, 18);
	printf("7.查看操作详细说明\n");

	color(11);
	printf("请选择:");
	scanf("%d", &yourchoice);
	switch (yourchoice)
	{
	case 1:
		system("cls");
		init_build(1);
		// 初始化
		break;
	case 2:
		system("cls");
		//gotoxy(30, 10);
		color(11);
		init_build(2);
		//printf("该功能未实现!");
		break;
	case 3:
		system("cls");
		gotoxy(30, 10);
		color(11);
		printf("该功能未实现!");
		break;
    case 4:
		system("cls");
		gotoxy(30, 10);
		color(11);
		printf("该功能未实现!");
		break;
	case 5:
		system("cls");
		gotoxy(30, 10);
		color(11);
		printf("该功能未实现!");
		break;
    case 6:
		system("cls");
		gotoxy(30, 10);
		color(11);
		printf("该功能未实现!");
		break;
    case 7:
		system("cls");
		gotoxy(30, 10);
		color(11);
		printf("该功能未实现!");
		break;
    case 0:
        break;
	default:
		system("cls");
		printf("没有此序号,请输入0-7数字\n");
		Sleep(2000);
		system("cls");
	}
	return yourchoice;
}
