/* Assignment: 3
Author: Noa Shem Tov, ID: 207000134   */

#ifndef HW3_MATCHMAKINGAGENCY_H
#define HW3_MATCHMAKINGAGENCY_H

#include "VIPClient.h"

class MatchmakingAgency {

private:
    Client ** ArrOfClient;
    int AmountOfClient;

public:
    MatchmakingAgency();
    ~MatchmakingAgency();
    void DeleteAgency();
    void SetTheArr();//make new array and minus 1 for the amount
    Client ** GetArrOfClient() const {return ArrOfClient;}
    bool searchByID(const MyString& ID)const;
    Client* IsPersonFound(const MyString& ID)const;//returned the address or null
    friend ostream &operator<<(ostream &os, const MatchmakingAgency& Agency);
    MatchmakingAgency& operator += (Client& clientToAdd);//adding
    MatchmakingAgency& operator += (VIPClient& clientToAdd);//adding
    MatchmakingAgency& operator -= (const Client& clientToRemove);//removing
    MatchmakingAgency& operator -= (const VIPClient& clientToRemove);
};
#endif //HW3_MATCHMAKINGAGENCY_H
