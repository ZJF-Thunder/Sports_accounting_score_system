#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <Graphics.h>
#include <easyx.h>
#include <conio.h>
#include <Windows.h>
#include "Project.h"
#include "Menu.h"
#include "Password.h"
using namespace std;

int main()
{

    initgraph(980, 500); //定义画布大小也就是黑框大小
    IMAGE img;
    loadimage(&img, _T("背景.jpg"), 980, 500);
    putimage(0, 0, &img);    // 在另一个地方再次显示背景
    setbkmode(TRANSPARENT);
    settextstyle(40, 0, _T("黑体"));
    settextcolor(0x9AFF9A);//获取当前文字颜色
    outtextxy(330, 220, _T("运动会计分系统"));//超市坐标
    _getch();        // 按任意键退出
    FlushMouseMsgBuffer();//清空鼠标消息缓存区
    closegraph();    // 关闭图片

    system("color B0");   //设置背景及其字体颜色
    menu();
    //system("pause");
    return 0;
}
