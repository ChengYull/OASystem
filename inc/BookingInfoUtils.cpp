//
// Created by Administrator on 24-9-3.
//

#include "BookingInfoUtils.h"
#include "fstream"
#include "iostream"
#include "OAUtils.h"

BookingInfoUtils::BookingInfoUtils() {
    this->bookingInfoList = readBookInfoToList();
}

bool BookingInfoUtils::saveBookingInfoToFile(BookingInfo *booking_info) {
    std::ofstream ofs(this->BOOKING_INFO_PATH,std::ios::out|std::ios::app);
    if(!ofs.is_open()) {
        std::cout << "文件打开失败：" << this->BOOKING_INFO_PATH << std::endl;
        return false;
    }
    ofs << booking_info->bookingId << " "
        << booking_info->meetingRoomId << " "
        << booking_info->username << " "
        << booking_info->userDepartment << std::endl;
    ofs.close();
    return true;
}

bool BookingInfoUtils::updateBookingInfoFile() {
    std::ofstream ofs(this->BOOKING_INFO_PATH,std::ios::out);
    if(!ofs.is_open()) {
        std::cout << "文件打开失败：" << this->BOOKING_INFO_PATH << std::endl;
        return false;
    }
    for(BookingInfo* booking_info:this->bookingInfoList) {
        ofs << booking_info->bookingId << " "
        << booking_info->meetingRoomId << " "
        << booking_info->username << " "
        << booking_info->userDepartment << std::endl;
    }
    ofs.close();
    return true;
}



std::vector<BookingInfo *> BookingInfoUtils::readBookInfoToList() {
    std::vector<BookingInfo *> list;
    std::ifstream ifs(this->BOOKING_INFO_PATH,std::ios::in);
    if(!ifs.is_open()) {
        std::cout << "文件打开失败：" << this->BOOKING_INFO_PATH << std::endl;
        return list;
    }
    std::string lineBuffer;
    std::vector<std::string> info;
    while(std::getline(ifs,lineBuffer)) {
        info = OAUtils::parseLine(lineBuffer);
        int bookingId = stoi(info[0]);
        int meetingRoomId = stoi(info[1]);
        string username = info[2];
        string userDpt = info[3];
        BookingInfo *booking_info =
            new BookingInfo(bookingId,meetingRoomId,username,userDpt);
        list.push_back(booking_info);
        info.clear();
    }
    ifs.close();
    return list;
}

bool BookingInfoUtils::addBookingInfo(BookingInfo *booking_info) {
    this->bookingInfoList.push_back(booking_info);
    return saveBookingInfoToFile(booking_info);
}

bool BookingInfoUtils::deleteBookingInfo(int bookingId) {
    for(auto it = bookingInfoList.begin();it != bookingInfoList.end();++it) {
        if(bookingId == (*it)->bookingId) {
            bookingInfoList.erase(it);
            break;
        }
    }
    return updateBookingInfoFile();
}

void BookingInfoUtils::showBookingInfoTable(std::vector<BookingInfo *> list) {
    std::cout << "预定编号\t" << "会议室编号\t" << "用户名\t\t"<<"用户部门" << std::endl;
    for(BookingInfo* info:list) {
        info->dispaly();
    }
}