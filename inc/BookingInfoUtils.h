//
// Created by Administrator on 24-9-3.
//

#ifndef BOOKINGINFOUTILS_H
#define BOOKINGINFOUTILS_H
#include <vector>

#include "BookingInfo.h"


class BookingInfoUtils {
    std::string BOOKING_INFO_PATH = "../../data/bookingInfo.txt";

public:
    std::vector<BookingInfo*> bookingInfoList;
    BookingInfoUtils();
    bool saveBookingInfoToFile(BookingInfo *booking_info);
    std::vector<BookingInfo*> readBookInfoToList();
    bool addBookingInfo(BookingInfo *booking_info);
    int deleteBookingInfo(int bookingId);
    bool updateBookingInfoFile();
    void showBookingInfoTable(std::vector<BookingInfo*> list);
    void resetBookingInfo();
    BookingInfo* createBookingInfo(int meetingRoomId, std::string username, std::string dpt);
    std::vector<BookingInfo*> getBookingInfoListByUsername(std::string username);
};



#endif //BOOKINGINFOUTILS_H
