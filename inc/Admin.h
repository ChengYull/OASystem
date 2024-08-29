//
// Created by Administrator on 24-8-28.
//

#ifndef ADMIN_H
#define ADMIN_H
#include "OAUtils.h"
#include "User.h"

class Admin:public User {

public:
    Admin();

    Admin(int id, string username, string password,int perm,int dptId);
    string getPermission() override;
};

#endif //ADMIN_H
