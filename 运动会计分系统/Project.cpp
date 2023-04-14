//#pragma warning (disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>//用到setw()函数
#include <windows.h>//控制台编程主要头文件
#include<conio.h>//_getch()
#include "Project.h"
#include "Menu.h"
using namespace std;


//获取字符
char GetChar()
{
    char ch = getchar();
    fflush(stdin);
    return ch;
}


//数字范围检验
int CheckNum(int* num, int max, int min)
{
    do
    {
        *num = min - 1;
        cin >> *num;
        while (getchar() != '\n');
        if (*num > max || *num < min)
        {
            printf("输入有误,请重新输入[%d--%d]:", min, max);
        }
    } while (*num > max || *num < min);
    return *num;
}



//信息初始化操作 个数和名称 三还是五 男还是女
void IntiInfo(CollegeNode*& pHead, ProjectNode*& ppHead)
{
    CollegeNode* p1 = NULL;
    ProjectNode* p2 = NULL;
    int id_c = 1;//学院编号
    int id_p = 1;//项目编号
    int num_c = 0; // 需要输入的学院个数
    int num_p = 0; // 需要输入的项目个数
    if (pHead == NULL)
    {
        printf("\t录入学院个数<5 - 15>\n\t: ");
        num_c = CheckNum(&num_c, 15, 5);
    }
    else
    {
        printf("\t录入学院个数<0 - 15>\n\t: ");
        num_c = CheckNum(&num_c, 15, 0);
        if (num_c == 0)
        {
            cout << "\t未添加学院!请确定是否要添加！" << endl;
            return;
        }
    }
    printf("\t录入项目个数<1 - 10>\n\t: ");
    num_p = CheckNum(&num_p, 10, 1);
    system("cls");


    for (int i = 0; i < num_c; i++)
    {
        GetCollegeNode(pHead, p1, id_c);
    }
    system("cls");
    for (int i = 0; i < num_p; i++)
    {
        GetProjectNode(ppHead, p2, id_p);
        system("cls");
    }
}

