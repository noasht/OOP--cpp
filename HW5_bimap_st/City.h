/* Assignment: 5
Author: Noa Shem Tov
 */

#ifndef BIMAP_H_CITY_H
#define BIMAP_H_CITY_H

#include <iostream>
# include <fstream>
using namespace std;

# define END_SIGN '\0'
# define ONE 1
# define ZERO 0
# define TWO_DEFUALT 2
# define NEG_ONE (-1)
# define A 'A'
# define A_SMALL 'a'
# define Z 'Z'
# define Z_SMALL 'z'
# define HYPHEN '-'
# define MAX_SIZE_STRING 30

template<class T>
class City {
private:
    char * NameC;
    long SizeC;
    T IDCity;

    char* stringCopy(const char* str)const;//copy the string
    long CheckSizeCity(long size)const;//check the size of the city
    char * DefaultString()const;//defoult string '\0'
    void InitializationCityName(char *NameCity);//Initialization the City's Name
    void Delete();//delete function

public:
    City();//default constructor
    City(const City<T> &CityToCopy);//copy constructor
    City(const T &IDCity,char *NameCity, long SizeCity);//constructor
    ~City();//destructor
    template<class U>friend fstream & operator >>(fstream &,City<U>&);//input
    template<class U>friend fstream & operator <<(fstream &,const City<U>&);//ouyput
    bool operator < (const City<T>& MapCity)const;//biiger
    bool operator == (const City<T>& MapCity)const;//equal
    bool operator != (const City<T>& MapCity)const;//different
    City<T>& operator = (const City<T>& MapCity);//assigning
    T GetId () const {return IDCity;}//get the ID
    long GetSizeCity () const {return SizeC;}//get size city
    char * GetNameCity () const { return NameC;}//get name city
    bool CheckString(const char* str)const;//check if the string is valid
    int stringLength(const char * str)const;//return the size of the string char *
};
template<class T>
City<T>::City()
{
    NameC = DefaultString();
    SizeC = NEG_ONE;
    IDCity = T();
}//default
template<class T>
char * City<T>::DefaultString()const
{
    char * temp = new char [ONE];
    temp[ZERO] = END_SIGN;
    return temp;//'\0'
}//DefaultString
template<class T>
City<T>::City(City<T> const &CityToCopy)
{
    this->IDCity = CityToCopy.IDCity;
    if(CheckString(CityToCopy.NameC))//if the string is valid then copy else do the default string
        this->NameC = stringCopy(CityToCopy.NameC);
    else this->NameC = DefaultString();
    this->SizeC = CheckSizeCity(CityToCopy.SizeC);
}//copy
template<class T>
long City<T>::CheckSizeCity(long size)const
{
    if(size < ZERO)//size can't be negative
        return NEG_ONE;
    return size;
}//CheckSizeCity
template<class T>
void City<T>::InitializationCityName(char * NameCity)
{
    Delete();//delete the string before
    if(CheckString(NameCity))//if the string is valid then copy else do the default string
        this->NameC = stringCopy(NameCity);
    else this->NameC = DefaultString();
}//InitializationCityName
template<class T>
City<T>::City( const T &IDCity,char *NameCity, long SizeCity)
{
    if(CheckString(NameCity))//if the string is valid then copy else do the default string
        this->NameC = stringCopy(NameCity);
    else this->NameC = DefaultString();
    this->SizeC = CheckSizeCity(SizeCity);
    this->IDCity = IDCity;
}//constructor
template<class T>
bool City<T>::CheckString(const char* str)const
{//only letters and - else false
    int size  = stringLength(str) - ONE;
    for (int i = ZERO; i < size; ++i)
    {
        if(str[i] < A || str[i] > Z)
            if(str[i] < A_SMALL || str[i] > Z_SMALL)
                if(str[i] != HYPHEN)
                    return false;
    }//if
    return true;
}//CheckString
template<class T>
void City<T>::Delete()
{
    delete [] NameC;
    NameC = nullptr;
}//Delete
template<class T>
City<T>::~City()
{
    Delete();
}//destructor
template<typename T>
fstream &operator<<(fstream &file, const City<T>& MapCity)
{
    file << "[" << MapCity.IDCity << "]";
    file << " " << MapCity.NameC << " ";
    file << MapCity.SizeC;
    return file;
}//output
template<class T>
fstream &operator>>(fstream& file,City<T>& MapCity)
{
    file >> MapCity.IDCity;
    string temp;
    file >> temp;//i tried to do it with char * but it doesn't went well so i changed to string
    long size;
    file >> size;
    int sizeStr = temp.length() + ONE;
    char * str = new char [sizeStr];
    for(int i = ZERO; i < sizeStr; i++)
        str[i] = temp[i];
    MapCity.InitializationCityName(str);
    MapCity.SizeC = MapCity.CheckSizeCity(size);
    delete [] str;
    return file;
}//input
template<class T>
bool City<T>::operator < (const City<T>& MapCity) const
{
    if(IDCity < MapCity.IDCity)
        return true;
    return false;
}//bigger
template<class T>
bool City<T>::operator == (const City<T>& MapCity)const
{
    if(IDCity == MapCity.IDCity)
        return true;
    return false;
}//equal
template<class T>
bool City<T>::operator != (const City<T>& MapCity) const
{
    if(IDCity != MapCity.IDCity)
        return true;
    return false;
}//Not Equal
template<class T>
City<T>& City<T>::operator = (const City<T>& MapCity)
{
    if(this == &MapCity)//if it is the same object
        return *this;
    InitializationCityName(MapCity.NameC);
    SizeC = CheckSizeCity(MapCity.SizeC);
    IDCity = MapCity.IDCity;
    return *this;
}//
template<class T>
char* City<T>::stringCopy(const char* str)const
{//string the string correctly the first letter and the letter after - must be uppercase and the rest loewcase
    int size = stringLength(str);
    if(size > ONE)
    {
        char * temp = new char[size];
        for (int i = ZERO; i < size; ++i)
        {
            if (i == ZERO || str[i - 1] == HYPHEN)
            {
                if (str[i] >= A_SMALL && str[i] <= Z_SMALL)
                    temp[i] = str[i] - (A_SMALL - A);
                else temp[i] = str[i];
            } //if
            else
            {
                if (str[i] != END_SIGN)
                {
                    if (str[i] >= A && str[i] <= Z)
                        temp[i] = str[i] + (A_SMALL - A);
                    else temp[i] = str[i];
                }
                else temp[i] = str[i];
            }//if
        }//for
        return temp;
    }//if
    return DefaultString();
}//stringCopy
template<class T>
int City<T>::stringLength(const char *str)const//return the size of the string
{
    int size = ZERO;
    while (str[size] != END_SIGN)
        size++;
    return size + ONE;
}//stringLength
#endif //BIMAP_H_CITY_H