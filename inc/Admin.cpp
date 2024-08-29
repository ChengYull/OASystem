//
// Created by Administrator on 24-8-28.
//
#include "Admin.h"

Admin::Admin() {
    this->username = "";
    this->permission = 1;
}

Admin::Admin(int id, string username, string password,int perm,int dptId){
    this->id = id;
    this->username = username;
    this->password = password;
    this->permission = perm;
    this->departmentId = dptId;
}

string Admin::getPermission() {
    return "管理员";
}
