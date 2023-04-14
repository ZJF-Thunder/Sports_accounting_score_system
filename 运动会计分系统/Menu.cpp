#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Graphics.h>
#include <easyx.h>
#include <conio.h>
#include "Project.h"
#include "Menu.h"
#include "Password.h"
using namespace std;

//菜单
void menu()
{
	MOUSEMSG m;//定义鼠标变量 m
	initgraph(980, 500); //定义画布大小也就是黑框大小
	setbkcolor(0xAFEEEE);//设置背景颜色 用与RGB相对应的16进制代码表示
	cleardevice();//刷新一次 略等于那个system(cls) 用当前背景色清空屏幕
	setfillcolor(0x9AFF9A);//设置后面用函数画出方框的背景颜色
	//           左边1 高1 左边2 高2
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(0, 0, 70, 30);

	settextcolor(BLACK);
	settextstyle(45, 0, _T("楷体"));
	outtextxy(335, 70, _T("运动会计分系统"));//系统坐标

	settextstyle(15, 0, _T("楷体"));//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景
	outtextxy(475, 208, _T("登录"));
	outtextxy(475, 258, _T("注册"));
	outtextxy(475, 308, _T("退出"));
	outtextxy(20, 8, _T("帮助"));

	while (1)
	{
		//获取鼠标消息
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			//画出红色的矩形框线
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//登录
			if (m.uMsg == WM_LBUTTONDOWN) //鼠标左键点击消息
			{
				closegraph();
				//登录
				log_in_menu();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//注册 注册成功然后跳转到登录界面或者退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				//注册 注册成功然后跳转到登录界面或者退出系统
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				exit(1);//退出系统
			}
		}
		else if (m.x >= 0 && m.x <= 70 && m.y >= 0 && m.y <= 30)
		{
			setlinecolor(RED);
			rectangle(0, 0, 70, 30);
			//获取帮助
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				//帮助文档
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(385, 195, 595, 235);
			rectangle(385, 245, 595, 285);
			rectangle(385, 295, 595, 335);
			rectangle(0, 0, 70, 30);
		}
	}
	getchar();
	closegraph();

}

//登录菜单
void log_in_menu()
{
	MOUSEMSG m;//定义鼠标变量 m
	initgraph(980, 500); //定义画布大小也就是黑框大小
	setbkcolor(0xAFEEEE);//设置背景颜色 用与RGB相对应的16进制代码表示
	cleardevice();//刷新一次 略等于那个system(cls) 用当前背景色清空屏幕
	setfillcolor(0x9AFF9A);//设置后面用函数画出方框的背景颜色
	//           左边1 高1 左边2 高2
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(0, 0, 70, 30);

	settextcolor(BLACK);
	settextstyle(45, 0, _T("楷体"));
	outtextxy(335, 70, _T("运动会计分系统"));//系统坐标

	settextstyle(15, 0, _T("楷体"));//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景
	outtextxy(455, 208, _T("管理员登录"));
	outtextxy(460, 258, _T("用户登录"));
	outtextxy(460, 308, _T("退出系统"));
	outtextxy(20, 8, _T("帮助"));

	while (1)
	{
		//获取鼠标消息
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			//画出红色的矩形框线
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//管理员登录
			if (m.uMsg == WM_LBUTTONDOWN) //鼠标左键点击消息
			{
				closegraph();
				Password();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//用户登录
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				Password();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				exit(1);//退出系统
			}
		}
		else if (m.x >= 0 && m.x <= 70 && m.y >= 0 && m.y <= 30)
		{
			setlinecolor(RED);
			rectangle(0, 0, 70, 30);
			//获取帮助
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(385, 195, 595, 235);
			rectangle(385, 245, 595, 285);
			rectangle(385, 295, 595, 335);
			rectangle(0, 0, 70, 30);
		}
	}
	getchar();
	closegraph();

}



