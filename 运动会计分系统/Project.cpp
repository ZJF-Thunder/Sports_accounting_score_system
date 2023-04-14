//#pragma warning (disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>//�õ�setw()����
#include <windows.h>//����̨�����Ҫͷ�ļ�
#include<conio.h>//_getch()
#include "Project.h"
#include "Menu.h"
using namespace std;


//��ȡ�ַ�
char GetChar()
{
    char ch = getchar();
    fflush(stdin);
    return ch;
}


//���ַ�Χ����
int CheckNum(int* num, int max, int min)
{
    do
    {
        *num = min - 1;
        cin >> *num;
        while (getchar() != '\n');
        if (*num > max || *num < min)
        {
            printf("��������,����������[%d--%d]:", min, max);
        }
    } while (*num > max || *num < min);
    return *num;
}



//��Ϣ��ʼ������ ���������� �������� �л���Ů
void IntiInfo(CollegeNode*& pHead, ProjectNode*& ppHead)
{
    CollegeNode* p1 = NULL;
    ProjectNode* p2 = NULL;
    int id_c = 1;//ѧԺ���
    int id_p = 1;//��Ŀ���
    int num_c = 0; // ��Ҫ�����ѧԺ����
    int num_p = 0; // ��Ҫ�������Ŀ����
    if (pHead == NULL)
    {
        printf("\t¼��ѧԺ����<5 - 15>\n\t: ");
        num_c = CheckNum(&num_c, 15, 5);
    }
    else
    {
        printf("\t¼��ѧԺ����<0 - 15>\n\t: ");
        num_c = CheckNum(&num_c, 15, 0);
        if (num_c == 0)
        {
            cout << "\tδ���ѧԺ!��ȷ���Ƿ�Ҫ��ӣ�" << endl;
            return;
        }
    }
    printf("\t¼����Ŀ����<1 - 10>\n\t: ");
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

//�������
CollegeNode* GetCollegeNode(CollegeNode*& pHead, CollegeNode*& p, int& id_c)
{
    CollegeNode* node = NULL;
    node = new CollegeNode;
    printf("\t�����%d��ѧԺ������: ", id_c);
    node->college_id = id_c++;//ѧԺ��Ÿ������id_s�仯
    while (1)
    {
        cin >> node->college_name;
        if (node->college_name[0] == '\0')
        {
            printf("\t����Ϊ�գ�����������:");
        }
        else
        {
            break;
        }
    }
    //��ʼ��
    node->man_score = 0;//���ŵ÷�
    node->woman_score = 0;//Ů�ŵ÷�
    node->college_score = 0;//ѧԺ�ܵ÷�
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
    printf("\t�����%d����Ŀ������: ", id_p);
    node->project_id = id_p++;
    while (1)
    {
        cin >> node->project_name;
        if (node->project_name[0] == '\0')
        {
            printf("\t����Ϊ�գ�����������:");
        }
        else {
            break;
        }
    }

    printf("\t���ӣ��У�/Ů�ӣ�Ů��: ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
    cout << "��Ŀ�Ա�:";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
    cin >> node->sex;
    while (strcmp(node->sex, "��") != 0 && strcmp(node->sex, "Ů") != 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "�Ƿ����룡����������:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
        cin >> node->sex;
    }

    while (1)
    {
        if (strcmp(node->sex, "Ů") == 0)
        {
            printf("\tŮ��%s", node->project_name);
        }
        else
        {
            printf("\t����%s", node->project_name);
        }

        printf("��Ŀ¼��: 3:ǰ���� 5:ǰ����: ");
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
            printf("��{3��5}��ѡ��");
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


//������ǰ��������ǰ������ѧԺ ����ɼ�
void InputScore(ProjectNode* pNode, CollegeNode* pHead)
{
    if (pNode == NULL)
    {
        cout << "��������Ŀ" << endl;
    }

    int count = 0; //ѧԺ�ĸ���
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
        //�����ʾ
        printf("%d.%-20s", p->college_id, p->college_name);
        p = p->next;
    }*/
    while (pNode)
    {
        p = pHead;
        system("cls");
        while (p)
        {
            //�����ʾ
            printf("%d.%-20s", p->college_id, p->college_name);
            p = p->next;
        }

        printf("\n\n���  %s��Ŀ\tǰ%d��<��д��� 1 - %d>:\n", pNode->project_name, pNode->power, count);
        int num = 1;
        for (int i = 0; i < pNode->power; i++)
        {
            printf("��%d����ѧУ: ", i + 1); //����Ҫ����һ��ͬ�������ֲ���������
            int choose = CheckNum(&choose, count, 1);
            pNode->College[i] = choose;
            AddCollegeScore(pHead, pNode, choose, num);
            cout << "��ѧԺ��Ŀ�Ʒ����!" << endl;
            num++;
        }
        printf("\n");
        pNode = pNode->next;
    }

}


//�޸ĺ��� �޸����Σ��޸�ѧԺ���� �޸���Ŀ���� �޸Ļ�����
int CollegeModify(CollegeNode* head, ProjectNode* pNode)
{

    char college_name[20];//ѧԺ����
    char project_name[20];//��Ŀ����
    CollegeNode* p = NULL;//ѧԺ�޸�ָ��
    ProjectNode* p2 = NULL;//��Ŀ�޸�ָ��
    int i = 0;//���λ��
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
    cout << "\t\t                           ******************************" << endl;
    cout << "\t\t                        *******��ѡ����Ҫ�޸ĵĶ���*******" << endl;
    cout << "\t\t                       *******      1-->�޸�ѧԺ��Ϣ    *******" << endl;
    cout << "\t\t                       *******      2-->�޸���Ŀ��Ϣ    *******" << endl;
    cout << "\t\t                        *******     3-->�������˵�   *******" << endl;
    cout << "\t\t                           ******************************" << endl;
    cout << "\t\t                      ����������ѡ��(1-3):";
    char b[10] = "0";//ȷ�����������
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
    cin >> b;
    while (strcmp(b, "1") != 0 && strcmp(b, "2") != 0 && strcmp(b, "3") != 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "�����������������:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
        cin >> b;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
    if (strcmp(b, "1") == 0)//�޸�ѧԺ
    {
        cout << "����������Ҫ�޸�ѧԺ���ƣ�";
        cin >> college_name;
        system("cls");
        if (head == NULL)//����ǿ�����
        {
            cout << "��ѧԺ��Ϣ��" << endl;
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
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
            cout << "\t\t        ��ѧԺ������!" << endl;
            CollegeModify(head, pNode);
        }
        else
        {
            printf("\tѧԺ���(����)\t\t�����ܷ�\t�����ܷ�\tŮ���ܷ�\n");

            printf("\t%d", p->college_id);
            printf(".%-15s\t", p->college_name);
            printf("%-3d\t\t", p->college_score);
            printf("%-3d\t\t", p->man_score);
            printf("%-3d\n", p->woman_score);

            cout << "�޸�ǰѧԺ���ƣ�" << p->college_name << endl;
            cout << "������ѧԺ����:";
            cin >> p->college_name;

            system("pause");
            cout << "\t\t                           **********************" << endl;
            cout << "\t\t                        *******�Ƿ�����޸ģ�*******" << endl;
            cout << "\t\t                       *******    1-->��      *******" << endl;
            cout << "\t\t                        *******   2-->��     *******" << endl;
            cout << "\t\t                           **********************" << endl;
            cout << "\t\t                       ����������ѡ��(1-2):";
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
                cout << "�����������������!" << endl;
            }
        }

    }

    else if (strcmp(b, "2") == 0)//�޸���Ŀ
    {
        cout << "����������Ҫ�޸���Ŀ���ƣ�";
        cin >> project_name;
        system("cls");
        if (pNode == NULL)//����ǿ�����
        {
            cout << "����Ŀ��Ϣ��" << endl;
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
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
            cout << "\t\t        ����Ŀ������!" << endl;
            CollegeModify(head, pNode);
        }
        else
        {
            printf("����������������������������������������������������������������������������������������������������������������������������\n");
            printf("\t\t������Ŀ:%s", p2->project_name);

            if (strcmp(p2->sex, "��") == 0)
            {
                printf("\t<����> ֻ¼��ǰ%d��\n\n", p2->power);
            }
            else
            {
                printf("\t<Ů��> ֻ¼��ǰ%d��\n\n", p2->power);
            }
            for (int i = 0; i < p2->power; i++)
            {
                CollegeNode* mark = head;
                while (mark)
                {
                    if (p2->College[i] == mark->college_id)
                    {
                        printf("\t��%d��:%-15s", i + 1, mark->college_name);
                    }
                    mark = mark->next;
                }
            }
            printf("\n\n");

            printf("�޸�1.��Ŀ����\t2.ǰ����\t3.�Ա�4.�޸Ļ�ѧԺ\t\t\n");
            char g[10] = "0";
            cin >> g;
            system("cls");

            if (strcmp(g, "1") == 0)
            {
                cout << "�޸�ǰ��Ŀ���ƣ�" << p2->project_name << endl;
                cout << "��������Ŀ����:";
                cin >> p2->project_name;

            }
            else if (strcmp(g, "2") == 0)
            {
                cout << "�޸�ǰǰ������" << p2->power << endl;
                cout << "������ǰ����:";
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
                    //�����ʾ
                    printf("%d.%-20s", p3->college_id, p3->college_name);
                    p3 = p3->next;
                }
                printf("\n\n���  %s��Ŀ\tǰ%d��<��д��� 1 - %d>:\n", pNode->project_name, pNode->power, count);
                int num = 1;
                for (int i = 0; i < p2->power; i++)
                {
                    printf("��%d����ѧУ: ", i + 1); //����Ҫ����һ��ͬ�������ֲ���������
                    int choose = CheckNum(&choose, count, 1);
                    pNode->College[i] = choose;
                    AddCollegeScore(head, pNode, choose, num);
                    cout << "��ѧԺ��Ŀ�Ʒ����!" << endl;
                    num++;
                }
            }
            else if (strcmp(g, "3") == 0)
            {
                cout << "�޸�ǰ�Ա�" << p2->sex << endl;
                cout << "�������Ա�:";
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
                    //�����ʾ
                    printf("%d.%-20s", p3->college_id, p3->college_name);
                    p3 = p3->next;
                }
                printf("\n\n���  %s��Ŀ\tǰ%d��<��д��� 1 - %d>:\n", pNode->project_name, pNode->power, count);
                int num = 1;
                for (int i = 0; i < pNode->power; i++)
                {
                    printf("��%d����ѧУ: ", i + 1); //����Ҫ����һ��ͬ�������ֲ���������
                    int choose = CheckNum(&choose, count, 1);
                    pNode->College[i] = choose;
                    AddCollegeScore(head, pNode, choose, num);
                    cout << "��ѧԺ��Ŀ�Ʒ����!" << endl;
                    num++;
                }
            }

            else
            {
                cout << "�������" << endl;
            }
            system("pause");
            cout << "\t\t                           **********************" << endl;
            cout << "\t\t                        *******�Ƿ�����޸ģ�*******" << endl;
            cout << "\t\t                       *******    1-->��      *******" << endl;
            cout << "\t\t                        *******   2-->��     *******" << endl;
            cout << "\t\t                           **********************" << endl;
            cout << "\t\t                       ����������ѡ��(1-2):";
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
                cout << "�����������������!" << endl;
            }
        }

    }

    else if (strcmp(b, "3") == 0)
    {
        return 0;
    }

}


