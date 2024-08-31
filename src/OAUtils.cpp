#include "../inc/OAUtils.h"
#include <iostream>
#include <limits>
#include <sstream>

#include "fstream"
#include "../inc/CommonUser.h"
#include "../inc/UserFactory.h"
using namespace std;



/**
 * 保证输入的是数字而非其他
 * @return 输出的数字
 */
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

/**
 * 解析一行读出的数据为单个子字符串列表
 * @param line 文件中读出的一行数据以空格分隔
 * @return 返回空格分隔的每个子字符串
 */
vector<string> OAUtils::parseLine(string line) {
    vector<string> lineInfo;
    string tmp;
    stringstream ss;
    ss << line;
    int count = 0;
    while(getline(ss,tmp,' ')) {
        lineInfo.push_back(tmp);
    }
    return lineInfo;
}


