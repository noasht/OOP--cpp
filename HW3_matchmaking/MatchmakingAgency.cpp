/* Assignment: 3
Author: Noa Shem Tov, ID: 207000134   */

#include "MatchmakingAgency.h"
MatchmakingAgency::MatchmakingAgency()
{
    ArrOfClient = nullptr;
    AmountOfClient = ZERO;
}//MatchmakingAgency
MatchmakingAgency::~MatchmakingAgency()
{
    DeleteAgency();
}//~MatchmakingAgency
void MatchmakingAgency::DeleteAgency()
{
    if(ArrOfClient != nullptr)
    {
        for(int i = ZERO; i < AmountOfClient; i++)
            delete ArrOfClient[i];
        delete[] ArrOfClient;
        ArrOfClient = nullptr;
    }//if
    AmountOfClient = ZERO;
}//DeleteAgency
bool MatchmakingAgency::searchByID(const MyString & ID)const
{
    Client * ThePerson = IsPersonFound(ID);//this function returned the address of the object or null
    if(ThePerson == nullptr)
        return false;//this id doesn't exist
    int i = ZERO;
    int counter = ZERO;
    for(i = ZERO; i < AmountOfClient; i++)
    {
        if(ThePerson->compatibility(*ArrOfClient[i]))//check the requirement
        {
            cout <<endl<< "There is a match"<<endl;
            cout<< *ArrOfClient[i];
            counter++;
        }//if
    }//for
    if(counter == ZERO)//not was a match
        return false;
    return true;
}//searchByID
ostream &operator<<(ostream &os, const MatchmakingAgency& Agency)
{
    if(Agency.ArrOfClient != nullptr)
    {
        for(int i = ZERO; i < Agency.AmountOfClient ; i++)
            os << *(Agency.ArrOfClient[i]);//<< of Client
    }//if
    return os;
}//operator << - print
MatchmakingAgency& MatchmakingAgency::operator += (Client& clientToAdd)
{
    Client * ThePerson = IsPersonFound(clientToAdd.GetID());//check if the person already in the system
    if(ThePerson == nullptr)//only if not it adds to the system
    {
        Client **NewArrAgency = new Client *[AmountOfClient + ONE];//create new +1
        for (int i = ZERO; i < AmountOfClient; i++)
            NewArrAgency[i] = ArrOfClient[i];
        NewArrAgency[AmountOfClient] = &(clientToAdd);//the new object that add to the agency
        if (AmountOfClient != ZERO)//if is not  the first adding
            delete [] ArrOfClient;
        AmountOfClient++;
        ArrOfClient = NewArrAgency;
    }//IF
    return *this;
}//add
MatchmakingAgency& MatchmakingAgency::operator += (VIPClient& clientToAdd)
{
    Client * ThePerson = IsPersonFound(clientToAdd.GetID());//check if the person already in the system
    if(ThePerson == nullptr)//only if not it adds to the system
    {
        Client **NewArrAgency = new Client *[AmountOfClient + ONE];//create new +1
        for (int i = ZERO; i < AmountOfClient; i++)
            NewArrAgency[i] = ArrOfClient[i];
        NewArrAgency[AmountOfClient] = &(clientToAdd);//the new object that add to the agency
        if (AmountOfClient != ZERO)//if is not  the first adding
            delete [] ArrOfClient;
        AmountOfClient++;
        ArrOfClient = NewArrAgency;
    }//IF
    return *this;
}//add
Client* MatchmakingAgency::IsPersonFound(const MyString& ID)const
{
    Client * ThePerson = nullptr;
    if(ArrOfClient == nullptr)//there is no Agency
        return nullptr;
    int i = ZERO;
    while (ThePerson == nullptr && i < AmountOfClient)//until he finds the person or the end of the array
    {
        if (this->ArrOfClient[i]->GetID() == ID)//== of MyString
            ThePerson = ArrOfClient[i];
        i++;
    }//while
    return ThePerson;
}//IsPersonFound
MatchmakingAgency& MatchmakingAgency::operator -= (const Client& clientToRemove)
{
    if(ArrOfClient == nullptr)//if there is no agency
        return *this;
    Client * ThePerson = IsPersonFound(clientToRemove.GetID());//if the person exist
    if(ThePerson == nullptr)
        return *this;
    if(AmountOfClient > ONE)
    {
        int i = ZERO;
        while (i < AmountOfClient)
        {
            if(ArrOfClient[i]->GetID() == clientToRemove.GetID())//check the ID
            {
                delete ArrOfClient[i];
                ArrOfClient[i] = nullptr;
                SetTheArr();//create new agency without the person who deleted
                return *this;//returned the new agency
            }//if
            i++;
        }//while
    }//if
    DeleteAgency();//if was only one client that left there is no agency anymore
    AmountOfClient = ZERO;
    return *this;
}//remove
MatchmakingAgency& MatchmakingAgency::operator -= (const VIPClient& clientToRemove)
{
    if(ArrOfClient == nullptr)//if there is no agency
        return *this;
    Client * ThePerson = IsPersonFound(clientToRemove.GetID());//if the person exist
    if(ThePerson == nullptr)
        return *this;
    if(AmountOfClient > ONE)
    {
        int i = ZERO;
        while (i < AmountOfClient)
        {
            if(ArrOfClient[i]->GetID() == clientToRemove.GetID())//check the ID
            {
                delete  ArrOfClient[i];
                ArrOfClient[i] = nullptr;
                SetTheArr();//create new agency without the person who deleted
                return *this;//returned the new agency
            }//if
            i++;
        }//while
    }//if
    DeleteAgency();//if was only one client that left there is no agency anymore
    AmountOfClient = ZERO;
    return *this;
}//remove
void MatchmakingAgency::SetTheArr()
{
    Client ** NewAgency = new Client * [AmountOfClient - ONE];//the size is -1
    int j = ZERO;//walks on this array
    int i = ZERO;//on the new array
    while(i < AmountOfClient - ONE)
    {
        if (ArrOfClient[j] != nullptr)//if is not the person who deleted then copy
        {
            NewAgency[i] = ArrOfClient[j];
            ArrOfClient[j] = nullptr;
            i++;//move to the next cell only after assigning
        }//if
        j++;//move to next cell
    }//for
    delete [] ArrOfClient;//delete the prev array
    ArrOfClient = NewAgency;//get the new one
    AmountOfClient--;//the amount down in 1
}//deleteClient