//管理员菜单
void adm_menu()
{
	CollegeNode* pHead = NULL;
	ProjectNode* ppHead = NULL;
	system("cls");

	MOUSEMSG m;//定义鼠标变量 m
	//菜单
	//initgraph(1000, 500);
	initgraph(980, 500); //定义画布大小也就是黑框大小
	setbkcolor(0xAFEEEE);//设置背景颜色 用与RGB相对应的16进制代码表示
	cleardevice();//刷新一次 略等于那个system(cls) 用当前背景色清空屏幕
	setfillcolor(0x9AFF9A);//设置后面用函数画出方框的背景颜色
	//           左边1 高1 左边2 高2
	fillrectangle(390, 150, 590, 180);
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(390, 400, 590, 430);
	fillrectangle(390, 450, 590, 480);
	fillrectangle(0, 0, 100, 30);


	settextcolor(BLACK);//设置字体颜色为黑色
	settextstyle(45, 0, _T("楷体"));
	outtextxy(335, 70, _T("运动会计分系统"));//系统坐标

	settextstyle(15, 0, _T("楷体"));//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景
	outtextxy(460, 158, _T("输入成绩"));//没有初始化不能操作
	outtextxy(460, 208, _T("查询成绩"));
	outtextxy(460, 258, _T("浏览成绩"));
	outtextxy(475, 308, _T("排序"));
	outtextxy(460, 358, _T("系统设置"));
	outtextxy(460, 408, _T("上级菜单"));
	outtextxy(465, 458, _T("主菜单"));
	outtextxy(20, 8, _T("退出系统"));

	while (1)
	{
		m = GetMouseMsg();

		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//如果点击了输入
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //读取到内存中
				ppHead = ProjectFileRead(ppHead);//读取到内存中
				system("cls");
				InputScore(ppHead, pHead);

				CollegeFileWrite(pHead);
				ProjectFileWrite(ppHead);

				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				adm_menu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//如果点击了查询
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //读取到内存中
				ppHead = ProjectFileRead(ppHead);//读取到内存中
				system("cls");
				char choice[10] = "0";;//查询的选择
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                        *******请选择您要查询的对象：*******" << endl;
				cout << "\t\t                       *******      1-->查找学院      *******" << endl;
				cout << "\t\t                      *******       2-->查找项目       *******" << endl;
				cout << "\t\t                        *******     3-->返回菜单   *******" << endl;
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                     请输入您的选择(1-3):";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> choice;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				system("cls");

				if (strcmp(choice, "1") == 0)
				{
					CollegeSearch(pHead);
				}
				else if (strcmp(choice, "2") == 0)
				{
					ProjectSearch(ppHead, pHead);
				}
				else if (strcmp(choice, "3") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
					cout << "返回菜单!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					system("cls");
					adm_menu();
					return;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "\t\t                             选择出错，返回菜单！\n" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				}






				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请按任意键继续..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				_getch();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				adm_menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//点击了浏览
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //读取到内存中
				ppHead = ProjectFileRead(ppHead);//读取到内存中
				system("cls");
				char choice[10] = "0";;//查询的选择
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                        *******请选择您要浏览的对象：*******" << endl;
				cout << "\t\t                       *******      1-->浏览学院得分情况      *******" << endl;
				cout << "\t\t                      *******       2-->浏览项目排名情况       *******" << endl;
				cout << "\t\t                        *******     3-->返回菜单   *******" << endl;
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                     请输入您的选择(1-3):";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> choice;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				system("cls");

				if (strcmp(choice, "1") == 0)
				{
					PrintCollege(pHead);//浏览学院得分情况

				}
				else if (strcmp(choice, "2") == 0)
				{
					PrintProject(pHead, ppHead);//浏览项目排名情况
				}
				else if (strcmp(choice, "3") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
					cout << "返回菜单!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					system("cls");
					adm_menu();
					return;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "\t\t                             选择出错，返回菜单！\n" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请按任意键继续..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				_getch();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				adm_menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//点击了排序
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				pHead = CollegeFileRead(pHead); //读取到内存中
				ppHead = ProjectFileRead(ppHead);//读取到内存中
				system("cls");
				SortModule(pHead);

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				adm_menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//点击了设置
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				setting_menu();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				adm_menu();

			}
		}
		//
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);
			//点击了上级菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				log_in_menu();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 450 && m.y <= 480)
		{
			setlinecolor(RED);
			rectangle(385, 445, 595, 485);
			//返回主菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				menu();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
			}
		}
		else if (m.x >= 0 && m.x <= 100 && m.y >= 0 && m.y <= 30)
		{//
			setlinecolor(RED);
			rectangle(0, 0, 100, 30);
			//退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				exit(1);
				return;
			}
		}

		else
		{
			setlinecolor(WHITE);
			rectangle(385, 145, 595, 185);
			rectangle(385, 195, 595, 235);
			rectangle(385, 245, 595, 285);
			rectangle(385, 295, 595, 335);
			rectangle(385, 345, 595, 385);
			rectangle(385, 395, 595, 435);
			rectangle(385, 445, 595, 485);
			rectangle(0, 0, 100, 30);
		}
	}
	getchar();
	closegraph();
}

