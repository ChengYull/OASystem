//
// Created by Administrator on 24-8-28.
//
#include "User.h"

#include "OAUtils.h"

User::User(int id, string username, string password)
        :id(id),username(username),password(password) {}

User::~User() {}

bool User::login(string username,string password) {
        // 密码加密
        password = OAUtils::hashPassword(password);
        if(username.compare(this->username)
                && password.compare(this->password)) {
                return true;
        }
        return false;
}


