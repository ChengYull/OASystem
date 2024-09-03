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
    bool deleteBookingInfo(int bookingId);
    bool updateBookingInfoFile();
    void showBookingInfoTable(std::vector<BookingInfo*> list);
};



#endif //BOOKINGINFOUTILS_H
