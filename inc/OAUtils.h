#pragma once
#include <string>

#include "AbstractFactory.h"
#include "vector"
class OAUtils
{
public:
    static int inputNumber();
    static std::string hashPassword(std::string password);
    static AbstractFactory * userFactory;
    ~OAUtils();
    static bool saveUserToFile(User *user);
    static bool readFileToUserList(vector<User*> &userList);
};
