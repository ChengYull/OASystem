//
// Created by Administrator on 24-8-28.
//

#ifndef USERFACTORY_H
#define USERFACTORY_H

#include "AbstractFactory.h"
#include "Admin.h"
#include "CommonUser.h"

class UserFactory:public AbstractFactory {
    User* createAdminFactory() override {
        return new Admin();
    }
    User* createCommonUserFactory() override{
        return new CommonUser();
    }
};

#endif //USERFACTORY_H
