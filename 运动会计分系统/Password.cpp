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
    if (strcmp(inp, "******") == 0)      //输入原始密码
    {
        printf("请输入初始密码：(最长15位)");
        cin >> inp;
        fprintf(fp, "%s", inp);
        fclose(fp);
        cout << endl;
        system("cls");
        return 1;
    }
    else
    {
        printf("请输入密码：");
        cin >> p;
        if (strcmp(p, inp + 6) == 0)
        {
            fclose(fp);
            system("cls");
            return 1;
        }
        else
        {
            printf("密码错误!\n");
            fclose(fp);
            system("cls");
            return 0;
        }
    }
}


int Password()
{
    char id[20] = { '0' };    //管理员or用户
    printf("\t\t管理员(admin)\n\t\t用户(user)\n");
    printf("\t\t您可以按Q退出\n\n\t\t请输入用户名：\n");
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
            printf("输入错误！\n");
        }
    }
}
