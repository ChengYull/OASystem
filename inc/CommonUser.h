//
// Created by Administrator on 24-8-28.
//

#ifndef CONNONUSER_H
#define CONNONUSER_H


#include "User.h"

class CommonUser:public User{

public:
    CommonUser();
    CommonUser(int id, string username, string password,int perm,int dptId);
    string getPermission() override;
    string getDepartment();
    void display() override;
};



#endif //CONNONUSER_H
