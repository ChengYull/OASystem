//
// Created by Administrator on 24-8-31.
//

#include "UserUtils.h"
#include "CommonUser.h"
#include "UserFactory.h"
#include "iostream"
#include "fstream"

/*
 * 构造函数 初始化工厂和缓存用户列表
 */
UserUtils::UserUtils() {
    //用户工厂 仅需创建一次，程序运行后仅使用一个工厂即可
    userFactory = new UserFactory();
    // 读取用户列表
    bufferUserList = readFileToUserList();
}

/**
 * 析构 释放工厂内存
 */
UserUtils::~UserUtils() {
    delete userFactory;
}

/**
 * 存储用户信息至文件
 * @param user 存储的用户信息
 * @return 存储成功返回true
 */
bool UserUtils::saveUserToFile(User *user) {
    ofstream ofs(USER_SAVE_PATH,ios::out|ios::app);
    if(!ofs.is_open()) {
        cout << "文件打开失败！" << endl;
        return false;
    }
    // 注意密码加密存储
    ofs << user->id << " " << user->username << " "
            << OAUtils::hashPassword(user->password) << " " << user->permission << " "
            << user->departmentId << endl;
    ofs.close();
    return true;
}

bool UserUtils::addUser(User *user) {
    this->bufferUserList.push_back(user);
    return saveUserToFile(user);
}

/**
 * 读取用户文件数据输出为用户列表
 * @param userList 存储读出的用户列表
 * @return 读取成功返回true
 */
vector<User *> UserUtils::readFileToUserList() {
    vector<User *> userList;
    ifstream ifs(USER_SAVE_PATH,ios::in);
    if(!ifs.is_open()) {
        cout << "文件打开失败！" << endl;
        return userList;
    }
    string lineBuffer;
    vector<string> userInfo;
    while(getline(ifs,lineBuffer)) {
        userInfo = OAUtils::parseLine(lineBuffer);
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
    return userList;
}

/**
 * 更新用户文件（根据userList重写）
 * @return 更新用户文件成功返回true
 */
bool UserUtils::updateUserFile() {
    ofstream ofs(USER_SAVE_PATH,ios::out);
    if(!ofs.is_open()) {
        cout << "文件打开更新失败！" << endl;
        return false;
    }
    for(User* user : bufferUserList) {
        ofs << user->id << " " << user->username << " "
            << user->password << " " << user->permission << " "
            << user->departmentId << endl;
    }
    ofs.close();
    return true;
}

/**
 * 根据用户名搜索用户
 * @param username 要搜索的用户名
 * @return 找到了返回指向该用户的迭代器
 */
vector<User*>::iterator UserUtils::getIterByUsername(string username) {
    for(auto iter = bufferUserList.begin();iter != bufferUserList.end(); ++iter) {
        if(username.compare((*iter)->username) == 0) {
            return iter;
        }
    }
    return bufferUserList.end();
}

/**
 * 根据用户名删除用户
 * @param username 用户名
 * @return 删除成功返回true
 */
bool UserUtils::deleteUserByUsername(string username) {
    auto iter = getIterByUsername(username);
    if(iter == bufferUserList.end()) {
        cout << "未找到该用户:" << username << endl;
        return false;
    }
    bufferUserList.erase(iter);
    return updateUserFile();
}

/**
 * 登录功能
 * @param username 用户名
 * @param password 密码
 * @return 登录成功 返回该用户
 */
User* UserUtils::login(string username,string password) {
    auto iter = getIterByUsername(username);
    if(iter != bufferUserList.end()) {
        if((*iter)->login(password)) {
            return *iter;
        }else {
            cout << "密码错误" << endl;
            return nullptr;
        }
    }else {
        cout << "用户名不存在" << endl;
        return nullptr;
    }
}

void UserUtils::showUserTable() {
    if(bufferUserList.size() > 0) {
        cout << "id" << "\t"
            << "用户名" << "\t"
            << "权限" << "\t\t"
            << "部门" << endl;
        for(User* user:bufferUserList) {
            user->display();
        }
    }
}

bool UserUtils::ifIdExist(int id) {
    for(User* user:bufferUserList) {
        if(id == user->id) {
            return true;
        }
    }
    return false;
}

bool UserUtils::ifUsernameExist(string username) {
    for(User* user:bufferUserList) {
        if(username == user->username) {
            return true;
        }
    }
    return false;
}




