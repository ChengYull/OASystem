//
// Created by Administrator on 24-9-1.
//

#ifndef MEETINGROOMUTILS_H
#define MEETINGROOMUTILS_H
#include <vector>

#include "fstream"
#include "MeetingRoom.h"

class MeetingRoomUtils {
public:
    std::string MEETING_ROOM_INFO_PATH = "../../data/meetingRoom.txt";
    std::vector<MeetingRoom*> meetingRoomList;
    MeetingRoomUtils();
    ~MeetingRoomUtils();
    bool saveMeetingRoomInfoToFile(MeetingRoom *meetingRoom);
    std::vector<MeetingRoom*> readFileToMeetingRoomList();
    bool addMeetingRoom(MeetingRoom *meetingRoom);
    void showMeetingRoomTable();
    bool deleteMeetingRoomById(int id);
};



#endif //MEETINGROOMUTILS_H
