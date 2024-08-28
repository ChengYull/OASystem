#include "../inc/OAUtils.h"
#include <iostream>
#include <limits>

using namespace std;

int OAUtils::inputNumber()
{
    int choice = -1;
    cin >> choice;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }

    return choice;
}

/**
 * 对密码进行加密处理
 * @param password 密码
 * @return 哈希乘法加密后的密码
 */
string OAUtils::hashPassword(string password) {
    long long hash = 0;
    int MODULE = 1000000007;
    for(unsigned char ch : password) {
        hash = ((31 * hash) + (int)ch) % MODULE;
    }
    return std::to_string(hash);
}
