#pragma once
#include "BookingInfoUtils.h"
#include "MeetingRoomUtils.h"
#include "../inc/UserUtils.h"

class OASystemUI
{
public:
    OASystemUI();
    ~OASystemUI();
    UserUtils *user_utils;
    MeetingRoomUtils *meeting_room_utils;
    BookingInfoUtils *booking_info_utils;
    User *loginUser;
    void displayMainPage();
    void loginPage();
    void adminPage();
    void commonUserPage();

    void addUserPage();
    void deleteUserPage();
    void addMeetingRoomPage();
    void deleteMeetingRoomPage();
    void resetMeetingRoomPage();

    void bookingMeetingRoomPage();
    void viewBookingInfoPage();
    void cancelBookingPage();
};
