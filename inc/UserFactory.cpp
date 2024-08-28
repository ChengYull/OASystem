//
// Created by Administrator on 24-8-28.
//
#include "UserFactory.h"
#include "Admin.h"
#include "CommonUser.h"

/*
 *TODO： 不能写这里？ 写这里报错
 *D:/Code/C++/OAsystem/inc/UserFactory.cpp:11: multiple definition of
 *`UserFactory::createAdminFactory()'; CMakeFiles/OASystem.dir/main.cpp.obj:
 *D:/Code/C++/OAsystem/inc/UserFactory.cpp:11: first defined here
 *User* UserFactory::createCommonUserFactory() {
    return new CommonUser();
}
User* UserFactory::createAdminFactory() {
    return new Admin();
}*/