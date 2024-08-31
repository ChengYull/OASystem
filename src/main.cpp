#include <iostream>


#include "../inc/MeetingRoomUtils.h"
#include "../inc/OASystemUI.h"
using namespace std;


int main()
{
    //OASystemUI *OAUI = new OASystemUI();
    //OAUI->displayMainPage();
    MeetingRoom * room = new MeetingRoom(703,60,3);

    MeetingRoomUtils *util = new MeetingRoomUtils();
    //util->addMeetingRoom(room);
    if(!util->deleteMeetingRoomById(705)) {
        cout << "删除失败" <<endl;
    }
    util->showMeetingRoomTable();
    return EXIT_SUCCESS;
}