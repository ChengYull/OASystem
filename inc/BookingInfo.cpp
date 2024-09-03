//
// Created by Administrator on 24-9-1.
//

#include "BookingInfo.h"
#include "iostream"
BookingInfo::BookingInfo(int id, int meetingRoomId, std::string username, std::string dpt) {
    this->bookingId = id;
    this->meetingRoomId = meetingRoomId;
    this->username = username;
    this->userDepartment = dpt;
}

void BookingInfo::dispaly() {
    std::cout << bookingId << "\t\t" <<meetingRoomId << "\t\t\t"
            << username << "\t\t" << userDepartment << std::endl;
}
