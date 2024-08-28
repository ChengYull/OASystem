//
// Created by Administrator on 24-8-28.
//

#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"

class Admin:public User {

public:
    Admin();
    string getPermission() override;
};

#endif //ADMIN_H
