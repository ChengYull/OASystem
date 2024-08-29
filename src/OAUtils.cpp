#include "../inc/OAUtils.h"
#include <iostream>
#include <limits>
#include <sstream>

#include "fstream"
#include "../inc/CommonUser.h"
#include "../inc/UserFactory.h"
using namespace std;

string USER_SAVE_PATH = "../../data/user.txt";

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



AbstractFactory* OAUtils::userFactory = new UserFactory();
OAUtils::~OAUtils() {
    delete userFactory;
}

bool OAUtils::saveUserToFile(User *user) {
    ofstream ofs(USER_SAVE_PATH,ios::out|ios::app);
    if(!ofs.is_open()) {
        cout << "文件打开失败！" << endl;
        return false;
    }
    ofs << user->id << " " << user->username << " "
            << hashPassword(user->password) << " " << user->permission << " "
            << user->departmentId << endl;
    ofs.close();
    return true;
}

bool OAUtils::readFileToUserList(vector<User *> &userList) {
    ifstream ifs(USER_SAVE_PATH,ios::in);
    if(!ifs.is_open()) {
        cout << "文件打开失败！" << endl;
        return false;
    }
    string lineBuffer,tmp;

    vector<string> userInfo;
    while(getline(ifs,lineBuffer)) {
        stringstream ss;
        ss << lineBuffer;
        int count = 0;
        while(getline(ss,tmp,' ')) {
            userInfo.push_back(tmp);
            count ++;
        }
        int id = stoi(userInfo[0]);
        string username = userInfo[1];
        string password = userInfo[2];
        int permission = stoi(userInfo[3]);
        int dptId = stoi(userInfo[4]);
        User * user;

        if(permission == 1) {
            user = userFactory->createAdminFactory(id,username,password,
                                                        permission,dptId);
        }else {
            user = userFactory->createCommonUserFactory(id,username,password,
                                                        permission,dptId);
        }
        userList.push_back(user);
        userInfo.clear();
    }
    ifs.close();
    return true;
}
