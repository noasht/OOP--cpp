/* Assignment: 3
Author: Noa Shem Tov, ID: 207000134   */

#ifndef HW3_CLIENT_H
#define HW3_CLIENT_H

#include "MyString.h"

class Client {

protected:
    MyString ID;//ID of the client
    MyString FullName;//first and last name
    char Gender;//F for female M for male
    int Age;//at least 18
    char ** Hobbies;//array of hobbies
    int AmountHobbies;//the size of the array -> the hobbies amount

public:
    Client(const MyString& Id, const MyString& fullName,char gender,int age, char ** Hobby, int amountHobbies);//constructor by parameters
    Client(const Client & OtherClient);//copy constructor
    Client();//default constructor
    ~Client();//destructor
    Client& operator = (const Client & OtherClient);//assigning
    friend ostream &operator << (ostream &output, const Client& person);//print function
    virtual bool compatibility(const Client & MatchmakingOption)const;//check if the person sent to the function can match the current person
    int GetAmountHobbies()const{return AmountHobbies;}
    char ** GetHobbies()const{return Hobbies;}
    MyString GetID()const{return ID;}
    char GetGender()const{return Gender;}
    int GetAge()const{return Age;}

    MyString& assigningID(const MyString& Id);
    MyString& defaultID();
    MyString& assigningFullName(const MyString& fullName);
    bool isAllLetters(const char * string,int sizeString)const;
    MyString& defaultFullName();
    void assigningGender(char gender);
    void assigningAge(int age);
    char** assigningHobby(char ** Hobby,int amountHobbies);
    char** defaultHobby();
    void DeleteHobbies();
    bool OneHobbyInCommon(const char * stringOfThis, const char * stringOfAnother)const;
    virtual void Print(ostream &output)const;
};
#endif //HW3_CLIENT_H
