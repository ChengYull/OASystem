#include <iostream>


#include "../inc/BookingInfoUtils.h"
#include "../inc/MeetingRoomUtils.h"
#include "../inc/OASystemUI.h"
using namespace std;


int main()
{
    //OASystemUI *OAUI = new OASystemUI();
    //OAUI->displayMainPage();

    BookingInfoUtils *utils = new BookingInfoUtils();
    BookingInfo *info = new BookingInfo(90,702,"user3","材料部");
    //utils->addBookingInfo(info);
    utils->deleteBookingInfo(93);
    utils->showBookingInfoTable(utils->bookingInfoList);

    return EXIT_SUCCESS;
}