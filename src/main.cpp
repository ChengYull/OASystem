#include <iostream>

#include "../inc/AbstractFactory.h"
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

    delete userFactory;
    return EXIT_SUCCESS;
}