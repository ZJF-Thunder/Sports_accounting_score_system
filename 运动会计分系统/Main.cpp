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

    initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
    IMAGE img;
    loadimage(&img, _T("����.jpg"), 980, 500);
    putimage(0, 0, &img);    // ����һ���ط��ٴ���ʾ����
    setbkmode(TRANSPARENT);
    settextstyle(40, 0, _T("����"));
    settextcolor(0x9AFF9A);//��ȡ��ǰ������ɫ
    outtextxy(330, 220, _T("�˶���Ʒ�ϵͳ"));//��������
    _getch();        // ��������˳�
    FlushMouseMsgBuffer();//��������Ϣ������
    closegraph();    // �ر�ͼƬ

    system("color B0");   //���ñ�������������ɫ
    menu();
    //system("pause");
    return 0;
}
