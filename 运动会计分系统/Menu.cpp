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

//�˵�
void menu()
{
	MOUSEMSG m;//���������� m
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
	setbkcolor(0xAFEEEE);//���ñ�����ɫ ����RGB���Ӧ��16���ƴ����ʾ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls) �õ�ǰ����ɫ�����Ļ
	setfillcolor(0x9AFF9A);//���ú����ú�����������ı�����ɫ
	//           ���1 ��1 ���2 ��2
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(0, 0, 70, 30);

	settextcolor(BLACK);
	settextstyle(45, 0, _T("����"));
	outtextxy(335, 70, _T("�˶���Ʒ�ϵͳ"));//ϵͳ����

	settextstyle(15, 0, _T("����"));//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(475, 208, _T("��¼"));
	outtextxy(475, 258, _T("ע��"));
	outtextxy(475, 308, _T("�˳�"));
	outtextxy(20, 8, _T("����"));

	while (1)
	{
		//��ȡ�����Ϣ
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			//������ɫ�ľ��ο���
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//��¼
			if (m.uMsg == WM_LBUTTONDOWN) //�����������Ϣ
			{
				closegraph();
				//��¼
				log_in_menu();
				FlushMouseMsgBuffer();//��������Ϣ������
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//ע�� ע��ɹ�Ȼ����ת����¼��������˳�ϵͳ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				//ע�� ע��ɹ�Ȼ����ת����¼��������˳�ϵͳ
				FlushMouseMsgBuffer();//��������Ϣ������
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//�˳�ϵͳ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//��������Ϣ������
				exit(1);//�˳�ϵͳ
			}
		}
		else if (m.x >= 0 && m.x <= 70 && m.y >= 0 && m.y <= 30)
		{
			setlinecolor(RED);
			rectangle(0, 0, 70, 30);
			//��ȡ����
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				//�����ĵ�
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
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

//��¼�˵�
void log_in_menu()
{
	MOUSEMSG m;//���������� m
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
	setbkcolor(0xAFEEEE);//���ñ�����ɫ ����RGB���Ӧ��16���ƴ����ʾ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls) �õ�ǰ����ɫ�����Ļ
	setfillcolor(0x9AFF9A);//���ú����ú�����������ı�����ɫ
	//           ���1 ��1 ���2 ��2
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(0, 0, 70, 30);

	settextcolor(BLACK);
	settextstyle(45, 0, _T("����"));
	outtextxy(335, 70, _T("�˶���Ʒ�ϵͳ"));//ϵͳ����

	settextstyle(15, 0, _T("����"));//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(455, 208, _T("����Ա��¼"));
	outtextxy(460, 258, _T("�û���¼"));
	outtextxy(460, 308, _T("�˳�ϵͳ"));
	outtextxy(20, 8, _T("����"));

	while (1)
	{
		//��ȡ�����Ϣ
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			//������ɫ�ľ��ο���
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//����Ա��¼
			if (m.uMsg == WM_LBUTTONDOWN) //�����������Ϣ
			{
				closegraph();
				Password();
				FlushMouseMsgBuffer();//��������Ϣ������
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//�û���¼
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				Password();
				FlushMouseMsgBuffer();//��������Ϣ������
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//�˳�ϵͳ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//��������Ϣ������
				exit(1);//�˳�ϵͳ
			}
		}
		else if (m.x >= 0 && m.x <= 70 && m.y >= 0 && m.y <= 30)
		{
			setlinecolor(RED);
			rectangle(0, 0, 70, 30);
			//��ȡ����
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
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



//����Ա�˵�
void adm_menu()
{
	CollegeNode* pHead = NULL;
	ProjectNode* ppHead = NULL;
	system("cls");

	MOUSEMSG m;//���������� m
	//�˵�
	//initgraph(1000, 500);
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
	setbkcolor(0xAFEEEE);//���ñ�����ɫ ����RGB���Ӧ��16���ƴ����ʾ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls) �õ�ǰ����ɫ�����Ļ
	setfillcolor(0x9AFF9A);//���ú����ú�����������ı�����ɫ
	//           ���1 ��1 ���2 ��2
	fillrectangle(390, 150, 590, 180);
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(390, 400, 590, 430);
	fillrectangle(390, 450, 590, 480);
	fillrectangle(0, 0, 100, 30);


	settextcolor(BLACK);//����������ɫΪ��ɫ
	settextstyle(45, 0, _T("����"));
	outtextxy(335, 70, _T("�˶���Ʒ�ϵͳ"));//ϵͳ����

	settextstyle(15, 0, _T("����"));//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(460, 158, _T("����ɼ�"));//û�г�ʼ�����ܲ���
	outtextxy(460, 208, _T("��ѯ�ɼ�"));
	outtextxy(460, 258, _T("����ɼ�"));
	outtextxy(475, 308, _T("����"));
	outtextxy(460, 358, _T("ϵͳ����"));
	outtextxy(460, 408, _T("�ϼ��˵�"));
	outtextxy(465, 458, _T("���˵�"));
	outtextxy(20, 8, _T("�˳�ϵͳ"));

	while (1)
	{
		m = GetMouseMsg();

		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//������������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //��ȡ���ڴ���
				ppHead = ProjectFileRead(ppHead);//��ȡ���ڴ���
				system("cls");
				InputScore(ppHead, pHead);

				CollegeFileWrite(pHead);
				ProjectFileWrite(ppHead);

				FlushMouseMsgBuffer();//��������Ϣ������
				adm_menu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//�������˲�ѯ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //��ȡ���ڴ���
				ppHead = ProjectFileRead(ppHead);//��ȡ���ڴ���
				system("cls");
				char choice[10] = "0";;//��ѯ��ѡ��
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                        *******��ѡ����Ҫ��ѯ�Ķ���*******" << endl;
				cout << "\t\t                       *******      1-->����ѧԺ      *******" << endl;
				cout << "\t\t                      *******       2-->������Ŀ       *******" << endl;
				cout << "\t\t                        *******     3-->���ز˵�   *******" << endl;
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                     ����������ѡ��(1-3):";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> choice;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "���ز˵�!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					system("cls");
					adm_menu();
					return;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "\t\t                             ѡ��������ز˵���\n" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				}






				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�밴���������..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				_getch();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				adm_menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//��������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //��ȡ���ڴ���
				ppHead = ProjectFileRead(ppHead);//��ȡ���ڴ���
				system("cls");
				char choice[10] = "0";;//��ѯ��ѡ��
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                        *******��ѡ����Ҫ����Ķ���*******" << endl;
				cout << "\t\t                       *******      1-->���ѧԺ�÷����      *******" << endl;
				cout << "\t\t                      *******       2-->�����Ŀ�������       *******" << endl;
				cout << "\t\t                        *******     3-->���ز˵�   *******" << endl;
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                     ����������ѡ��(1-3):";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> choice;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				system("cls");

				if (strcmp(choice, "1") == 0)
				{
					PrintCollege(pHead);//���ѧԺ�÷����

				}
				else if (strcmp(choice, "2") == 0)
				{
					PrintProject(pHead, ppHead);//�����Ŀ�������
				}
				else if (strcmp(choice, "3") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "���ز˵�!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					system("cls");
					adm_menu();
					return;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "\t\t                             ѡ��������ز˵���\n" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�밴���������..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				_getch();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				adm_menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//���������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				pHead = CollegeFileRead(pHead); //��ȡ���ڴ���
				ppHead = ProjectFileRead(ppHead);//��ȡ���ڴ���
				system("cls");
				SortModule(pHead);

				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				adm_menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//���������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				setting_menu();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				adm_menu();

			}
		}
		//
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);
			//������ϼ��˵�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				log_in_menu();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 450 && m.y <= 480)
		{
			setlinecolor(RED);
			rectangle(385, 445, 595, 485);
			//�������˵�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				menu();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
			}
		}
		else if (m.x >= 0 && m.x <= 100 && m.y >= 0 && m.y <= 30)
		{//
			setlinecolor(RED);
			rectangle(0, 0, 100, 30);
			//�˳�ϵͳ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//��������Ϣ������
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

//ϵͳ���ò˵�
void setting_menu()
{
	CollegeNode* pHead = NULL;
	ProjectNode* ppHead = NULL;
	system("cls");

	MOUSEMSG m;//���������� m
	//�˵�
	//initgraph(1000, 500);
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
	setbkcolor(0xAFEEEE);//���ñ�����ɫ ����RGB���Ӧ��16���ƴ����ʾ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls) �õ�ǰ����ɫ�����Ļ
	setfillcolor(0x9AFF9A);//���ú����ú�����������ı�����ɫ
	//           ���1 ��1 ���2 ��2
	fillrectangle(390, 150, 590, 180);
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(390, 400, 590, 430);



	settextcolor(BLACK);//����������ɫΪ��ɫ
	settextstyle(45, 0, _T("����"));
	outtextxy(335, 70, _T("�˶���Ʒ�ϵͳ"));//ϵͳ����

	settextstyle(15, 0, _T("����"));//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(440, 158, _T("ϵͳ��ʼ������"));//û�г�ʼ�����ܲ���
	outtextxy(460, 208, _T("�޸���Ϣ"));
	outtextxy(460, 258, _T("ɾ����Ϣ"));
	outtextxy(460, 308, _T("�ϼ��˵�"));
	outtextxy(460, 358, _T("�л��û�"));
	outtextxy(460, 408, _T("�˳�ϵͳ"));

	while (1)
	{

		m = GetMouseMsg();

		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//�������˳�ʼ������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				IntiInfo(pHead, ppHead);
				CollegeFileWrite(pHead);
				ProjectFileWrite(ppHead);
				cout << "�ѱ���ϵͳ��ʼ������!\n�밴���������..." << endl;
				_getch();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				setting_menu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//���������޸�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //��ȡ���ڴ���
				ppHead = ProjectFileRead(ppHead);//��ȡ���ڴ���
				system("cls");
				CollegeModify(pHead, ppHead);

				CollegeFileWrite(pHead);
				ProjectFileWrite(ppHead);

				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				setting_menu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//�����ɾ��
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				pHead = CollegeFileRead(pHead); //��ȡ���ڴ���
				ppHead = ProjectFileRead(ppHead);//��ȡ���ڴ���
				system("cls");
				CollegeNodeDel(pHead, ppHead);

				CollegeFileWrite(pHead);
				ProjectFileWrite(ppHead);

				system("cls");
				_getch();
				FlushMouseMsgBuffer();//��������Ϣ������
				setting_menu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//������ϼ��˵�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				adm_menu();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//������л��û�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				log_in_menu();

				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������

			}
		}
		//
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);
			//������˳�ϵͳ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
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

//�û��˵�
void user_menu()
{
	CollegeNode* pHead = NULL;
	ProjectNode* ppHead = NULL;

	MOUSEMSG m;//���������� m
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
	setbkcolor(0xAFEEEE);//���ñ�����ɫ ����RGB���Ӧ��16���ƴ����ʾ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls) �õ�ǰ����ɫ�����Ļ
	setfillcolor(0x9AFF9A);//���ú����ú�����������ı�����ɫ

	//           ���1 ��1 ���2 ��2
	fillrectangle(390, 150, 590, 180);
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(390, 400, 590, 430);
	fillrectangle(0, 0, 70, 30);


	settextcolor(BLACK);//����������ɫΪ��ɫ
	settextstyle(45, 0, _T("����"));
	outtextxy(335, 70, _T("�˶���Ʒ�ϵͳ"));//ϵͳ����

	settextstyle(15, 0, _T("����"));//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(460, 158, _T("��ѯ�ɼ�"));//û�г�ʼ�����ܲ���
	outtextxy(460, 208, _T("����ɼ�"));
	outtextxy(475, 258, _T("����"));
	outtextxy(460, 308, _T("�л��û�"));
	outtextxy(465, 358, _T("���˵�"));
	outtextxy(460, 408, _T("�˳�ϵͳ"));
	outtextxy(20, 8, _T("����"));



	while (1)
	{
		//��ȡ�����Ϣ
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//�������˲�ѯ�ɼ�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //��ȡ���ڴ���
				ppHead = ProjectFileRead(ppHead);//��ȡ���ڴ���
				system("cls");
				char choice[10] = "0";;//��ѯ��ѡ��
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                        *******��ѡ����Ҫ��ѯ�Ķ���*******" << endl;
				cout << "\t\t                       *******      1-->����ѧԺ      *******" << endl;
				cout << "\t\t                      *******       2-->������Ŀ       *******" << endl;
				cout << "\t\t                        *******     3-->���ز˵�   *******" << endl;
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                     ����������ѡ��(1-3):";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> choice;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "���ز˵�!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					system("cls");
					user_menu();
					return;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "\t\t                             ѡ��������ز˵���\n" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				}


				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�밴���������..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				_getch();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				adm_menu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//������������ɼ�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				pHead = CollegeFileRead(pHead); //��ȡ���ڴ���
				ppHead = ProjectFileRead(ppHead);//��ȡ���ڴ���
				system("cls");
				char choice[10] = "0";;//��ѯ��ѡ��
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                        *******��ѡ����Ҫ����Ķ���*******" << endl;
				cout << "\t\t                       *******      1-->���ѧԺ�÷����      *******" << endl;
				cout << "\t\t                      *******       2-->�����Ŀ�������       *******" << endl;
				cout << "\t\t                        *******     3-->���ز˵�   *******" << endl;
				cout << "\t\t                           ******************************" << endl;
				cout << "\t\t                     ����������ѡ��(1-3):";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> choice;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				system("cls");

				if (strcmp(choice, "1") == 0)
				{
					PrintCollege(pHead);//���ѧԺ�÷����

				}
				else if (strcmp(choice, "2") == 0)
				{
					PrintProject(pHead, ppHead);//�����Ŀ�������
				}
				else if (strcmp(choice, "3") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "���ز˵�!" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					system("cls");
					adm_menu();
					return;
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "\t\t                             ѡ��������ز˵���\n" << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�밴���������..." << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				_getch();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				user_menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//���������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				pHead = CollegeFileRead(pHead); //��ȡ���ڴ���
				ppHead = ProjectFileRead(ppHead);//��ȡ���ڴ���
				system("cls");
				SortModule(pHead);

				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				user_menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//������л��û�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				log_in_menu();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//��������˵�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				menu();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������

			}
		}
		//
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);
			//������˳�ϵͳ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				exit(1);
				//return;

			}
		}

		else if (m.x >= 0 && m.x <= 70 && m.y >= 0 && m.y <= 30)
		{//
			setlinecolor(RED);
			rectangle(0, 0, 70, 30);
			//����
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				FlushMouseMsgBuffer();//��������Ϣ������
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