//系统设置菜单
void setting_menu()
{
	CollegeNode* pHead = NULL;
	ProjectNode* ppHead = NULL;
	system("cls");

	MOUSEMSG m;//定义鼠标变量 m
	//菜单
	//initgraph(1000, 500);
	initgraph(980, 500); //定义画布大小也就是黑框大小
	setbkcolor(0xAFEEEE);//设置背景颜色 用与RGB相对应的16进制代码表示
	cleardevice();//刷新一次 略等于那个system(cls) 用当前背景色清空屏幕
	setfillcolor(0x9AFF9A);//设置后面用函数画出方框的背景颜色
	//           左边1 高1 左边2 高2
	fillrectangle(390, 150, 590, 180);
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(390, 400, 590, 430);



	settextcolor(BLACK);//设置字体颜色为黑色
	settextstyle(45, 0, _T("楷体"));
	outtextxy(335, 70, _T("运动会计分系统"));//系统坐标

	settextstyle(15, 0, _T("楷体"));//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景
	outtextxy(440, 158, _T("系统初始化设置"));//没有初始化不能操作
	outtextxy(460, 208, _T("修改信息"));
	outtextxy(460, 258, _T("删除信息"));
	outtextxy(460, 308, _T("上级菜单"));
	outtextxy(460, 358, _T("切换用户"));
	outtextxy(460, 408, _T("退出系统"));

	while (1)
	{

		m = GetMouseMsg();

		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//如果点击了初始化设置
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				IntiInfo(pHead, ppHead);
				CollegeFileWrite(pHead);
				ProjectFileWrite(ppHead);
				cout << "已保存系统初始化设置!\n请按任意键继续..." << endl;
				_getch();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				setting_menu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//如果点击了修改
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //读取到内存中
				ppHead = ProjectFileRead(ppHead);//读取到内存中
				system("cls");
				CollegeModify(pHead, ppHead);

				CollegeFileWrite(pHead);
				ProjectFileWrite(ppHead);

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				setting_menu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//点击了删除
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				pHead = CollegeFileRead(pHead); //读取到内存中
				ppHead = ProjectFileRead(ppHead);//读取到内存中
				system("cls");
				CollegeNodeDel(pHead, ppHead);

				CollegeFileWrite(pHead);
				ProjectFileWrite(ppHead);

				system("cls");
				_getch();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				setting_menu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//点击了上级菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				adm_menu();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//点击了切换用户
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				log_in_menu();

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区

			}
		}
		//
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);
			//点击了退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				exit(1);
				//return;

			}
		}

		else {
			setlinecolor(WHITE);
			rectangle(385, 145, 595, 185);
			rectangle(385, 195, 595, 235);
			rectangle(385, 245, 595, 285);
			rectangle(385, 295, 595, 335);
			rectangle(385, 345, 595, 385);
			rectangle(385, 395, 595, 435);
		}
	}
	getchar();
	closegraph();
}

