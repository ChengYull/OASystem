//
// Created by Administrator on 24-8-28.
//

#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

class User {
public:
    int id;
    string username;
    string password;
    int permission;
    int departmentId;
    User();

    virtual ~User();
    bool login(string username,string password);
    virtual string getPermission() = 0;

};



#endif //USER_H
