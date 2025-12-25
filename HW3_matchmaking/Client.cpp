/* Assignment: 3
Author: Noa Shem Tov, ID: 207000134   */

#include "Client.h"
#define LIMIT_AGE 18
#define NINE 9
#define MALE 'M'
#define FEMALE 'F'
#define SMALL_FEMALE 'f'
#define SMALL_MALE 'm'
#define ZERO_CHAR '0'
#define NINE_CHAR '9'
#define DEFAULT_ID "123456789"
#define UPPER_A 'A'
#define LOWER_A 'a'
#define UPPER_Z 'Z'
#define LOWER_Z 'z'
#define SPACE ' '
#define HYPHEN '-'
#define DEFAULT_FULL_NAME "Israel Israeli"
#define VALID_HOBBY 'Y'
#define NOT_VALID_HOBBY 'N'
#define DEFAULT_SIZE_HOBBY 2
#define DEFAULT_HOBBY_1 "Reading"
#define DEFAULT_SIZE_HOBBY_1 8
#define DEFAULT_HOBBY_2 "Swimming"
#define DEFAULT_SIZE_HOBBY_2 9
#define MAX_AGE_DIFFERENCE 5
#define NEG_MAX_AGE_DIFFERENCE (-5)

Client::Client(const MyString& Id, const MyString& fullName,char gender,int age, char ** Hobby, int amountHobbies)//constructor by parameters
{
    assigningID(Id);//assigning of id
    assigningFullName(fullName);//assigning of fullName
    assigningGender(gender);//assigning of gender
    assigningAge(age);//assigning of age
    Hobbies = assigningHobby(Hobby,amountHobbies);
}//constructor
MyString& Client::assigningID(const MyString& Id)
{
    if(Id.GetObjectStr() == nullptr || Id.GetObjectStr()[ZERO] == END_SIGN )//check if there is object
        return defaultID();
    int sizeID =(int)(strlen(Id.GetObjectStr()));//the amount of the char need to be 9 because it's ID
    if (sizeID != NINE)//ID need to be with 9 digit because it is a string, the zeros at the beginning also exist, so there must be 9 digits
       return defaultID();
    for(int i = ZERO; i < NINE; i++)//check if all the characters are digit
    {
        if((Id.GetObjectStr())[i] < ZERO_CHAR || (Id.GetObjectStr())[i] > NINE_CHAR)
            return defaultID();
    }//for
    this->ID = Id;
    return this->ID;
}//assigningID
MyString& Client::defaultID()
{
    char defStr [] = DEFAULT_ID;
    ID.SetObjectStr(ID.creatString(defStr));
    return ID;
}//defaultID
MyString& Client::assigningFullName(const MyString& fullName)
{
    if(fullName.GetObjectStr() == nullptr)//if there is no name
        return defaultFullName();
    int sizeFullName = (int)(strlen(fullName.GetObjectStr()));//the size of the name
    if(!(isAllLetters(fullName.GetObjectStr(),sizeFullName)))//if there is a digit or another char that don't need to be in name
        return defaultFullName();
    this->FullName = fullName;//of the MyString class
    return this->FullName;
}//assigningFullName
bool Client::isAllLetters(const char * string, int sizeString) const
{
    if(sizeString <= ONE)
        return false;//one char cant be name or hobby or if the person type \n
    for(int i = ZERO; i < sizeString; ++i)//check if the hobby/name don't include non needed char
    {
        if(string[i] < UPPER_A || string[i] > UPPER_Z )
            if(string[i] < LOWER_A || string[i] > LOWER_Z)
                if(string[i] != HYPHEN)
                    if(string[i] != SPACE)
                        return false;
    }//for
    return true;
}//isAllLetters
MyString&  Client::defaultFullName()
{
    char defStr [] = DEFAULT_FULL_NAME;
    FullName.SetObjectStr(FullName.creatString(defStr));
    return FullName;
}//defaultFullName
void Client::assigningGender(char gender)
{
    if(gender != FEMALE && gender != SMALL_FEMALE)
        if(gender != MALE && gender != SMALL_MALE)
        {
            this->Gender = MALE;//the default option
            return;
        }//if
    if(gender == FEMALE || gender == SMALL_FEMALE)
        this->Gender = FEMALE;
    else this->Gender = MALE;
}//assigningGender
void Client::assigningAge(int age)
{
    if(age < LIMIT_AGE)
    {
        this->Age = LIMIT_AGE;
        return;
    }//if
    this->Age = age;
}//assigningAge
char ** Client::assigningHobby(char ** Hobby,int amountHobbies)//hobby need to be more than one char and not include digits or @ etc.
{
    if(amountHobbies == ZERO)
        return defaultHobby();
    int sizeOfHobby = ZERO;//the amount of the valid hobbies
    char * ArrOFHobbyValid = new char [amountHobbies];//an array in which, which cell to copy is indicated after checking that the hobby is correct
    for(int i = ZERO; i < amountHobbies; i++)
    {
        if(Hobby[i] == nullptr || !(isAllLetters(Hobby[i], (int)(strlen(Hobby[i])))))
            ArrOFHobbyValid[i] = NOT_VALID_HOBBY;
        else
        {
            sizeOfHobby++;
            ArrOFHobbyValid[i] = VALID_HOBBY;
        }//else
    }//for
    if(sizeOfHobby == ZERO)//there is no hobby valid
    {
        delete [] ArrOFHobbyValid;//delete the array that created
        ArrOFHobbyValid = nullptr;
        return defaultHobby();
    }//if
    char ** NewArrOfHobby = new char * [sizeOfHobby];//the list of hobbies for the object this
    if(sizeOfHobby == amountHobbies)//every hobby was valid
    {
        delete [] ArrOFHobbyValid;//deleted the array that marked which cell need to be copied
        for(int i = ZERO; i < sizeOfHobby; i++)
        {
           int sizeCurrenHobby = (int)(strlen(Hobby[i]));//the size of the hobby
           NewArrOfHobby[i] = new char [sizeCurrenHobby + ONE];//+ one for the end sign in string \0
           strcpy(NewArrOfHobby[i],Hobby[i]);//copy the hobby
        }//for
        AmountHobbies = sizeOfHobby;//set the amount
        return NewArrOfHobby;//return the new list of hobbies
    }//if
    //if not all the hobby were valid
    int index = ZERO;//the index in the arrays the one who created and the one that received
    for(int i = ZERO; i < sizeOfHobby; i++)
    {
        while(ArrOFHobbyValid[index] == NOT_VALID_HOBBY)//looking for the cell that need to be copied
            index++;
        int sizeCurrenHobby = (int)(strlen(Hobby[index]));//the size of the hobby
        NewArrOfHobby[i] = new char [sizeCurrenHobby + ONE];//+ one for the end sign in string \0
        strcpy(NewArrOfHobby[i],Hobby[index]);//copy the hobby
        index++;//step forward for the next cell
    }//for
    delete [] ArrOFHobbyValid;//deleted the array that marked which cell need to be copied
    AmountHobbies = sizeOfHobby;//set the amount
    return NewArrOfHobby;//return the new list of hobbies
}//assigningHobby
char ** Client::defaultHobby()
{
    char ** DefaultHobbies = new char * [DEFAULT_SIZE_HOBBY];//default list
    DefaultHobbies[ZERO] = new char [DEFAULT_SIZE_HOBBY_1];//default hobby
    char defaultStr1 [] = DEFAULT_HOBBY_1;
    strcpy(DefaultHobbies[ZERO],defaultStr1);
    char defaultStr2 [] = DEFAULT_HOBBY_2;
    DefaultHobbies[ONE] = new char [DEFAULT_SIZE_HOBBY_2];
    strcpy(DefaultHobbies[ONE],defaultStr2);
    this->AmountHobbies = DEFAULT_SIZE_HOBBY;
    return DefaultHobbies;
}//defaultHobby
Client::Client(const Client & OtherClient)//copy constructor
{
    assigningID(OtherClient.ID );
    assigningFullName(OtherClient.FullName);
    assigningGender(OtherClient.Gender);
    assigningAge(OtherClient.Age);
    Hobbies =  assigningHobby(OtherClient.Hobbies, OtherClient.AmountHobbies);
}//copy constructor
Client::Client()
{
    defaultID();
    defaultFullName();
    Gender = FEMALE;
    Age = LIMIT_AGE;
    Hobbies = defaultHobby();
}//default constructor
Client::~Client()//destructor
{
    DeleteHobbies();
}//destructor
void Client::DeleteHobbies()
{
    for(int i = ZERO; i < AmountHobbies; i++)
    {
        delete [] Hobbies[i];
        Hobbies[i] = nullptr;
    }//for
    delete [] Hobbies;
    Hobbies = nullptr;
}
Client& Client::operator = (const Client & OtherClient)//assigning
{
    if(this == &OtherClient)
        return *this;
    this->ID = OtherClient.ID;//= MyString class
    this->FullName = OtherClient.FullName;//= MyString class
    Gender = OtherClient.Gender;
    Age = OtherClient.Age;
    DeleteHobbies();//first need to delete the list
    Hobbies = assigningHobby(OtherClient.Hobbies,OtherClient.AmountHobbies);
    return *this;
}//assigning
bool Client::compatibility(const Client & MatchmakingOption)const//check if the person sent to the function can match the current person
{
    if(Gender == MatchmakingOption.Gender)//check the gender
        return false;
    if(Age - MatchmakingOption.Age < NEG_MAX_AGE_DIFFERENCE || Age - MatchmakingOption.Age > MAX_AGE_DIFFERENCE)//only 5 years of difference
        return false;
    int AmountOfHobbiesThis = AmountHobbies;
    int AmountOfHobbiesAnother = MatchmakingOption.AmountHobbies;
    for(int i = ZERO; i < AmountOfHobbiesThis; i++)//only one hobby is good
    {
        for(int j = ZERO; j <  AmountOfHobbiesAnother; j++)
            if(OneHobbyInCommon(this->Hobbies[i],MatchmakingOption.Hobbies[j]))
                return true;
    }//for
    return false;//there is no hobby in common
}//compatibility
bool Client::OneHobbyInCommon(const char * stringOfThis, const char * stringOfAnother)const
{
    int sizeOfThis = (int)(strlen(stringOfThis));//the size need to be tha same
    int SizeOfAnother = (int)(strlen(stringOfAnother));
    if(sizeOfThis != SizeOfAnother)//if not false
        return false;
    for(int i = ZERO; i < sizeOfThis; i++)
    {
        if(stringOfThis[i] != stringOfAnother[i])//each cell need to be equal
            return false;
    }//for
    return true;
}//OneHobbyInCommon
ostream &operator << (ostream &output, const Client& person)//print function
{
    person.Print(output);
    return output;
}//operator << Client
void Client::Print(ostream &output)const
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
    output<<endl;
}