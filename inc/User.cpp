//
// Created by Administrator on 24-8-28.
//
#include "User.h"

#include "OAUtils.h"

User::User() {
        this->departmentId = -1;
}

User::~User() {}

bool User::login(string password) {
        // 密码加密
        password = OAUtils::hashPassword(password);
        return password.compare(this->password) == 0;
}


