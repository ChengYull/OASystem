//
// Created by Administrator on 24-9-1.
//

#include "MeetingRoomUtils.h"
#include "iostream"
#include <string>

#include "MeetingRoom.h"
#include "OAUtils.h"

MeetingRoomUtils::MeetingRoomUtils() {
    this->meetingRoomList = readFileToMeetingRoomList();
}

MeetingRoomUtils::~MeetingRoomUtils() {
    for(MeetingRoom* room:meetingRoomList) {
        delete room;
    }
}

bool MeetingRoomUtils::saveMeetingRoomInfoToFile(MeetingRoom *meetingRoom) {
    std::ofstream ofs(MEETING_ROOM_INFO_PATH,std::ios::out|std::ios::app);
    if(!ofs.is_open()) {
        std::cout << "文件打开失败" << std::endl;
        return false;
    }
    ofs << meetingRoom->id << " "
    << meetingRoom->size << " "
    << meetingRoom->status << std::endl;
    ofs.close();
    return true;
}

std::vector<MeetingRoom *> MeetingRoomUtils::readFileToMeetingRoomList() {
    std::vector<MeetingRoom *> list;
    std::ifstream ifs(MEETING_ROOM_INFO_PATH,std::ios::in);
    if(!ifs.is_open()) {
        std::cout<< "文件打开失败" << std::endl;
        return list;
    }
    std::string lineBuffer;
    std::vector<std::string> info;
    while(std::getline(ifs,lineBuffer)) {
        info = OAUtils::parseLine(lineBuffer);
        int id = stoi(info[0]);
        int size = stoi(info[1]);
        int status = stoi(info[2]);
        MeetingRoom *meetingRoom = new MeetingRoom(id,size,status);
        list.push_back(meetingRoom);
        info.clear();
    }
    ifs.close();
    return list;
}

bool MeetingRoomUtils::addMeetingRoom(MeetingRoom *meetingRoom) {
    this->meetingRoomList.push_back(meetingRoom);
    return saveMeetingRoomInfoToFile(meetingRoom);
}


void MeetingRoomUtils::showMeetingRoomTable() {
    if(meetingRoomList.size() > 0) {
        std::cout << "会议室编号" << "\t\t"
            << "会议室容量" << "\t\t"
            << "会议室状态" << std::endl;
        for(MeetingRoom* room:meetingRoomList) {
            room->display();
        }
    }else {
        cout << "找不到会议室列表..." << endl;
    }
}

bool MeetingRoomUtils::deleteMeetingRoomById(int id) {
    ofstream ofs(MEETING_ROOM_INFO_PATH,ios::out);
    if(!ofs.is_open()) {
        cout << "文件打开失败" << endl;
        return false;
    }
    bool find = false;
    for(auto iter = meetingRoomList.begin();iter != meetingRoomList.end();++iter) {
        if((*iter)->id == id) {
            find = true;
            //delete *iter;
            iter = meetingRoomList.erase(iter);
        }
        ofs << (*iter)->id << " "
            << (*iter)->size << " "
            << (*iter)->status << std::endl;
    }
    ofs.close();
    return find;
}

bool MeetingRoomUtils::ifIdExist(int id) {
    for(MeetingRoom* room:meetingRoomList) {
        if(id == room->id) {
            return true;
        }
    }
    return false;
}

void MeetingRoomUtils::resetBooking() {
    for(MeetingRoom* room:meetingRoomList) {
        if(2 == room->status) {
            room->status = 1;
        }
    }
}

std::vector<MeetingRoom *>::iterator MeetingRoomUtils::getById(int id) {
    for(auto it = meetingRoomList.begin();it != meetingRoomList.end();++it) {
        if(id == (*it)->id) {
            return it;
        }
    }
    return meetingRoomList.end();
}

bool MeetingRoomUtils::updateMeetingRoomFiel() {
    std::ofstream ofs(MEETING_ROOM_INFO_PATH,std::ios::out);
    if(!ofs.is_open()) {
        std::cout << "文件打开失败" << std::endl;
        return false;
    }
    for(MeetingRoom *meetingRoom:meetingRoomList) {
        ofs << meetingRoom->id << " "
            << meetingRoom->size << " "
            << meetingRoom->status << std::endl;
    }
    ofs.close();
    return true;
}

