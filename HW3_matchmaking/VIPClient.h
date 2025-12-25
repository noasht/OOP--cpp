/* Assignment: 3
Author: Noa Shem Tov, ID: 207000134   */

#ifndef HW3_VIPCLIENT_H
#define HW3_VIPCLIENT_H

#include "Client.h"

class VIPClient : public Client{

private:
    int NumberCommonInterests;

public:
    VIPClient(const MyString& Id, const MyString& fullName,char gender,int age, char ** Hobby, int amountHobbies, int NumberCommonInterests);
    virtual bool compatibility(const Client& MatchOption)const;
    void Print(ostream &output)const;
};
#endif //HW3_VIPCLIENT_H
