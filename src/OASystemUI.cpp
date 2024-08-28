#include <iostream>

#include "../inc/OASystemUI.h"
#include "../inc/OAUtils.h"

using namespace std;

void OASystemUI::displayMainPage()
{
    while (true)
    {
        cout << "欢迎使用OA会议室预定系统" << endl;
        cout << "-----------------------" << endl;
        cout << "1.管理员登录" << endl;
        cout << "2.普通用户登录" << endl;
        cout << "3.退出系统" << endl;
        cout << "-----------------------" << endl;
        cout << "请输入您的选择：";

        // 让用户进行控制台输入选择
        int choice = OAUtils::inputNumber();

        switch (choice)
        {
            case 1:
                cout << "管理员登录" << endl;
            break;
            case 2:
                cout << "普通用户登录" << endl;
            break;
            case 3:
                cout << "退出系统" << endl;
            goto end;

            default:
                break;
        }
    }
    end:
        cout << "欢迎下次使用" << endl;
}