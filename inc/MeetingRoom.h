//
// Created by Administrator on 24-9-1.
//

#ifndef MEETINGROOM_H
#define MEETINGROOM_H
#include <string>


class MeetingRoom {
public:
    int id;
    int size;
    int status;
    MeetingRoom() = default;
    MeetingRoom(int id,int size,int status);

    std::string getStatus();
    void display();
};



#endif //MEETINGROOM_H
