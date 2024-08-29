//
// Created by Administrator on 24-8-28.
//

#ifndef USERFACTORY_H
#define USERFACTORY_H

#include "AbstractFactory.h"
#include "Admin.h"
#include "CommonUser.h"

class UserFactory:public AbstractFactory {
    User* createCommonUserFactory() override{
        return new CommonUser();
    }
    User* createCommonUserFactory(int id,string username,string password,
                                            int permission,int dptId) override {
        return new CommonUser(id,username,password,permission,dptId);
    }
    User* createAdminFactory() override {
        return new Admin();
    }
    User* createAdminFactory(int id,string username,string password,
                                            int permission,int dptId) override {
        return new Admin(id,username,password,permission,dptId);
    }


};

#endif //USERFACTORY_H