//用户菜单
void user_menu()
{
	CollegeNode* pHead = NULL;
	ProjectNode* ppHead = NULL;

	MOUSEMSG m;//定义鼠标变量 m
	initgraph(980, 500); //定义画布大小也就是黑框大小
	setbkcolor(0xAFEEEE);//设置背景颜色 用与RGB相对应的16进制代码表示
	cleardevice();//刷新一次 略等于那个system(cls) 用当前背景色清空屏幕
	setfillcolor(0x9AFF9A);//设置后面用函数画出方框的背景颜色

	//           左边1 高1 左边2 高2
	fillrectangle(390, 150, 590, 180);
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(390, 400, 590, 430);
	fillrectangle(0, 0, 70, 30);


	settextcolor(BLACK);//设置字体颜色为黑色
	settextstyle(45, 0, _T("楷体"));
	outtextxy(335, 70, _T("运动会计分系统"));//系统坐标

	settextstyle(15, 0, _T("楷体"));//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景
	outtextxy(460, 158, _T("查询成绩"));//没有初始化不能操作
	outtextxy(460, 208, _T("浏览成绩"));
	outtextxy(475, 258, _T("排序"));
	outtextxy(460, 308, _T("切换用户"));
	outtextxy(465, 358, _T("主菜单"));
	outtextxy(460, 408, _T("退出系统"));
	outtextxy(20, 8, _T("帮助"));



	while (1)
	{
		//获取鼠标消息
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//如果点击了查询成绩
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //读取到内存中
				ppHead = ProjectFileRead(ppHead);//读取到内存中
				system("cls");
				char choice[10] = "0";;//查询的选择
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                        *******请选择您要查询的对象：*******" << endl;
				cout << "\t\t                       *******      1-->查找学院      *******" << endl;
				cout << "\t\t                      *******       2-->查找项目       *******" << endl;
				cout << "\t\t                        *******     3-->返回菜单   *******" << endl;
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                     请输入您的选择(1-3):";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> choice;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				system("cls");

				if (strcmp(choice, "1") == 0)
				{
					CollegeSearch(pHead);
				}
				else if (strcmp(choice, "2") == 0)
				{
					ProjectSearch(ppHead, pHead);
				}
				else if (strcmp(choice, "3") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
					cout << "返回菜单!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					system("cls");
					user_menu();
					return;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "\t\t                             选择出错，返回菜单！\n" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				}


				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请按任意键继续..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				_getch();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				adm_menu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//如果点击了浏览成绩
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //读取到内存中
				ppHead = ProjectFileRead(ppHead);//读取到内存中
				system("cls");
				char choice[10] = "0";;//查询的选择
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                        *******请选择您要浏览的对象：*******" << endl;
				cout << "\t\t                       *******      1-->浏览学院得分情况      *******" << endl;
				cout << "\t\t                      *******       2-->浏览项目排名情况       *******" << endl;
				cout << "\t\t                        *******     3-->返回菜单   *******" << endl;
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                     请输入您的选择(1-3):";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> choice;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				system("cls");

				if (strcmp(choice, "1") == 0)
				{
					PrintCollege(pHead);//浏览学院得分情况

				}
				else if (strcmp(choice, "2") == 0)
				{
					PrintProject(pHead, ppHead);//浏览项目排名情况
				}
				else if (strcmp(choice, "3") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
					cout << "返回菜单!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					system("cls");
					adm_menu();
					return;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "\t\t                             选择出错，返回菜单！\n" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请按任意键继续..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				_getch();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				user_menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//点击了排序
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				pHead = CollegeFileRead(pHead); //读取到内存中
				ppHead = ProjectFileRead(ppHead);//读取到内存中
				system("cls");
				SortModule(pHead);

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				user_menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//点击了切换用户
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				log_in_menu();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//点击了主菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				menu();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区

			}
		}
		//
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);
			//点击了退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				exit(1);
				//return;

			}
		}

		else if (m.x >= 0 && m.x <= 70 && m.y >= 0 && m.y <= 30)
		{//
			setlinecolor(RED);
			rectangle(0, 0, 70, 30);
			//帮助
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				//exit(1);
				return;
			}
		}

		else {
			setlinecolor(WHITE);
			rectangle(385, 145, 595, 185);
			rectangle(385, 195, 595, 235);
			rectangle(385, 245, 595, 285);
			rectangle(385, 295, 595, 335);
			rectangle(385, 345, 595, 385);
			rectangle(385, 395, 595, 435);
			rectangle(0, 0, 70, 30);
		}
	}
	getchar();
	closegraph();

}
