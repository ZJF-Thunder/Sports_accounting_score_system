#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <Windows.h>
#include "Password.h"
#include "Menu.h"
#include "Project.h"
using namespace std;

int Judge_Password()
{
    char inp[20];
    char p[20];
    FILE* fp = NULL;
    fp = fopen("password.txt", "r+");
    fscanf(fp, "%s", inp);
    if (strcmp(inp, "******") == 0)      //����ԭʼ����
    {
        printf("�������ʼ���룺(�15λ)");
        cin >> inp;
        fprintf(fp, "%s", inp);
        fclose(fp);
        cout << endl;
        system("cls");
        return 1;
    }
    else
    {
        printf("���������룺");
        cin >> p;
        if (strcmp(p, inp + 6) == 0)
        {
            fclose(fp);
            system("cls");
            return 1;
        }
        else
        {
            printf("�������!\n");
            fclose(fp);
            system("cls");
            return 0;
        }
    }
}


int Password()
{
    char id[20] = { '0' };    //����Աor�û�
    printf("\t\t����Ա(admin)\n\t\t�û�(user)\n");
    printf("\t\t�����԰�Q�˳�\n\n\t\t�������û�����\n");
    while (cin >> id)
    {
        if (strcmp(id, "admin") == 0)
        {
            while (!Judge_Password());
            system("cls");
            adm_menu();
        }
        else if (strcmp(id, "user") == 0)
        {
            system("cls");
            user_menu();
        }
        else if (strcmp(id, "Q") == 0)
        {
            exit(0);
        }
        else
        {
            printf("�������\n");
        }
    }
}