//ɾ������ ɾ��ѧԺ��ɾ����Ŀ
int CollegeNodeDel(CollegeNode*& head, ProjectNode*& pNode)
{
    CollegeNode* q = NULL;
    CollegeNode* p = head;
    ProjectNode* r = NULL;
    ProjectNode* s = pNode;
    int i = 0;//���ڱ����ҵ�����ѯ��Ϣλ��
    int k = 0;//�����ж��Ƿ��д˶���
    char college_name[20];//��Ҫɾ����ѧԺ����
    char project_name[20];
    char choose[10] = "0";//����һ��ѡ���ַ�
    cout << "\t\t                           *****************************" << endl;
    cout << "\t\t                          *******   ��ѡ��ɾ������:  *******" << endl;
    cout << "\t\t                        *******     1-->ɾ��ѧԺ    *******" << endl;
    cout << "\t\t                       *******      2-->ɾ����Ŀ     *******" << endl;
    cout << "\t\t                      *******       3-->�������˵�      *******" << endl;
    cout << "\t\t                           *****************************" << endl;
    cout << "\t\t                      ����������ѡ��1-3��:";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
    cin >> choose;
    while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0 && strcmp(choose, "3") != 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "\t\t                   ����������������루1-3��:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
        cin >> choose;
    }
    if (strcmp(choose, "1") == 0)
    {
        i = 0;
        k = 0;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "\t\t  ����������Ҫɾ����ѧԺ����:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
        cin >> college_name;//������Ҫɾ����ѧԺ����
        while (p != NULL)
        {
            i++;//��¼λ�ã�����ɾ����������Ϣ��ȵ�����
            if (strcmp(college_name, p->college_name) == 0)//�ж���Ҫɾ����������Ϣ�Ƿ����
            {
                int j = 1;
                if (i == 1)//��ɾ�������ǵ�һ��ʱ
                {
                    head = p->next;
                    i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
                }
                else
                {
                    q = head;
                    while (q != NULL)
                    {
                        if (j + 1 == i)//��ɾ��λ�õ�ǰһλ
                        {
                            if (q->next->next != NULL)
                            {
                                q->next = q->next->next;
                                i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
                            }
                            else
                            {
                                q->next = NULL;
                            }
                        }
                        q = q->next;
                        j++;//��¼qָ��ָ��λ�ã�������i�Ա��ҵ�����в����ĵط�
                    }
                }
                k++;//�ж��Ƿ�����ɾ����Ϣ����
            }
            p = p->next;
        }
        if (k == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
            cout << "\t\t                       *************     ��ѧԺ�����ڣ�   *************" << endl;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
            cout << "\t\t           *************       �ɹ�ɾ������Ϊ" << college_name << "��" << k << "��ѧԺ��Ϣ��      *************" << endl;
        }
    }
    else if (strcmp(choose, "2") == 0)
    {
        i = 0;
        k = 0;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "\t\t  ����������Ҫɾ������Ŀ����:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
        cin >> project_name;//������Ҫɾ������Ŀ����
        while (s != NULL)
        {
            i++;//��¼λ�ã�����ɾ����������Ϣ��ȵ�����
            if (strcmp(project_name, s->project_name) == 0)//�ж���Ҫɾ����������Ϣ�Ƿ����
            {
                int j = 1;
                if (i == 1)//��ɾ�������ǵ�һ��ʱ
                {
                    pNode = s->next;
                    i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
                }
                else
                {
                    r = pNode;
                    while (q != NULL)
                    {
                        if (j + 1 == i)//��ɾ��λ�õ�ǰһλ
                        {
                            if (r->next->next != NULL)
                            {
                                r->next = r->next->next;
                                i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
                            }
                            else
                            {
                                r->next = NULL;
                            }
                        }
                        r = r->next;
                        j++;//��¼qָ��ָ��λ�ã�������i�Ա��ҵ�����в����ĵط�
                    }
                }
                k++;//�ж��Ƿ�����ɾ����Ϣ����
            }
            s = s->next;
        }
        if (k == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
            cout << "\t\t                       *************     ����Ŀ�����ڣ�   *************" << endl;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
            cout << "\t\t           *************       �ɹ�ɾ������Ϊ" << project_name << "��" << k << "����Ŀ��Ϣ��      *************" << endl;
        }
    }
    else if (strcmp(choose, "3") == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        return 0;
    }

    char choi[10] = "0";
    i = 0; //�����ж���ѡ���Ƿ��������ʱ��ѡ���Ƿ����
    while (strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
    {
        if (i > 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            cout << "\t\t                                     �Ƿ����룡���������룡" << endl;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
        cout << "\t\t                              ********************************" << endl;
        cout << "\t\t                           *******    �Ƿ����ɾ����Ʒ��  *******" << endl;
        cout << "\t\t                          *******       Y-->����ɾ��       *******" << endl;
        cout << "\t\t                           *******      N-->�������˵�    *******" << endl;
        cout << "\t\t                              ********************************" << endl;
        cout << "\t\t                          ����������ѡ��(Y or N):";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
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

//��ѯѧԺ ģ������
int CollegeSearch(CollegeNode* head)
{
    char college_name[20];

    printf("�������ѯ��ѧԺ����:");
    cin >> college_name;

    CollegeNode* p = NULL;//p�ǲ���λ��
    int i = 0;//λ�����
    if (head == NULL)//����ǿ�����
    {
        cout << "\t\t        ��ѧԺ��Ϣ��" << endl;
        return -1;//��ʾ��ʱ����Ϊ��
    }

    p = head;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
    int j = 0;
    for (p = head; p != NULL; p = p->next)
    {
        char* s = NULL;
        s = strstr(p->college_name, college_name);
        if (s != NULL)
        {
            if (i == 0)
            {
                printf("\tѧԺ���(����)\t\t�����ܷ�\t�����ܷ�\tŮ���ܷ�\n");
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
        cout << "\t\t        û�и����Ƶ�ѧԺ��" << endl;
        _getch();
    }
    return 0;

}

//��ѯ��Ŀ
int ProjectSearch(ProjectNode* head, CollegeNode* chead)
{
    char project_name[20];

    printf("�������ѯ����Ŀ����:");
    cin >> project_name;

    ProjectNode* p = NULL;//p�ǲ���λ��
    int i = 0;//λ�����
    if (head == NULL)//����ǿ�����
    {
        cout << "����Ŀ��Ϣ��" << endl;
    }

    p = head;
    while (p != NULL && strcmp(project_name, p->project_name) != 0)
    {
        p = p->next;
        i++;
    }

    if (p == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "\t\t        ����Ŀ������!" << endl;
    }
    else
    {
        printf("����������������������������������������������������������������������������������������������������������������������������\n");
        printf("\t\t������Ŀ:%s", p->project_name);

        if (strcmp(p->sex, "��") == 0)
        {
            printf("\t<����> ֻ¼��ǰ%d��\n\n", p->power);
        }
        else
        {
            printf("\t<Ů��> ֻ¼��ǰ%d��\n\n", p->power);
        }
        for (int i = 0; i < p->power; i++)
        {
            CollegeNode* mark = chead;
            while (mark)
            {
                if (p->College[i] == mark->college_id)
                {
                    printf("\t��%d��:%-15s", i + 1, mark->college_name);
                }
                mark = mark->next;
            }
        }
        printf("\n");
    }
    return 0;

}


//�Ʒֺ���
void AddCollegeScore(CollegeNode* pHead, ProjectNode* pNode, int id, int sort)
{
    int grade_3[3] = { 5, 3, 2 };
    int grade_5[5] = { 7, 5, 3, 2, 1 };
    CollegeNode* mark = pHead;
    while (mark)
    {
        if (mark->college_id == id)
        {
            if (strcmp(pNode->sex, "��") == 0 && pNode->power == 3)
            {
                mark->man_score += grade_3[sort - 1];
                mark->college_score += grade_3[sort - 1];
            }
            else if (strcmp(pNode->sex, "��") == 0 && pNode->power == 5)
            {
                mark->man_score += grade_5[sort - 1];
                mark->college_score += grade_5[sort - 1];
            }
            else if (strcmp(pNode->sex, "Ů") == 0 && pNode->power == 3)
            {
                mark->woman_score += grade_3[sort - 1];
                mark->college_score += grade_3[sort - 1];
            }
            else if (strcmp(pNode->sex, "Ů") == 0 && pNode->power == 5)
            {
                mark->woman_score += grade_5[sort - 1];
                mark->college_score += grade_5[sort - 1];
            }
        }
        mark = mark->next;
    }
}


//����ܷ�����������  ����ģ��
void SortModule(CollegeNode*& pHead)
{
    if (pHead == NULL)
    {
        printf("\t������������������������������������������������������������������������������\n\t");
        printf("\t\t��ǰδ¼������  �����Ա�������ݣ�\n");
        printf("\t������������������������������������������������������������������������������\n\t");
        return;
    }
    int g_menu = 0;
    cout << "\t\t            ************************************************************************" << endl;
    cout << "\t\t           ********************          ��ѡ����������:         ********************" << endl;
    cout << "\t\t          ********************         1-->�������Ž�������       ********************" << endl;
    cout << "\t\t         ********************          2-->����Ů�Ž�������        ********************" << endl;
    cout << "\t\t         ********************          3-->����ѧԺ�ֽܷ�������    ********************" << endl;
    cout << "\t\t          ********************         4-->�������˵�   ********************" << endl;
    cout << "\t\t            ***********************************************************************" << endl;
    cout << "\t\t         ����������ѡ��1-4��:";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
    cin >> g_menu;
    while (g_menu != 1 && g_menu != 2 && g_menu != 3 && g_menu != 4)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "\t\t                    ����������������루1-4��:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
        cin >> g_menu;
    }
    system("cls");//����

    switch (g_menu)
    {
    case 1:
        printf("\t\t�������Ž������У�\n");
        ManScoreSort(pHead);
        break;
    case 2:
        printf("\t\t����Ů�Ž������У�\n");
        WomanScoreSort(pHead);
        break;
    case 3:
        printf("\t\t����ѧԺ�ֽܷ������У�\n");
        SchoolScoreSort(pHead);
        break;
    case 4:
        return;
        break;

    }

    printf("����������������������������������������������������������������������������������������������������������������������\n");
    printf("\tѧԺ���(����)\t\t�����ܷ�\t�����ܷ�\tŮ���ܷ�\n");
    while (pHead)
    {
        printf("\t%d.%-15s", pHead->college_id, pHead->college_name);
        printf("\t%-3d\t\t%-3d\t\t%-3d\n", pHead->college_score, pHead->man_score, pHead->woman_score);
        pHead = pHead->next;
    }
    printf("����������������������������������������������������������������������������������������������������������������������\n");

    char choi[10] = "0";
    int i = 0; //�����ж���ѡ���Ƿ��������ʱ��ѡ���Ƿ����
    while (strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
    {
        if (i > 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            cout << "\t\t                                     �Ƿ����룡���������룡" << endl;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
        cout << "\t\t                              ********************************" << endl;
        cout << "\t\t                           *******  �Ƿ�����鿴ѧԺ����*******" << endl;
        cout << "\t\t                          *******       Y-->�����鿴       *******" << endl;
        cout << "\t\t                           *******      N-->�������˵�    *******" << endl;
        cout << "\t\t                              ********************************" << endl;
        cout << "\t\t                          ����������ѡ��(Y or N):";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
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


//���ӳɼ����� ð������
void ManScoreSort(CollegeNode*& pHead)
{
    if (pHead == NULL)
    {
        printf("\t������������������������������������������������������������������������������\n\t");
        printf("\t\t��ǰδ¼������  �����Ա�������ݣ�\n");
        printf("\t������������������������������������������������������������������������������\n\t");
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

//Ů�ӳɼ����� ֱ�Ӳ�������
void WomanScoreSort(CollegeNode*& pHead)
{
    if (pHead == NULL)
    {
        printf("\t������������������������������������������������������������������������������\n\t");
        printf("\t\t��ǰδ¼������  �����Ա�������ݣ�\n");
        printf("\t������������������������������������������������������������������������������\n\t");
        return;
    }
    CollegeNode* q = NULL;
    CollegeNode* p = NULL;
    CollegeNode* k = NULL;
    CollegeNode* r = NULL;
    q = new CollegeNode;//Ϊ�������ڴ浥Ԫ
    q->next = pHead;//q����һ�ڵ�ָ��ͷ���
    pHead = q;//��ͷ�����Ϊ��
    p = pHead->next->next;//��ָ��p������δ����Ԫ�ص���Ϣ
    pHead->next->next = NULL;//ʹ��ԭ����������������ǰ����һ��Ԫ��
    while (p != NULL)//����������
    {
        k = p->next;//����λ��
        r = pHead;//��ָ��ָ��������
        while (r->next != NULL && r->next->woman_score > p->woman_score)//�ж�ָ��ָ�����һ��Ԫ����������ȡ��Ԫ�صĴ�С
        {
            r = r->next;
        }
        p->next = r->next;//�������
        r->next = p;
        p = k;//��pֵ�ظ���ָ����������һ���ڵ�
    }
    pHead = pHead->next;//ȥ��һ��ʼ����Ŀ�����
    delete q;

}

//ѧԺ�ܷ����� ð������
void SchoolScoreSort(CollegeNode*& pHead)
{
    if (pHead == NULL)
    {
        printf("\t������������������������������������������������������������������������������\n\t");
        printf("\t\t��ǰδ¼������  �����Ա�������ݣ�\n");
        printf("\t������������������������������������������������������������������������������\n\t");
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

//���ѧԺ�÷����
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
    printf("������������������������������������������������������������������������������������������������������������������������\n");
    printf("\tѧԺ���(����)\t\t�����ܷ�\t�����ܷ�\tŮ���ܷ�\n");
    while (pHead)
    {
        printf("\t%d.%-15s", pHead->college_id, pHead->college_name);
        printf("\t%-3d\t\t%-3d\t\t%-3d\n", pHead->college_score, pHead->man_score, pHead->woman_score);
        pHead = pHead->next;
    }
    printf("������������������������������������������������������������������������������������������������������������������������\n");

}

//�����Ŀ�������
void PrintProject(CollegeNode* pHead, ProjectNode* pNode)
{
    if (!pNode)
    {
        printf("\t������������������������������������������������������������������������������\n\t");
        printf("\t\t��ǰδ¼������  �����Ա�������ݣ�\n");
        printf("\t������������������������������������������������������������������������������\n\t");
    }
    while (pNode)
    {
        printf("����������������������������������������������������������������������������������������������������������������������\n");
        printf("\t\t��%d��������Ŀ:%s", pNode->project_id, pNode->project_name);
        if (strcmp(pNode->sex, "��") == 0)
        {
            printf("\t<����> ֻ¼��ǰ%d��\n\n", pNode->power);
        }
        else
        {
            printf("\t<Ů��> ֻ¼��ǰ%d��\n\n", pNode->power);
        }
        for (int i = 0; i < pNode->power; i++)
        {
            CollegeNode* mark = pHead;
            while (mark)
            {
                if (pNode->College[i] == mark->college_id)
                {
                    printf("\t��%d��:%-15s", i + 1, mark->college_name);
                }
                mark = mark->next;
            }
        }
        printf("\n");
        pNode = pNode->next;
    }
}


//ѧԺ��Ϣ�ļ���ȡ ��ȡ���ڴ���
CollegeNode* CollegeFileRead(CollegeNode*& head)
{
    CollegeNode* p1 = NULL;
    CollegeNode* p2 = NULL;
    int i = 0;
    FILE* file = NULL;//�����ļ�����ָ��
    fopen_s(&file, "College_data.txt", "r+");
    if (file == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "��ȡ�ļ�ʧ��!\n" << endl;
        return 0;
    }

    char buf[1024];
    fgets(buf, sizeof(buf), file);
    while (!feof(file)) //��ʾû��ָ���ļ�ĩβ��ûָ��ĩβΪ0
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
    cout << "����ȡ" << i << "��ѧԺ����Ϣ���ڴ��У�" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
    fclose(file);

    return head;
}

//ѧԺ��Ϣ�ļ�д�� д�뵽�ļ���
bool CollegeFileWrite(CollegeNode* pHead)
{
    CollegeNode* p = NULL;
    FILE* file = NULL;
    int i = 0;
    fopen_s(&file, "College_data.txt", "w+");
    if (file == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "�����ļ�ʧ��!" << endl;
        return 0;
    }

    p = pHead;
    fprintf(file, "ѧԺ���\tѧԺ����\tѧԺ�ܳɼ�\t���ųɼ�\tŮ�ųɼ�\n");
    while (p != NULL)
    {
        fprintf(file, "%-8d\t", p->college_id);
        fprintf(file, "%-8s\t", p->college_name);
        fprintf(file, "%-8d\t", p->college_score);
        fprintf(file, "%-8d\t", p->man_score);
        fprintf(file, "%-8d\t\n", p->woman_score);
        p = p->next; //ָ��ָ����һ���ڵ�
        i++;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
    cout << "������" << i << "��ѧԺ����Ϣ���ļ��У�" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
    fclose(file);
    return 1;


}

//��Ŀ��Ϣ�ļ���ȡ ��ȡ���ڴ���
ProjectNode* ProjectFileRead(ProjectNode*& head)
{
    ProjectNode* p1 = NULL;
    ProjectNode* p2 = NULL;
    int i = 0;
    FILE* file = NULL;
    fopen_s(&file, "Project_data.txt", "r+");
    if (file == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "��ȡ�ļ�ʧ��!\n" << endl;
        return 0;
    }

    char buf[1024];
    fgets(buf, sizeof(buf), file);
    while (!feof(file)) //��ʾû��ָ���ļ�ĩβ��ûָ��ĩβΪ0
    {

        p1 = new ProjectNode;
        fscanf(file, "%d\t", &p1->power);
        fscanf(file, "%s\t", &p1->sex);
        fscanf(file, "%d\t", &p1->project_id);
        fscanf(file, "%s\t", &p1->project_name);

        cout << "�Ʒ���Ϊ��" << p1->power << endl;
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
    cout << "����ȡ" << i << "����Ŀ����Ϣ���ڴ��У�" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ

    fclose(file);
    return head;

}

//��Ŀ��Ϣ�ļ�д�� д�뵽�ļ���
bool ProjectFileWrite(ProjectNode* ppHead)
{
    ProjectNode* p = NULL;
    FILE* file = NULL;
    int i = 0;
    fopen_s(&file, "Project_data.txt", "w+");
    if (file == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
        cout << "�����ļ�ʧ��!" << endl;
        return 0;
    }

    p = ppHead;
    fprintf(file, "ǰ����\t�Ա�\t��Ŀ���\t��Ŀ����\t��ѧԺ���\n");
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
            cout << "д��������ݴ���" << endl;
        }
        p = p->next; //ָ��ָ����һ���ڵ�
        i++;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
    cout << "������" << i << "����Ŀ����Ϣ���ļ��У�" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
    fclose(file);
    return 1;
}

