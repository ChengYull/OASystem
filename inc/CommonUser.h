//
// Created by Administrator on 24-8-28.
//

#ifndef CONNONUSER_H
#define CONNONUSER_H


#include "User.h"

class CommonUser:public User{

public:
    CommonUser();
    string getPermission() override;
};



#endif //CONNONUSER_H
