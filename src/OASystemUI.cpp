#include <iostream>

#include "../inc/OASystemUI.h"

#include "../inc/CommonUser.h"
#include "../inc/OAUtils.h"


using namespace std;

OASystemUI::OASystemUI() {
    loginUser = nullptr;
    user_utils = new UserUtils();
    meeting_room_utils = new MeetingRoomUtils();
    booking_info_utils = new BookingInfoUtils();
}

OASystemUI::~OASystemUI() {
    delete loginUser;
    delete user_utils;
    delete meeting_room_utils;
    delete booking_info_utils;
}

void OASystemUI::displayMainPage()
{
    while (true)
    {
        cout << "欢迎使用OA会议室预定系统" << endl;
        cout << "-----------------------" << endl;
        cout << "1.登录" << endl;
        cout << "2.退出系统" << endl;
        cout << "-----------------------" << endl;
        cout << "请输入您的选择：";

        // 让用户进行控制台输入选择
        int choice = OAUtils::inputNumber();

        switch (choice)
        {
            case 1:
                cout << "登录" << endl;
                loginPage();
            break;
            case 2:
                cout << "退出系统" << endl;
            goto end;

            default:
                break;
        }
    }
    end:
        cout << "欢迎下次使用" << endl;
}

void OASystemUI::loginPage() {
    cout << "----OA会议室预定系统----" << endl;
    cout << "-----------------------" << endl;
    cout << "登录:" << endl;
    cout << "请输入用户名:" ;
    string username;
    cin >> username;
    cout << "请输入密码：" ;
    string password;
    cin >> password;
    cout << "--------请稍等---------" << endl;
    User* user = user_utils->login(username,password);
    if(user != nullptr) {
        this->loginUser = user;
        cout << "欢迎你，" << user->getPermission() << endl;
        if(user->permission == 0) {
            commonUserPage();
        }else {
            adminPage();
        }
    }else {
        cout << "登录失败！" << endl;
    }

}

void OASystemUI::adminPage() {
    while(true) {
        cout << "----OA会议室预定系统----" << endl;
        cout << "--------管理员---------" << endl;
        cout << "1、添加用户" << endl;
        cout << "2、用户列表" << endl;
        cout << "3、删除用户" << endl;
        cout << "4、添加会议室" << endl;
        cout << "5、删除会议室" << endl;
        cout << "6、重置会议室预定" << endl;
        cout << "7、回到主页" << endl;
        cout << "----------------------" << endl;
        int choice = OAUtils::inputNumber();

        switch (choice){
            case 1:
                // 添加新用户
                addUserPage();
            break;
            case 2:
                cout << "--------用户列表---------" << endl;
                user_utils->showUserTable();
            break;
            case 3:
                // 删除用户
                deleteUserPage();
            break;
            case 4:
                //添加会议室
                addMeetingRoomPage();
            break;
            case 5:
                //删除会议室
                deleteMeetingRoomPage();
            break;
            case 6:
                //重置会议室预定
                resetMeetingRoomPage();
            break;
            case 7:
                cout << "回到主页" << endl;
            goto out_of_while;
            default:
                cout << "输入无效" << endl;
        }
    }
    out_of_while:

}

void OASystemUI::commonUserPage() {
    while(true) {
        cout << "----OA会议室预定系统----" << endl;
        cout << "-------普通用户--------" << endl;
        cout << "1、预定会议室" << endl;
        cout << "2、查看自己的预定" << endl;
        cout << "3、取消预定的会议室" << endl;
        cout << "4、回到主页" << endl;
        cout << "----------------------" << endl;
        int choice = OAUtils::inputNumber();

        switch (choice){
            case 1:
                //预定会议室
                bookingMeetingRoomPage();
            break;
            case 2:
                //查看自己的预定
                viewBookingInfoPage();
            break;
            case 3:
                //取消预定的会议室
                cancelBookingPage();
            break;
            case 4:
                cout << "回到主页" << endl;
                goto out_of_while;
            default:
                cout << "输入无效" << endl;
        }
    }
    out_of_while:
}

void OASystemUI::addUserPage() {
    cout << "--------添加用户---------" << endl;
    cout << "请输入新用户的ID：" << endl;
    int userId = OAUtils::inputNumber();
    while(user_utils->ifIdExist(userId)) {
        cout << "该id已存在，请重新输入：" << endl;
        userId = OAUtils::inputNumber();
    }
    cout << "请输入新用户的用户名：" << endl;
    string username;
    cin >> username;
    while(user_utils->ifUsernameExist(username)) {
        cout << "该用户名已存在，请重新输入：" << endl;
        cin >> username;
    }
    cout << "请输入新用户的密码：" << endl;
    string password;
    cin >> password;
    cout << "是否设其为管理员（0、否 1、是 ）：" << endl;
    int permission = OAUtils::inputNumber();
    int dptId = -1;
    if(!permission) {
        cout << "请选择用户部门：" << endl;
        cout <<"0、人事部  1、材料部  2、测试部  3、研发部"  << endl;
        dptId = OAUtils::inputNumber();
    }
    User * user = user_utils->userFactory->createUser(userId,username,password,
                                                permission,dptId);
    if(user_utils->addUser(user)) {
        cout << "添加成功！" << endl;
    }
}

