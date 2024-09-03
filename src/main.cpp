#include <iostream>


#include "../inc/BookingInfoUtils.h"
#include "../inc/MeetingRoomUtils.h"
#include "../inc/OASystemUI.h"
using namespace std;


int main()
{
    OASystemUI *OAUI = new OASystemUI();
    OAUI->displayMainPage();

    return EXIT_SUCCESS;
}