//
// Created by Administrator on 24-8-28.
//

#include "CommonUser.h"
#include "iostream"
#include "OAUtils.h"

CommonUser::CommonUser() {
    this->permission = 0;
}
CommonUser::CommonUser(int id, string username, string password,int perm,int dptId){
    this->id = id;
    this->username = username;
    this->password = password;
    this->permission = perm;
    this->departmentId = dptId;
}
string CommonUser::getPermission() {
    return "普通用户";
}

string CommonUser::getDepartment() {
    switch (this->departmentId) {
        case 0:
            return "人事部";
        case 1:
            return "材料部";
        case 2:
            return "测试部";
        case 3:
            return "研发部";
        default:
            return "未定义部门";
    }
}
void CommonUser::display() {
    cout << this->id << '\t'
        << this->username << "\t"
        << this->getPermission() <<  "\t"
        << this->getDepartment()<< endl;
}
