/* Assignment: 3
Author: Noa Shem Tov, ID: 207000134   */

#include "VIPClient.h"
#define FEMALE 'F'
#define MAX_AGE_DIFFERENCE 5
#define NEG_MAX_AGE_DIFFERENCE (-5)

VIPClient::VIPClient(const MyString& Id, const MyString& fullName,char gender,int age, char ** Hobby, int amountHobbies, int NumberCommonInterests)
:Client(Id,fullName,gender,age,Hobby, amountHobbies)
{
    if(NumberCommonInterests < ONE || this->AmountHobbies < NumberCommonInterests)//if is not a valid amount = negative number or the person cant ask a number of hobbies that bigger than his amount of hobby
        this->NumberCommonInterests = this->AmountHobbies;
    else
        this->NumberCommonInterests = NumberCommonInterests;
}//constructor
bool VIPClient::compatibility(const Client& MatchOption)const
{
    int amountOfHobbiesOFMatch = MatchOption.GetAmountHobbies();//the amount of the person that the match has
    if(amountOfHobbiesOFMatch < NumberCommonInterests)//if it's smaller than the requirement there is no point to check
        return false;
    if(this->Age - MatchOption.GetAge() > MAX_AGE_DIFFERENCE || NEG_MAX_AGE_DIFFERENCE > this->Age - MatchOption.GetAge())
        return false;
    if(this->Gender == MatchOption.GetGender())//check the same gender
        return false;
    int counter = ZERO;//count the number of common interests
    for(int i = ZERO; i < this->AmountHobbies && counter < NumberCommonInterests ; i++)
    {
        for(int j = ZERO; j < amountOfHobbiesOFMatch && counter < NumberCommonInterests; j++)
        {
            if(OneHobbyInCommon(Hobbies[i], MatchOption.GetHobbies()[j]))//if the hobby are the same
                counter++;
        }//for
    }//for
    if(counter == NumberCommonInterests )//if is answerer on the requirement, else false
        return true;
    return false;
}//compatibility
void VIPClient::Print(ostream &output)const
{
    output <<"The details about the client" << endl;
    output << "The name of the client is: ";
    output << FullName.GetObjectStr()<<endl;
    output<< "The gender is: ";
    if(Gender == FEMALE)
        output<<"FEMALE"<<endl;
    else  output<<"MALE"<<endl;
    output <<"ID : "<<ID.GetObjectStr()<<endl;
    output<<"Age :" <<Age<<endl;
    output<<"The "<< AmountHobbies <<" Hobbies are: "<<endl;
    for(int i = ZERO; i < AmountHobbies; i++)
         output<< i+1 << " - "<<Hobbies[i]<<endl;
    output<< "This client is VIP Client"<<endl<<endl;
}//print function