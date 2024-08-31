//
// Created by Administrator on 24-8-31.
//

#ifndef USERUTILS_H
#define USERUTILS_H

#include "User.h"
#include "AbstractFactory.h"
#include "vector"


class UserUtils {
public:
    string USER_SAVE_PATH = "../../data/user.txt";
    vector<User *> bufferUserList;
    AbstractFactory * userFactory;
    UserUtils();
    ~UserUtils();

    bool saveUserToFile(User *user);
    vector<User*> readFileToUserList();
    bool updateUserFile();
    vector<User*>::iterator getIterByUsername(string username);
    bool deleteUserByUsername(string username);
    User* login(string username,string password);
};



#endif //USERUTILS_H
