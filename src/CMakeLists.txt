cmake_minimum_required(VERSION 3.28)
project(OASystem)

set(CMAKE_CXX_STANDARD 11)

add_executable(OASystem
        OAUtils.cpp
        ../inc/OASystemUI.h
        ../inc/OAUtils.h
        OASystemUI.cpp
        main.cpp
        ../inc/User.h
        ../inc/CommonUser.h
        ../inc/User.cpp
        ../inc/Admin.h
        ../inc/CommonUser.cpp
        ../inc/Admin.cpp
        ../inc/AbstractFactory.h
        ../inc/UserFactory.h
        ../inc/UserFactory.cpp
        ../inc/UserUtils.cpp
        ../inc/UserUtils.h
        ../inc/MeetingRoom.cpp
        ../inc/MeetingRoom.h
        ../inc/MeetingRoomUtils.cpp
        ../inc/MeetingRoomUtils.h
        ../inc/BookingInfo.cpp
        ../inc/BookingInfo.h
        ../inc/BookingInfoUtils.cpp
        ../inc/BookingInfoUtils.h
)
