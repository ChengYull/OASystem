//
// Created by Administrator on 24-9-1.
//

#include "MeetingRoom.h"

#include <iostream>

MeetingRoom::MeetingRoom(int id, int size, int status):
        id(id),size(size),status(status){}


std::string MeetingRoom::getStatus() {
        switch (status) {
                case 0:
                        return "关闭";
                case 1:
                        return "可用";
                case 2:
                        return "已被预定";
                default:
                        return "状态未知";
        }
}

void MeetingRoom::display() {
        std::cout << id << "\t\t\t\t"
                << size << "\t\t\t\t"
                << getStatus() << std::endl;
}
