#include "window.h"
#include "font.h"
#include <stdio.h>
#include "build.h"
/*
* @note ���ù��λ��
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
	// ��������
	gotoxy(30, 2);
	color(11);
	printf("\t��ا�����Ų���ϵͳ\n");
	printf("\n");
	//color(13);
	printf("\t\t���������  TEST!");
	printf("\t\t���������  TEST!");
	gotoxy(37, 6);
	color(12);
	printf("1.��������8��Ԫ�ص�����\n");
	gotoxy(37, 8);
	printf("2.���a����\n");
	gotoxy(37, 10);
	printf("3.���b����\n");
	gotoxy(37, 12);
	printf("4.���c����\n");
	gotoxy(37, 14);
	printf("5.���d����\n");
	gotoxy(37, 16);
	printf("6.���e����\t\n");
	gotoxy(37, 18);
	printf("7.�鿴������ϸ˵��\n");

	color(11);
	printf("��ѡ��:");
	scanf("%d", &yourchoice);
	switch (yourchoice)
	{
	case 1:
		system("cls");
		init_build(1);
		// ��ʼ��
		break;
	case 2:
		system("cls");
		//gotoxy(30, 10);
		color(11);
		init_build(2);
		//printf("�ù���δʵ��!");
		break;
	case 3:
		system("cls");
		gotoxy(30, 10);
		color(11);
		printf("�ù���δʵ��!");
		break;
    case 4:
		system("cls");
		gotoxy(30, 10);
		color(11);
		printf("�ù���δʵ��!");
		break;
	case 5:
		system("cls");
		gotoxy(30, 10);
		color(11);
		printf("�ù���δʵ��!");
		break;
    case 6:
		system("cls");
		gotoxy(30, 10);
		color(11);
		printf("�ù���δʵ��!");
		break;
    case 7:
		system("cls");
		gotoxy(30, 10);
		color(11);
		printf("�ù���δʵ��!");
		break;
    case 0:
        break;
	default:
		system("cls");
		printf("û�д����,������0-7����\n");
		Sleep(2000);
		system("cls");
	}
	return yourchoice;
}
