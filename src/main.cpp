#include <iostream>

#include "../inc/AbstractFactory.h"
#include "../inc/OAUtils.h"
#include "../inc/UserFactory.cpp"
using namespace std;

#include "../inc/OASystemUI.h"

int main()
{
    //OASystemUI::displayMainPage();
    AbstractFactory *userFactory = new UserFactory();
    User * admin = userFactory->createAdminFactory();
    cout << "权限：" << admin->getPermission() << endl;

    User * commonUser = userFactory->createCommonUserFactory();
    cout << "权限：" << commonUser->getPermission() << endl;

    admin->id = 1;
    admin->username = "admin";
    admin->password = "450575452";

    //OAUtils::saveUserToFile(admin);
    cout << admin->login("admin","123456");

    vector<User*> userList;
    OAUtils::readFileToUserList(userList);
    cout << userList[0]->getPermission() << endl;
    cout << userList[1]->getPermission() << endl;
    cout << userList[2]->getPermission() << endl;
    delete userFactory;
    return EXIT_SUCCESS;
}