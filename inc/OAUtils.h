#pragma once
#include <string>
#include "User.h"
#include "AbstractFactory.h"
#include "vector"
class OAUtils
{
public:

    static int inputNumber();
    static std::string hashPassword(std::string password);
    static vector<string> parseLine(string line);


};
