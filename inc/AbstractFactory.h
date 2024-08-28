//
// Created by Administrator on 24-8-28.
//

#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "User.h"
class AbstractFactory {
public:
    virtual ~AbstractFactory() {};

    virtual User* createCommonUserFactory() = 0;
    virtual User* createAdminFactory() = 0;
};
#endif //ABSTRACTFACTORY_H
