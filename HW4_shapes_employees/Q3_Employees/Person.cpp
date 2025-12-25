/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#include "Person.h"

int Person::AmountOfPersons = ZERO;

Person::Person(char * Name, long ID)
{
    if(Name != nullptr && ValidName(Name))//name must be more than one letter and not included digit or something like that
    {
        this->Name = new char[strlen(Name) + ONE];
        strcpy(this->Name, Name);
    }//if
    else
    {
        this->Name = new char[DEFAULT_SIZE];
        strcpy(this->Name, NAME);
    }//else
    if(ValidID(ID))//ID must have 7 (for the very old people) until 9 digits
        this->ID = ID;
    else this->ID = ID_NUMBER;
    AmountOfPersons++;
}//constructor
bool Person::ValidID( long ID)const
{
    int counter = ZERO;
    while (ID != ZERO)
    {
        counter++;
        ID /= TEN;
    }//while
    if(counter < SEVEN || counter > NINE)//for the older people they have 7 digit the minimum amount and nine is the maximum
        return false;
    return true;
}//ValidID
bool Person::ValidName( char * Name)const
{
    int sizeName = strlen(Name);
    if(sizeName == ONE)//name cant be one letter
        return false;
    for(int i = ZERO; i < sizeName; i++)
    {
        if(Name[i] < A_LOWERCASE || Name[i] > Z_LOWERCASE )
            if(Name[i] < A_UPPERCASE ||Name[i] > Z_UPPERCASE)
                if(Name[i] != SPACE)
                    if(Name[i] != HYPHEN)
                        return false;
    }//for
    return true;
}//validName
Person::Person(const Person & PersonToCopy)
{
    if(PersonToCopy.Name != nullptr && ValidName(Name))//only if the name is valid
    {
        this->Name = new char[strlen(PersonToCopy.Name) + ONE];
        strcpy(this->Name, Name);
    }//if
    else
    {
        this->Name = new char[DEFAULT_SIZE];
        strcpy(this->Name, NAME);
    }//else
    if(ValidID(PersonToCopy.ID))//only if the ID is valid
        this->ID = PersonToCopy.ID;
    else this->ID = ID_NUMBER;
    AmountOfPersons++;
}//copy constructor
Person::~Person()
{
    delete [] this->Name;
    this->Name = nullptr;
}//destructor