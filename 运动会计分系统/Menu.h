#pragma once
//菜单
void menu();//顶级菜单
void log_in_menu();//登录菜单
void adm_menu();//管理员菜单
void user_menu();//用户菜单
void setting_menu();//系统设置菜单

char GetChar();         //清空stdin

//数字范围检验
int CheckNum(int* num, int max, int min);
