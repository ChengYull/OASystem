#include <iostream>

#include "../inc/OASystemUI.h"
#include "../inc/OAUtils.h"


using namespace std;

OASystemUI::OASystemUI() {
    utils = new UserUtils();
}

void OASystemUI::displayMainPage()
{
    while (true)
    {
        cout << "欢迎使用OA会议室预定系统" << endl;
        cout << "-----------------------" << endl;
        cout << "1.登录" << endl;
        cout << "2.普通用户" << endl;
        cout << "3.退出系统" << endl;
        cout << "-----------------------" << endl;
        cout << "请输入您的选择：";

        // 让用户进行控制台输入选择
        int choice = OAUtils::inputNumber();

        switch (choice)
        {
            case 1:
                cout << "登录" << endl;
                loginPage();
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

void OASystemUI::loginPage() {
    cout << "欢迎使用OA会议室预定系统" << endl;
    cout << "-----------------------" << endl;
    cout << "登录:" << endl;
    cout << "请输入用户名:" ;
    string username;
    cin >> username;
    cout << "请输入密码：" ;
    string password;
    cin >> password;
    cout << "--------请稍等---------" << endl;
    User* user = utils->login(username,password);
    if(user != nullptr) {
        cout << "欢迎你，" << user->getPermission() << endl;
    }else {
        cout << "登录失败！" << endl;
    }

}