void OASystemUI::deleteUserPage() {
    cout << "--------删除用户---------" << endl;
    cout << "请输入要删除用户的用户名：" << endl;
    string username;
    cin >> username;
    if(user_utils->deleteUserByUsername(username)) {
        cout << "成功删除该用户！" << endl;
    }

}

void OASystemUI::addMeetingRoomPage() {
    cout << "--------添加会议室-------" << endl;
    cout << "请输入会议室编号：" << endl;
    int id = OAUtils::inputNumber();
    while(meeting_room_utils->ifIdExist(id)) {
        cout << "该id已存在，请重新输入：" << endl;
        id = OAUtils::inputNumber();
    }
    cout << "请输入会议室容量：" << endl;
    int size = OAUtils::inputNumber();
    cout << "请选择会议室状态：" << endl;
    cout << "0、关闭  1、可用  2、已被预定" << endl;
    int status = OAUtils::inputNumber();
    MeetingRoom *room = new MeetingRoom(id,size,status);
    if(meeting_room_utils->addMeetingRoom(room)) {
        cout << "成功添加会议室：" << room->id << endl;
    }
}

void OASystemUI::deleteMeetingRoomPage() {
    cout << "--------删除会议室-------" << endl;
    cout << "会议室列表：" << endl;
    meeting_room_utils->showMeetingRoomTable();
    cout << "请输入要删除的会议室编号：" << endl;
    int id = OAUtils::inputNumber();
    if(meeting_room_utils->deleteMeetingRoomById(id)) {
        cout << "成功删除会议室：" << id << endl;
    }else {
        cout << "找不到该编号会议室" << endl;
    }
}

void OASystemUI::resetMeetingRoomPage() {
    cout << "--------重置会议室预定信息-------" << endl;
    cout << "确定重置会议室预定信息吗？（将会清除所有预定信息，并将被预定的会议室设为可用）" << endl;
    cout << "1、确认" << endl;
    cout << "2、取消" << endl;
    int choice = OAUtils::inputNumber();
    if(choice == 1) {
        // 清除预定信息
        booking_info_utils->resetBookingInfo();
        // 将被预定的会议室设为可用
        meeting_room_utils->resetBooking();
        cout << "成功清除所有预定信息，并将被预定的会议室设为可用" << endl;
    }else {
        cout << "取消重置操作！" << endl;
    }
}

void OASystemUI::bookingMeetingRoomPage() {
    cout << "--------预定会议室-------" << endl;
    cout << "会议室列表：" << endl;
    meeting_room_utils->showMeetingRoomTable();
    cout << "请输入要预定的会议室编号：" << endl;
    int room_id = OAUtils::inputNumber();
    auto iter = meeting_room_utils->getById(room_id);
    if(iter != meeting_room_utils->meetingRoomList.end()) {
        if((*iter)->status == 0 || (*iter)->status == 2) {
            cout << "该会议室暂时不可用" << endl;
        }else if((*iter)->status == 1) {
            // 修改会议室状态为 已被预定
            (*iter)->status = 2;
            // 更新文件信息
            meeting_room_utils->updateMeetingRoomFiel();
            BookingInfo* booking_info =booking_info_utils->createBookingInfo(
                room_id,
                loginUser->username,
                loginUser->getDepartment());
            if (booking_info_utils->addBookingInfo(booking_info)) {
                cout << "成功预定会议室：" << room_id << endl;
            }
        }else {
            cout << "该会议室状态异常" << endl;
        }
    }else {
        cout << "未找到该会议室：" << room_id << endl;
    }

}

void OASystemUI::viewBookingInfoPage() {
    cout << "--------我的预定-------" << endl;
    std::vector<BookingInfo*> myBookingList =
            booking_info_utils->getBookingInfoListByUsername(loginUser->username);
    booking_info_utils->showBookingInfoTable(myBookingList);
}

void OASystemUI::cancelBookingPage() {
    cout << "--------取消预定-------" << endl;
    cout << "请输入你要取消预定的预定编号：" << endl;
    int bookingId = OAUtils::inputNumber();
    std::vector<BookingInfo*> myBookingList =
            booking_info_utils->getBookingInfoListByUsername(loginUser->username);
    bool isMine = false;
    for(BookingInfo* info:myBookingList) {
        if(bookingId == info->bookingId) {
            isMine = true;
            break;
        }
    }
    if(!isMine) {
        cout << "这不是你预定的会议室" << endl;
        return;
    }
    int roomId = booking_info_utils->deleteBookingInfo(bookingId);
    if(roomId != -1) {
        auto meetingRoomIt = meeting_room_utils->getById(roomId);
        // 修改会议室状态为可用
        (*meetingRoomIt)->status = 1;
        // 更新文件内容
        if(meeting_room_utils->updateMeetingRoomFiel()) {
            cout << "取消预定" << roomId << "会议室成功！" << endl;
        }

    }else {
        cout << "取消预定发生错误！" << endl;
    }

}