//链表操作
CollegeNode* GetCollegeNode(CollegeNode*& pHead, CollegeNode*& p, int& id_c)
{
    CollegeNode* node = NULL;
    node = new CollegeNode;
    printf("\t输入第%d个学院的名称: ", id_c);
    node->college_id = id_c++;//学院编号跟随变量id_s变化
    while (1)
    {
        cin >> node->college_name;
        if (node->college_name[0] == '\0')
        {
            printf("\t输入为空，请重新输入:");
        }
        else
        {
            break;
        }
    }
    //初始化
    node->man_score = 0;//男团得分
    node->woman_score = 0;//女团得分
    node->college_score = 0;//学院总得分
    node->next = NULL;
    if (pHead == NULL)
    {
        pHead = node;
        p = node;
    }
    else
    {
        p->next = node;
        p = node;
    }
    return p;
}
ProjectNode* GetProjectNode(ProjectNode*& ppHead, ProjectNode*& p, int& id_p)
{
    ProjectNode* node = NULL;
    node = new ProjectNode;
    printf("\t输入第%d个项目的名称: ", id_p);
    node->project_id = id_p++;
    while (1)
    {
        cin >> node->project_name;
        if (node->project_name[0] == '\0')
        {
            printf("\t输入为空，请重新输入:");
        }
        else {
            break;
        }
    }

    printf("\t男子（男）/女子（女）: ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
    cout << "项目性别:";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
    cin >> node->sex;
    while (strcmp(node->sex, "男") != 0 && strcmp(node->sex, "女") != 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
        cout << "非法输入！请重新输入:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
        cin >> node->sex;
    }

    while (1)
    {
        if (strcmp(node->sex, "女") == 0)
        {
            printf("\t女子%s", node->project_name);
        }
        else
        {
            printf("\t男子%s", node->project_name);
        }

        printf("项目录入: 3:前三名 5:前五名: ");
        int power = 0;
        fflush(stdin);
        scanf("%d", &power);
        fflush(stdin);
        if (power == 3)
        {
            node->power = power;
            break;
        }
        else if (power == 5)
        {
            node->power = power;
            break;
        }
        else {
            printf("于{3，5}中选择！");
        }
    }
    node->next = NULL;
    if (ppHead == NULL)
    {
        ppHead = node;
    }
    else
    {
        p->next = node;
    }
    p = node;
    return p;
}


//输入获得前三名或者前五名的学院 输入成绩
void InputScore(ProjectNode* pNode, CollegeNode* pHead)
{
    if (pNode == NULL)
    {
        cout << "不存在项目" << endl;
    }

    int count = 0; //学院的个数
    CollegeNode* p = pHead;
    while (p)
    {
        count++;
        p = p->next;
    }
    /*p = pHead;
    system("cls");
    while (p)
    {
        //输出显示
        printf("%d.%-20s", p->college_id, p->college_name);
        p = p->next;
    }*/
    while (pNode)
    {
        p = pHead;
        system("cls");
        while (p)
        {
            //输出显示
            printf("%d.%-20s", p->college_id, p->college_name);
            p = p->next;
        }

        printf("\n\n获得  %s项目\t前%d名<填写编号 1 - %d>:\n", pNode->project_name, pNode->power, count);
        int num = 1;
        for (int i = 0; i < pNode->power; i++)
        {
            printf("第%d名的学校: ", i + 1); //这里要设置一个同样的数字不能输入多次
            int choose = CheckNum(&choose, count, 1);
            pNode->College[i] = choose;
            AddCollegeScore(pHead, pNode, choose, num);
            cout << "该学院项目计分完成!" << endl;
            num++;
        }
        printf("\n");
        pNode = pNode->next;
    }

}


//修改函数 修改名次，修改学院名称 修改项目名称 修改获奖名次
int CollegeModify(CollegeNode* head, ProjectNode* pNode)
{

    char college_name[20];//学院名称
    char project_name[20];//项目名称
    CollegeNode* p = NULL;//学院修改指针
    ProjectNode* p2 = NULL;//项目修改指针
    int i = 0;//结点位置
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
    cout << "\t\t                           ******************************" << endl;
    cout << "\t\t                        *******请选择您要修改的对象：*******" << endl;
    cout << "\t\t                       *******      1-->修改学院信息    *******" << endl;
    cout << "\t\t                       *******      2-->修改项目信息    *******" << endl;
    cout << "\t\t                        *******     3-->返回主菜单   *******" << endl;
    cout << "\t\t                           ******************************" << endl;
    cout << "\t\t                      请输入您的选择(1-3):";
    char b[10] = "0";//确认误操作变量
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
    cin >> b;
    while (strcmp(b, "1") != 0 && strcmp(b, "2") != 0 && strcmp(b, "3") != 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
        cout << "输入错误，请重新输入:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
        cin >> b;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
    if (strcmp(b, "1") == 0)//修改学院
    {
        cout << "请输入你需要修改学院名称：";
        cin >> college_name;
        system("cls");
        if (head == NULL)//如果是空链表
        {
            cout << "无学院信息！" << endl;
            CollegeModify(head, pNode);
        }
        p = head;
        while (p != NULL && strcmp(college_name, p->college_name) != 0)
        {
            p = p->next;
            i++;
        }
        if (p == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
            cout << "\t\t        该学院不存在!" << endl;
            CollegeModify(head, pNode);
        }
        else
        {
            printf("\t学院编号(名称)\t\t团体总分\t男团总分\t女团总分\n");

            printf("\t%d", p->college_id);
            printf(".%-15s\t", p->college_name);
            printf("%-3d\t\t", p->college_score);
            printf("%-3d\t\t", p->man_score);
            printf("%-3d\n", p->woman_score);

            cout << "修改前学院名称：" << p->college_name << endl;
            cout << "请输入学院名称:";
            cin >> p->college_name;

            system("pause");
            cout << "\t\t                           **********************" << endl;
            cout << "\t\t                        *******是否继续修改：*******" << endl;
            cout << "\t\t                       *******    1-->是      *******" << endl;
            cout << "\t\t                        *******   2-->否     *******" << endl;
            cout << "\t\t                           **********************" << endl;
            cout << "\t\t                       请输入您的选择(1-2):";
            char f[5];
            cin >> f;
            system("cls");
            if (strcmp(f, "1") == 0)
            {
                CollegeModify(head, pNode);
            }
            else if (strcmp(f, "2") == 0)
            {
                return 0;
            }
            else
            {
                cout << "输入错误！请重新输入!" << endl;
            }
        }

    }

    else if (strcmp(b, "2") == 0)//修改项目
    {
        cout << "请输入你需要修改项目名称：";
        cin >> project_name;
        system("cls");
        if (pNode == NULL)//如果是空链表
        {
            cout << "无项目信息！" << endl;
            CollegeModify(head, pNode);
        }
        p2 = pNode;
        while (p2 != NULL && strcmp(project_name, p2->project_name) != 0)
        {
            p2 = p2->next;
            i++;
        }
        if (p2 == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
            cout << "\t\t        该项目不存在!" << endl;
            CollegeModify(head, pNode);
        }
        else
        {
            printf("——————————————————————————————————————————————————————————————\n");
            printf("\t\t比赛项目:%s", p2->project_name);

            if (strcmp(p2->sex, "男") == 0)
            {
                printf("\t<男子> 只录入前%d名\n\n", p2->power);
            }
            else
            {
                printf("\t<女子> 只录入前%d名\n\n", p2->power);
            }
            for (int i = 0; i < p2->power; i++)
            {
                CollegeNode* mark = head;
                while (mark)
                {
                    if (p2->College[i] == mark->college_id)
                    {
                        printf("\t第%d名:%-15s", i + 1, mark->college_name);
                    }
                    mark = mark->next;
                }
            }
            printf("\n\n");

            printf("修改1.项目名称\t2.前几名\t3.性别4.修改获奖学院\t\t\n");
            char g[10] = "0";
            cin >> g;
            system("cls");

            if (strcmp(g, "1") == 0)
            {
                cout << "修改前项目名称：" << p2->project_name << endl;
                cout << "请输入项目名称:";
                cin >> p2->project_name;

            }
            else if (strcmp(g, "2") == 0)
            {
                cout << "修改前前几名：" << p2->power << endl;
                cout << "请输入前几名:";
                cin >> p2->power;
                int count = 0;
                CollegeNode* p3 = head;
                while (p3)
                {
                    count++;
                    p3 = p3->next;
                }
                p3 = head;
                system("cls");
                while (p3)
                {
                    //输出显示
                    printf("%d.%-20s", p3->college_id, p3->college_name);
                    p3 = p3->next;
                }
                printf("\n\n获得  %s项目\t前%d名<填写编号 1 - %d>:\n", pNode->project_name, pNode->power, count);
                int num = 1;
                for (int i = 0; i < p2->power; i++)
                {
                    printf("第%d名的学校: ", i + 1); //这里要设置一个同样的数字不能输入多次
                    int choose = CheckNum(&choose, count, 1);
                    pNode->College[i] = choose;
                    AddCollegeScore(head, pNode, choose, num);
                    cout << "该学院项目计分完成!" << endl;
                    num++;
                }
            }
            else if (strcmp(g, "3") == 0)
            {
                cout << "修改前性别：" << p2->sex << endl;
                cout << "请输入性别:";
                cin >> p2->sex;
            }
            else if (strcmp(g, "4") == 0)
            {
                int count = 0;
                CollegeNode* p3 = head;
                while (p3)
                {
                    count++;
                    p3 = p3->next;
                }
                p3 = head;
                system("cls");
                while (p3)
                {
                    //输出显示
                    printf("%d.%-20s", p3->college_id, p3->college_name);
                    p3 = p3->next;
                }
                printf("\n\n获得  %s项目\t前%d名<填写编号 1 - %d>:\n", pNode->project_name, pNode->power, count);
                int num = 1;
                for (int i = 0; i < pNode->power; i++)
                {
                    printf("第%d名的学校: ", i + 1); //这里要设置一个同样的数字不能输入多次
                    int choose = CheckNum(&choose, count, 1);
                    pNode->College[i] = choose;
                    AddCollegeScore(head, pNode, choose, num);
                    cout << "该学院项目计分完成!" << endl;
                    num++;
                }
            }

            else
            {
                cout << "输入错误" << endl;
            }
            system("pause");
            cout << "\t\t                           **********************" << endl;
            cout << "\t\t                        *******是否继续修改：*******" << endl;
            cout << "\t\t                       *******    1-->是      *******" << endl;
            cout << "\t\t                        *******   2-->否     *******" << endl;
            cout << "\t\t                           **********************" << endl;
            cout << "\t\t                       请输入您的选择(1-2):";
            char f[5];
            cin >> f;
            system("cls");
            if (strcmp(f, "1") == 0)
            {
                CollegeModify(head, pNode);
            }
            else if (strcmp(f, "2") == 0)
            {
                return 0;
            }
            else
            {
                cout << "输入错误！请重新输入!" << endl;
            }
        }

    }

    else if (strcmp(b, "3") == 0)
    {
        return 0;
    }

}


//删除函数 删除学院，删除项目
int CollegeNodeDel(CollegeNode*& head, ProjectNode*& pNode)
{
    CollegeNode* q = NULL;
    CollegeNode* p = head;
    ProjectNode* r = NULL;
    ProjectNode* s = pNode;
    int i = 0;//用于遍历找到所查询信息位置
    int k = 0;//用于判断是否有此对象
    char college_name[20];//需要删除的学院名称
    char project_name[20];
    char choose[10] = "0";//定义一个选择字符
    cout << "\t\t                           *****************************" << endl;
    cout << "\t\t                          *******   请选择删除对象:  *******" << endl;
    cout << "\t\t                        *******     1-->删除学院    *******" << endl;
    cout << "\t\t                       *******      2-->删除项目     *******" << endl;
    cout << "\t\t                      *******       3-->返回主菜单      *******" << endl;
    cout << "\t\t                           *****************************" << endl;
    cout << "\t\t                      请输入您的选择（1-3）:";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
    cin >> choose;
    while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0 && strcmp(choose, "3") != 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
        cout << "\t\t                   输入错误，请重新输入（1-3）:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
        cin >> choose;
    }
    if (strcmp(choose, "1") == 0)
    {
        i = 0;
        k = 0;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
        cout << "\t\t  请输入你需要删除的学院名称:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
        cin >> college_name;//输入需要删除的学院名称
        while (p != NULL)
        {
            i++;//记录位置，用于删除与数据信息相等的数据
            if (strcmp(college_name, p->college_name) == 0)//判断与要删除的数据信息是否相等
            {
                int j = 1;
                if (i == 1)//需删除数据是第一个时
                {
                    head = p->next;
                    i--;//删除后记录位置减一，便于之后删除位置的正确
                }
                else
                {
                    q = head;
                    while (q != NULL)
                    {
                        if (j + 1 == i)//需删除位置的前一位
                        {
                            if (q->next->next != NULL)
                            {
                                q->next = q->next->next;
                                i--;//删除后记录位置减一，便于之后删除位置的正确
                            }
                            else
                            {
                                q->next = NULL;
                            }
                        }
                        q = q->next;
                        j++;//记录q指针指向位置，便于与i对比找到需进行操作的地方
                    }
                }
                k++;//判断是否有所删除信息存在
            }
            p = p->next;
        }
        if (k == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
            cout << "\t\t                       *************     该学院不存在！   *************" << endl;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
            cout << "\t\t           *************       成功删除名称为" << college_name << "的" << k << "个学院信息！      *************" << endl;
        }
    }
    else if (strcmp(choose, "2") == 0)
    {
        i = 0;
        k = 0;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
        cout << "\t\t  请输入你需要删除的项目名称:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
        cin >> project_name;//输入需要删除的项目名称
        while (s != NULL)
        {
            i++;//记录位置，用于删除与数据信息相等的数据
            if (strcmp(project_name, s->project_name) == 0)//判断与要删除的数据信息是否相等
            {
                int j = 1;
                if (i == 1)//需删除数据是第一个时
                {
                    pNode = s->next;
                    i--;//删除后记录位置减一，便于之后删除位置的正确
                }
                else
                {
                    r = pNode;
                    while (q != NULL)
                    {
                        if (j + 1 == i)//需删除位置的前一位
                        {
                            if (r->next->next != NULL)
                            {
                                r->next = r->next->next;
                                i--;//删除后记录位置减一，便于之后删除位置的正确
                            }
                            else
                            {
                                r->next = NULL;
                            }
                        }
                        r = r->next;
                        j++;//记录q指针指向位置，便于与i对比找到需进行操作的地方
                    }
                }
                k++;//判断是否有所删除信息存在
            }
            s = s->next;
        }
        if (k == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
            cout << "\t\t                       *************     该项目不存在！   *************" << endl;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
            cout << "\t\t           *************       成功删除名称为" << project_name << "的" << k << "个项目信息！      *************" << endl;
        }
    }
    else if (strcmp(choose, "3") == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
        return 0;
    }

    char choi[10] = "0";
    i = 0; //用于判断在选择是否继续查找时，选择是否出错
    while (strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
    {
        if (i > 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            cout << "\t\t                                     非法输入！请重新输入！" << endl;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
        cout << "\t\t                              ********************************" << endl;
        cout << "\t\t                           *******    是否继续删除商品？  *******" << endl;
        cout << "\t\t                          *******       Y-->继续删除       *******" << endl;
        cout << "\t\t                           *******      N-->返回主菜单    *******" << endl;
        cout << "\t\t                              ********************************" << endl;
        cout << "\t\t                          请输入您的选择(Y or N):";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
        cin >> choi;
        system("cls");
        if (strcmp(choi, "N") == 0 || strcmp(choi, "n") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
            break;
        }
        else if (strcmp(choi, "y") == 0 || strcmp(choi, "Y") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
            CollegeNodeDel(head, pNode);

        }
        i++;
    }

}

//查询学院 模糊查找
int CollegeSearch(CollegeNode* head)
{
    char college_name[20];

    printf("请输入查询的学院名称:");
    cin >> college_name;

    CollegeNode* p = NULL;//p是查找位置
    int i = 0;//位置序号
    if (head == NULL)//如果是空链表
    {
        cout << "\t\t        无学院信息！" << endl;
        return -1;//表示此时链表为空
    }

    p = head;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
    int j = 0;
    for (p = head; p != NULL; p = p->next)
    {
        char* s = NULL;
        s = strstr(p->college_name, college_name);
        if (s != NULL)
        {
            if (i == 0)
            {
                printf("\t学院编号(名称)\t\t团体总分\t男团总分\t女团总分\n");
                i++;
            }
            printf("\t%d", p->college_id);
            printf(".%-15s\t", p->college_name);
            printf("%-3d\t\t", p->college_score);
            printf("%-3d\t\t", p->man_score);
            printf("%-3d\n", p->woman_score);
            j++;
        }
    }

    if (j == 0)
    {
        cout << "\t\t        没有该名称的学院！" << endl;
        _getch();
    }
    return 0;

}

//查询项目
int ProjectSearch(ProjectNode* head, CollegeNode* chead)
{
    char project_name[20];

    printf("请输入查询的项目名称:");
    cin >> project_name;

    ProjectNode* p = NULL;//p是查找位置
    int i = 0;//位置序号
    if (head == NULL)//如果是空链表
    {
        cout << "无项目信息！" << endl;
    }

    p = head;
    while (p != NULL && strcmp(project_name, p->project_name) != 0)
    {
        p = p->next;
        i++;
    }

    if (p == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
        cout << "\t\t        该项目不存在!" << endl;
    }
    else
    {
        printf("——————————————————————————————————————————————————————————————\n");
        printf("\t\t比赛项目:%s", p->project_name);

        if (strcmp(p->sex, "男") == 0)
        {
            printf("\t<男子> 只录入前%d名\n\n", p->power);
        }
        else
        {
            printf("\t<女子> 只录入前%d名\n\n", p->power);
        }
        for (int i = 0; i < p->power; i++)
        {
            CollegeNode* mark = chead;
            while (mark)
            {
                if (p->College[i] == mark->college_id)
                {
                    printf("\t第%d名:%-15s", i + 1, mark->college_name);
                }
                mark = mark->next;
            }
        }
        printf("\n");
    }
    return 0;

}


//计分函数
void AddCollegeScore(CollegeNode* pHead, ProjectNode* pNode, int id, int sort)
{
    int grade_3[3] = { 5, 3, 2 };
    int grade_5[5] = { 7, 5, 3, 2, 1 };
    CollegeNode* mark = pHead;
    while (mark)
    {
        if (mark->college_id == id)
        {
            if (strcmp(pNode->sex, "男") == 0 && pNode->power == 3)
            {
                mark->man_score += grade_3[sort - 1];
                mark->college_score += grade_3[sort - 1];
            }
            else if (strcmp(pNode->sex, "男") == 0 && pNode->power == 5)
            {
                mark->man_score += grade_5[sort - 1];
                mark->college_score += grade_5[sort - 1];
            }
            else if (strcmp(pNode->sex, "女") == 0 && pNode->power == 3)
            {
                mark->woman_score += grade_3[sort - 1];
                mark->college_score += grade_3[sort - 1];
            }
            else if (strcmp(pNode->sex, "女") == 0 && pNode->power == 5)
            {
                mark->woman_score += grade_5[sort - 1];
                mark->college_score += grade_5[sort - 1];
            }
        }
        mark = mark->next;
    }
}


//输出总分排序后的数据  排序模块
void SortModule(CollegeNode*& pHead)
{
    if (pHead == NULL)
    {
        printf("\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\t");
        printf("\t\t当前未录入数据  请管理员输入数据！\n");
        printf("\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\t");
        return;
    }
    int g_menu = 0;
    cout << "\t\t            ************************************************************************" << endl;
    cout << "\t\t           ********************          请选择排序依据:         ********************" << endl;
    cout << "\t\t          ********************         1-->按照男团降序排列       ********************" << endl;
    cout << "\t\t         ********************          2-->按照女团降序排列        ********************" << endl;
    cout << "\t\t         ********************          3-->按照学院总分降序排列    ********************" << endl;
    cout << "\t\t          ********************         4-->返回主菜单   ********************" << endl;
    cout << "\t\t            ***********************************************************************" << endl;
    cout << "\t\t         请输入您的选择（1-4）:";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
    cin >> g_menu;
    while (g_menu != 1 && g_menu != 2 && g_menu != 3 && g_menu != 4)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
        cout << "\t\t                    输入错误，请重新输入（1-4）:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
        cin >> g_menu;
    }
    system("cls");//清屏

    switch (g_menu)
    {
    case 1:
        printf("\t\t按照男团降序排列：\n");
        ManScoreSort(pHead);
        break;
    case 2:
        printf("\t\t按照女团降序排列：\n");
        WomanScoreSort(pHead);
        break;
    case 3:
        printf("\t\t按照学院总分降序排列：\n");
        SchoolScoreSort(pHead);
        break;
    case 4:
        return;
        break;

    }

    printf("———————————————————————————————————————————————————————————\n");
    printf("\t学院编号(名称)\t\t团体总分\t男团总分\t女团总分\n");
    while (pHead)
    {
        printf("\t%d.%-15s", pHead->college_id, pHead->college_name);
        printf("\t%-3d\t\t%-3d\t\t%-3d\n", pHead->college_score, pHead->man_score, pHead->woman_score);
        pHead = pHead->next;
    }
    printf("———————————————————————————————————————————————————————————\n");

    char choi[10] = "0";
    int i = 0; //用于判断在选择是否继续查找时，选择是否出错
    while (strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
    {
        if (i > 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            cout << "\t\t                                     非法输入！请重新输入！" << endl;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
        cout << "\t\t                              ********************************" << endl;
        cout << "\t\t                           *******  是否继续查看学院排序？*******" << endl;
        cout << "\t\t                          *******       Y-->继续查看       *******" << endl;
        cout << "\t\t                           *******      N-->返回主菜单    *******" << endl;
        cout << "\t\t                              ********************************" << endl;
        cout << "\t\t                          请输入您的选择(Y or N):";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
        cin >> choi;
        if (strcmp(choi, "N") == 0 || strcmp(choi, "n") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
            return;
        }
        else if (strcmp(choi, "y") == 0 || strcmp(choi, "Y") == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
            SortModule(pHead);
        }
        i++;
    }
}


//男子成绩排序 冒泡排序
void ManScoreSort(CollegeNode*& pHead)
{
    if (pHead == NULL)
    {
        printf("\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\t");
        printf("\t\t当前未录入数据  请管理员输入数据！\n");
        printf("\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\t");
        return;
    }

    CollegeNode* mark = pHead;
    int count = 0;
    while (mark)
    {
        count++;
        mark = mark->next;
    }
    CollegeNode* pri, * mid, * tai, * p;
    while (count--)
    {
        mid = pHead->next;
        if (pHead->man_score < pHead->next->man_score)
        {
            pHead->next = mid->next;
            mid->next = pHead;
            pHead = mid;
        }
        pri = pHead;
        mid = pHead->next;
        tai = mid->next;
        while (mid->next != NULL)
        {
            if (mid->man_score < tai->man_score)
            {
                pri->next = mid->next;
                mid->next = tai->next;
                tai->next = mid;
            }
            pri = pri->next;
            mid = pri->next;
            tai = mid->next;
        }
    }
}

//女子成绩排序 直接插入排序
void WomanScoreSort(CollegeNode*& pHead)
{
    if (pHead == NULL)
    {
        printf("\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\t");
        printf("\t\t当前未录入数据  请管理员输入数据！\n");
        printf("\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\t");
        return;
    }
    CollegeNode* q = NULL;
    CollegeNode* p = NULL;
    CollegeNode* k = NULL;
    CollegeNode* r = NULL;
    q = new CollegeNode;//为结点分配内存单元
    q->next = pHead;//q的下一节点指向头结点
    pHead = q;//将头结点设为空
    p = pHead->next->next;//用指针p保存下未排序元素的信息
    pHead->next->next = NULL;//使用原链表构造有序区，当前仅有一个元素
    while (p != NULL)//遍历无序区
    {
        k = p->next;//保存位置
        r = pHead;//用指针指向有序区
        while (r->next != NULL && r->next->woman_score > p->woman_score)//判断指针指向的下一个元素与无序区取出元素的大小
        {
            r = r->next;
        }
        p->next = r->next;//插入操作
        r->next = p;
        p = k;//将p值回复，指向无序区下一个节点
    }
    pHead = pHead->next;//去掉一开始加入的空数据
    delete q;

}

//学院总分排序 冒泡排序
void SchoolScoreSort(CollegeNode*& pHead)
{
    if (pHead == NULL)
    {
        printf("\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\t");
        printf("\t\t当前未录入数据  请管理员输入数据！\n");
        printf("\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\t");
        return;
    }
    CollegeNode* mark = pHead;
    int count = 0;
    while (mark)
    {
        count++;
        mark = mark->next;
    }
    CollegeNode* pri, * mid, * tai, * p;
    while (count--)
    {
        mid = pHead->next;
        if (pHead->college_score < pHead->next->college_score)
        {
            pHead->next = mid->next;
            mid->next = pHead;
            pHead = mid;
        }
        pri = pHead;
        mid = pHead->next;
        tai = mid->next;
        while (mid->next != NULL)
        {
            if (mid->college_score < tai->college_score)
            {
                pri->next = mid->next;
                mid->next = tai->next;
                tai->next = mid;
            }
            pri = pri->next;
            mid = pri->next;
            tai = mid->next;
        }
    }
}

//浏览学院得分情况
void PrintCollege(CollegeNode*& pHead)
{
    if (pHead == NULL)
    {
        return;
    }
    CollegeNode* mark = pHead;
    int count = 0;
    while (mark)
    {
        count++;
        mark = mark->next;
    }
    CollegeNode* pri, * mid, * tai, * p;
    while (count--)
    {
        mid = pHead->next;
        if (pHead->college_id > pHead->next->college_id)
        {
            pHead->next = mid->next;
            mid->next = pHead;
            pHead = mid;
        }
        pri = pHead;
        mid = pHead->next;
        tai = mid->next;
        while (mid->next != NULL)
        {
            if (mid->college_id > tai->college_id)
            {
                pri->next = mid->next;
                mid->next = tai->next;
                tai->next = mid;
            }
            pri = pri->next;
            mid = pri->next;
            tai = mid->next;
        }
    }
    printf("————————————————————————————————————————————————————————————\n");
    printf("\t学院编号(名称)\t\t团体总分\t男团总分\t女团总分\n");
    while (pHead)
    {
        printf("\t%d.%-15s", pHead->college_id, pHead->college_name);
        printf("\t%-3d\t\t%-3d\t\t%-3d\n", pHead->college_score, pHead->man_score, pHead->woman_score);
        pHead = pHead->next;
    }
    printf("————————————————————————————————————————————————————————————\n");

}

//浏览项目排名情况
void PrintProject(CollegeNode* pHead, ProjectNode* pNode)
{
    if (!pNode)
    {
        printf("\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\t");
        printf("\t\t当前未录入数据  请管理员输入数据！\n");
        printf("\t〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\t");
    }
    while (pNode)
    {
        printf("———————————————————————————————————————————————————————————\n");
        printf("\t\t第%d个比赛项目:%s", pNode->project_id, pNode->project_name);
        if (strcmp(pNode->sex, "男") == 0)
        {
            printf("\t<男子> 只录入前%d名\n\n", pNode->power);
        }
        else
        {
            printf("\t<女子> 只录入前%d名\n\n", pNode->power);
        }
        for (int i = 0; i < pNode->power; i++)
        {
            CollegeNode* mark = pHead;
            while (mark)
            {
                if (pNode->College[i] == mark->college_id)
                {
                    printf("\t第%d名:%-15s", i + 1, mark->college_name);
                }
                mark = mark->next;
            }
        }
        printf("\n");
        pNode = pNode->next;
    }
}


//学院信息文件读取 读取到内存中
CollegeNode* CollegeFileRead(CollegeNode*& head)
{
    CollegeNode* p1 = NULL;
    CollegeNode* p2 = NULL;
    int i = 0;
    FILE* file = NULL;//定义文件类型指针
    fopen_s(&file, "College_data.txt", "r+");
    if (file == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
        cout << "读取文件失败!\n" << endl;
        return 0;
    }

    char buf[1024];
    fgets(buf, sizeof(buf), file);
    while (!feof(file)) //表示没有指向文件末尾，没指向末尾为0
    {
        p1 = new CollegeNode;

        fscanf(file, "%d\t", &p1->college_id);
        fscanf(file, "%s\t", &p1->college_name);
        fscanf(file, "%d\t", &p1->college_score);
        fscanf(file, "%d\t", &p1->man_score);
        fscanf(file, "%d\t", &p1->woman_score);

        if (head == NULL)
        {
            head = p1;
            p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }
        i++;
    }
    p2->next = NULL;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
    cout << "共读取" << i << "个学院的信息到内存中！" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
    fclose(file);

    return head;
}

//学院信息文件写入 写入到文件中
bool CollegeFileWrite(CollegeNode* pHead)
{
    CollegeNode* p = NULL;
    FILE* file = NULL;
    int i = 0;
    fopen_s(&file, "College_data.txt", "w+");
    if (file == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
        cout << "创建文件失败!" << endl;
        return 0;
    }

    p = pHead;
    fprintf(file, "学院编号\t学院名称\t学院总成绩\t男团成绩\t女团成绩\n");
    while (p != NULL)
    {
        fprintf(file, "%-8d\t", p->college_id);
        fprintf(file, "%-8s\t", p->college_name);
        fprintf(file, "%-8d\t", p->college_score);
        fprintf(file, "%-8d\t", p->man_score);
        fprintf(file, "%-8d\t\n", p->woman_score);
        p = p->next; //指针指向下一个节点
        i++;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
    cout << "共输入" << i << "个学院的信息到文件中！" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
    fclose(file);
    return 1;


}

//项目信息文件读取 读取到内存中
ProjectNode* ProjectFileRead(ProjectNode*& head)
{
    ProjectNode* p1 = NULL;
    ProjectNode* p2 = NULL;
    int i = 0;
    FILE* file = NULL;
    fopen_s(&file, "Project_data.txt", "r+");
    if (file == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
        cout << "读取文件失败!\n" << endl;
        return 0;
    }

    char buf[1024];
    fgets(buf, sizeof(buf), file);
    while (!feof(file)) //表示没有指向文件末尾，没指向末尾为0
    {

        p1 = new ProjectNode;
        fscanf(file, "%d\t", &p1->power);
        fscanf(file, "%s\t", &p1->sex);
        fscanf(file, "%d\t", &p1->project_id);
        fscanf(file, "%s\t", &p1->project_name);

        cout << "计分制为：" << p1->power << endl;
        int flag1 = p1->power;
        if (flag1 == 3)
        {
            fseek(file, -1, SEEK_CUR);

            fscanf(file, "%d\t", &p1->College[0]);
            fscanf(file, "%d\t", &p1->College[1]);
            fscanf(file, "%d\t", &p1->College[2]);

        }
        else if (flag1 == 5)
        {
            fseek(file, -1, SEEK_CUR);

            fscanf_s(file, "%d\t", &p1->College[0], 20);
            fscanf_s(file, "%d\t", &p1->College[1], 20);
            fscanf_s(file, "%d\t", &p1->College[2], 20);
            fscanf_s(file, "%d\t", &p1->College[3], 20);
            fscanf_s(file, "%d\t", &p1->College[4], 20);

        }
        else
        {
            break;
        }
        p1->next = NULL;
        if (head == NULL)
        {
            head = p1;
            p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }

        i++;

    }
    p2->next = NULL;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
    cout << "共读取" << i << "个项目的信息到内存中！" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色

    fclose(file);
    return head;

}

//项目信息文件写入 写入到文件中
bool ProjectFileWrite(ProjectNode* ppHead)
{
    ProjectNode* p = NULL;
    FILE* file = NULL;
    int i = 0;
    fopen_s(&file, "Project_data.txt", "w+");
    if (file == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
        cout << "创建文件失败!" << endl;
        return 0;
    }

    p = ppHead;
    fprintf(file, "前几名\t性别\t项目编号\t项目名称\t获奖学院编号\n");
    while (p != NULL)
    {
        fprintf(file, "%-5d\t", p->power);
        fprintf(file, "%-5s\t", p->sex);
        fprintf(file, "%-4d\t", p->project_id);
        fprintf(file, "%5s\t", p->project_name);

        if (p->power == 5)
        {
            fprintf(file, "%-5d\t", p->College[0]);
            fprintf(file, "%-5d\t", p->College[1]);
            fprintf(file, "%-5d\t", p->College[2]);
            fprintf(file, "%-5d\t", p->College[3]);
            fprintf(file, "%-5d\t\n", p->College[4]);
        }
        else if (p->power == 3)
        {
            fprintf(file, "%-5d\t", p->College[0]);
            fprintf(file, "%-5d\t", p->College[1]);
            fprintf(file, "%-5d\t\n", p->College[2]);
        }
        else
        {
            cout << "写入错误！数据错误！" << endl;
        }
        p = p->next; //指针指向下一个节点
        i++;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
    cout << "共输入" << i << "个项目的信息到文件中！" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
    fclose(file);
    return 1;
}

