//
// Created by Administrator on 24-9-1.
//

#ifndef BOOKINGINFO_H
#define BOOKINGINFO_H
#include <string>


class BookingInfo {
public:
    int bookingId;
    int meetingRoomId;
    std::string username;
    std::string userDepartment;
    BookingInfo(int id,int MeetingRoomId,std::string username,std::string dpt);
    void dispaly();
};



#endif //BOOKINGINFO_H
