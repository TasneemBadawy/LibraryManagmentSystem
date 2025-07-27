#ifndef USER_H
#define USER_H

#include <string>

class User {
    std::string FullName;
    std::string UserId;
    std::string PhoneNumber;
    std::string Email;
    int money = 0;

public:
    void SetName(std::string name);
    void SetUserId(std::string id);
    void SetPhoneNumber(std::string phone);
    void SetEmail(std::string email);
    void AddPayment(int price);
    int GetMoney();
};

#endif 
