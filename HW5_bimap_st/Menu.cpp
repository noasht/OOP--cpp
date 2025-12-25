/* Assignment: 5
Author: Noa Shem Tov
 */

# include "Menu.h"
# include <string>
# include "exceptionRep.h"
# include "BiMap.h"
# include "exceptionCity.h"
# include "Exception.h"
# include <algorithm>

Menu::Menu (BiMap<City<long>, string>& Bimap)
{
    fstream file;//the file that need to read from
    file.open("input.txt", ios::in);
    if (file) //only if the input file open
    {
        int Choice;//the choice number from 1 to 12
        char flag = A;//flag for the prevent the endless loop
        while (flag == A)
        {
            file >> Choice;//read from the txt file
            switch (Choice)
            {
                case ONE:
                    if (!AddCity(Bimap, file)) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
                    break;
                case TWO:
                    if (!addName(Bimap, file)) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
                    break;
                case THREE:
                    if (!eraseByCity(Bimap, file)) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
                    break;
                case FOUR:
                    if (!eraseByName(Bimap, file)) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
                    break;
                case FIVE:
                    if (!getCity(Bimap, file)) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
                    break;
                case SIX:
                    if (!getName(Bimap, file)) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
                    break;
                case SEVEN:
                    if (!isCity(Bimap, file)) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
                    break;
                case EIGHT:
                    if (!isName(Bimap, file)) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
                    break;
                case NINE:
                    if (!sortByCity(Bimap)) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
                    break;
                case TEN:
                    if (!sortByName(Bimap)) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
                    break;
                case ELEVEN:
                    Clean(Bimap);
                    break;
                case TWELVE:
                    file.close();
                    flag = A_SMALL;
                    break;
                default:
                    if (!InvalidOutPut()) //if the file doesn't open then the program will end
                    {
                        file.close();
                        flag = A_SMALL;
                    }//if
            }//switch
        }//while
    }//if
}//constructor
//Add a city by delegate name key
bool Menu::AddCity (BiMap<City<long>, string>& Bimap,fstream &file)
{
    string NameCity;
    long ID;
    long size;
    file >> ID;
    file >> NameCity;//im not using the operator >> because if the name of the city will be invalid there is function in City<> that change the name to '\0'
    // I want to keep the wrong name for the exceptions
    file >> size;
    string NameRep;
    file >> NameRep;//the representative's name
    char CityInValid [] = "The name of the city was invalid";
    char NameInValid [] = "The name of the Representative was invalid";
    char Exist [] = "The city already exist in the map";
    char IDExist [] = "The ID already exist in the map";
    int sizeStr = (int)NameCity.length() + ONE;
    char * name = new char [sizeStr];
    for(int i = ZERO; i < sizeStr; i++)
        name[i] = NameCity[i];
    try
    {
        if(ID < ZERO)//city's ID cant be negative
        {
            delete [] name;
            fstream fileOut;
            fileOut.open("output.txt", ios::app);
            if (!fileOut)
                return false;
            fileOut << "error"<<endl;
            fileOut.close();
            return true;
        }//if
        if(size < ONE)//the Size cant be negative
        {
            delete [] name;
            fstream fileOut;
            fileOut.open("output.txt", ios::app);
            if (!fileOut)
                return false;
            fileOut << "error"<<endl;
            fileOut.close();
            return true;
        }//if
        if(!check(NameCity))//if the name is not valid
            throw exceptionCity(name,CityInValid);
        if(!check(NameRep))//check the representative name
            throw exceptionCity (name, NameInValid);
        if(FoundIDCity(Bimap,ID))//if the ID already exist the ID must be unique
            throw exceptionCity(name,IDExist);
        City<long> Temp(ID,name,size);
        if(!Bimap.insert(NameRep,Temp))//the Value or the full object already existent
            throw exceptionCity(Temp.GetNameCity(), Exist);
        delete [] name;
        return true;//the insert was succeeded
    }//try
    catch (exceptionCity & errorCity)
    {
        delete [] name;
        if(!errorCity.handel())//the file doesn't open
            return false;
        return true;
    }//catch
}//AddCity
bool Menu::FoundIDCity (BiMap<City<long>, string>& Bimap, long ID)const
{
    BiMap<City<long>, string>::iteratorF iteratorValue = Bimap.beginF();//the beginning of the map
    while (iteratorValue != Bimap.endF())//until the end
    {
        if (iteratorValue.GetPointerF()->first.GetId() == ID)//check if the ID is not unique
            return true;
        iteratorValue++;//movement to the next object in the map
    }//while
    return false;//the ID doesn't existent
}//FoundIDCity
//Add a delegate name by city key
bool Menu::addName (BiMap<City<long>, string>& Bimap,fstream &file)
{
    char CityInValid [] = "The name of the city was invalid";
    char NameInValid [] = "The name of the Representative was invalid";
    char Exist [] = "The city already exist in the map";
    char IDExist [] = "The Id  already exist in the map";
    char NoName [] = "No Name";//if the name was invalid
    string NameRep;
    file >> NameRep;//the name of the representative
    const char * name = NameRep.c_str();
    City <long> Temp;
    file >> Temp;//the city
    try
    {
        if(Temp.GetId() < ZERO)//the ID can't be negative
        {
            fstream fileOut;
            fileOut.open("output.txt", ios::app);
            if (!fileOut)
                return false;
            fileOut << "error"<<endl;
            fileOut.close();
            return true;
        }//if
        if(Temp.GetSizeCity() == NEG_ONE)//the size can't be negative
        {
            fstream fileOut;
            fileOut.open("output.txt", ios::app);
            if (!fileOut)
                return false;
            fileOut << "error"<<endl;
            fileOut.close();
            return true;
        }//if
        if(!check(NameRep))//if the name is not valid
            throw exceptionRep(name, NameInValid);
        if(Temp.GetNameCity()[ZERO] == END_SIGN)//the name is not valid
            throw exceptionRep(NoName, CityInValid);
        if(FoundIDCity(Bimap,Temp.GetId()))//the id isn't unique
            throw exceptionRep(name,IDExist);
        if(!Bimap.insert(Temp, NameRep))//the insert failed
            throw exceptionRep(name, Exist);
        return true;
    }//try
    catch (exceptionRep & errorRep)
    {
        if(!errorRep.handel())
            return false;
        return true;
    }//catch
}//addName
//Delete a pair element by city key
bool Menu::eraseByCity (BiMap<City<long>, string>& Bimap,fstream &file)
{
    long IDForErase;
    file >> IDForErase;
    if(IDForErase < ZERO)
    {
        fstream fileOut;
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << "error"<<endl;
        fileOut.close();
        return true;
    }//if
    char NotExist [] = "The city isn't exist in the map";
    char NoCity[] = "No City";
    try
    {
        if (!FoundIDCity(Bimap, IDForErase))//city that doesn't existent can't be deleted
            throw exceptionCity(NoCity,NotExist);
        BiMap<City<long>, string>::iteratorF iteratorValue = Bimap.beginF();
        while (iteratorValue != Bimap.endF())//while for finding the city
        {
            if (iteratorValue.GetPointerF()->first.GetId() == IDForErase)
            {
                City<long> CityForErase = iteratorValue.GetPointerF()->first;
                Bimap.erase(CityForErase);//delete the city
                return true;
            }//if
        }//while
    }//try
    catch (exceptionCity & errorCity)
    {
        if(!errorCity.handel())
            return false;
        return true;
    }//catch
    return false;//because of the found function the loop wil end with true, is just for in case that never be use
}//eraseByCity
//Delete a pair element by delegate name key
bool Menu::eraseByName (BiMap<City<long>, string>& Bimap,fstream &file)
{
    string Name;
    file >> Name;
    if(!check(Name))//the name wasn't valid
    {
        fstream fileOut;
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << "error"<<endl;
        fileOut.close();
        return true;
    }//if
    char NotExist [] = "This representative isn't exist in the map";
    try
    {
        BiMap<City<long>, string>::iteratorS iteratorKey = Bimap.beginS();
        while (iteratorKey != Bimap.endS())//loop for search the object
        {
            if (iteratorKey.GetPointerS()->first == Name)
            {
                string NameForErase = iteratorKey.GetPointerS()->first;
                Bimap.erase(NameForErase);//delete the object from the BiMap
                return true;
            }//if
            iteratorKey++;//movement to the next object
        }//while
        const char * nameRep = Name.c_str();//the name does not exist in the BiMap
        throw exceptionRep(nameRep,NotExist);
    }//try
    catch (exceptionRep & errorRep)
    {
        if(!errorRep.handel())
            return false;
        return true;
    }//catch
}//eraseByName
//Absorb a delegate's name and return the city they represent
bool Menu::getCity (BiMap<City<long>, string>& Bimap,fstream &file)
{
    string Name;
    file >> Name;
    if(!check(Name))//the name doesn't valid
    {
        fstream fileOut;
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << "error"<<endl;
        fileOut.close();
        return true;
    }//if
    char NotExist [] = "This representative isn't exist in the map";
    try
    {
        City<long> city;
        BiMap<City<long>, string>::iteratorS iteratorKey = Bimap.beginS();
        while (iteratorKey != Bimap.endS())//loop to find the object
        {
            if (iteratorKey.GetPointerS()->first == Name)
            {
                city = iteratorKey.GetPointerS()->second;
                fstream fileOut;
                fileOut.open("output.txt", ios::app);
                if (!fileOut)
                    return false;
                fileOut << city<<endl;
                fileOut.close();
                return true;
            }//if
            iteratorKey++;//movement to the next object in the BiMap
        }//while
        const char * nameRep = Name.c_str();//the name doesn't appear in the map
        throw exceptionRep(nameRep,NotExist);
    }//try
    catch (exceptionRep & errorRep)
    {
        if(!errorRep.handel())
            return false;
        return true;
    }//catch
}//getCity
//Absorb a city's unique character and return the representative name of that city
bool Menu::getName (BiMap<City<long>, string>& Bimap,fstream &file)
{
    long ID;
    file >> ID;
    char NoCity [] = "NO CITY";
    char NotExist [] = "The city isn't exist in the map";
    if(ID < ZERO)//ID can't be negative
    {
        fstream fileOut;
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << "error"<<endl;
        fileOut.close();
        return true;
    }//if
    try
    {
        BiMap<City<long>, string>::iteratorF iteratorValue = Bimap.beginF();
        while (iteratorValue != Bimap.endF())//loop to find the city
        {
            if (iteratorValue.GetPointerF()->first.GetId() == ID)
            {//the name must be with uppercase in the beginning and also after - = HYPHEN and the rest lettres must be lowercase
                string City = iteratorValue.GetPointerF()->second;
                int i = ZERO;
                while (City[i] != END_SIGN)
                {
                    if (i == ZERO || City[i - 1] == HYPHEN)//upper case
                    {
                        if (City[i] >= A_SMALL && City[i] <= Z_SMALL)
                            City[i] -= (A_SMALL - A);
                    } //if
                    else
                    {
                        if (City[i] >= A && City[i] <= Z)//lower case
                            City[i] += +(A_SMALL - A);
                    }//if
                    i++;
                }//while
                fstream fileOut;
                fileOut.open("output.txt", ios::app);
                if (!fileOut)
                    return false;
                fileOut << City << endl;
                return true;
            }//if
        }//while
        throw exceptionCity (NoCity,NotExist);//this ID doesn't belong to any cities in the map
    }//try
    catch (exceptionCity & errorCity)
    {
        if(!errorCity.handel())
            return false;
        return true;
    }//catch
}//getName
//Absorb a unique character of a city and check whether it exists in the data structure
bool Menu::isCity (BiMap<City<long>, string>& Bimap,fstream &file)
{
    long ID;
    file >> ID;
    if(ID < ZERO)//the DI can't be negative
    {
        fstream fileOut;
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << "error"<<endl;
        fileOut.close();
        return true;
    }//if
    char spam [ ] = "Spam";
    City<long> Temp(ID,spam,ZERO);//for using the == operator
    BiMap<City<long>, string>::iteratorF iteratorValue = Bimap.beginF();
    bool found = Find(iteratorValue.GetPointerF(),Temp, Bimap.size());//return true if the object was found
    if (found)
    {
        fstream fileOut;
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << "yes"<<endl;
        fileOut.close();
        return true;
    }//if
    fstream fileOut;
    fileOut.open("output.txt", ios::app);
    if (!fileOut)
        return false;
    fileOut << "no"<<endl;
    fileOut.close();
    return true;
}//isCity
//Absorb a name and check whether it exists in the data structure
bool Menu::isName (BiMap<City<long>, string>& Bimap,fstream &file)
{
    string name;
    file >> name;
    if(!check(name))//the name is not valid
    {
        fstream fileOut;
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << "error"<<endl;
        fileOut.close();
        return true;
    }//if
    BiMap<City<long>, string>::iteratorS iteratorKey = Bimap.beginS();
    bool found = Find(iteratorKey.GetPointerS(),name, Bimap.size());//return true if the object was found
    if (found)
    {
        fstream fileOut;
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << "yes"<<endl;
        fileOut.close();
        return true;
    }//if
    fstream fileOut;
    fileOut.open("output.txt", ios::app);
    if (!fileOut)
        return false;
    fileOut << "no"<<endl;
    fileOut.close();
    return true;
}//isName
//Sorting and printing cities
bool Menu::sortByCity (BiMap<City<long>, string>& Bimap)
{
    fstream fileOut;
    BiMap<City<long>, string>::iteratorF iteratorValue = Bimap.beginF();
    if(iteratorValue == Bimap.endF())//the map is empty there is nothing to print
    {
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << "empty"<<endl;
        fileOut.close();
        return true;
    }//if
    while (iteratorValue != Bimap.endF())//until the end of the map
    {
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << iteratorValue.GetPointerF()->first<<endl;
        fileOut.close();
        iteratorValue++;//step to the next cell
    }//while
    return true;
}//sortByCity
//Sorting and printing delegate names
bool Menu::sortByName (BiMap<City<long>, string>& Bimap)
{
    fstream fileOut;
    BiMap<City<long>, string>::iteratorS iteratorKey = Bimap.beginS();
    if(iteratorKey == Bimap.endS())//if the map is empty there in nothing to print
    {
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << "empty"<<endl;
        fileOut.close();
        return true;
    }//if
    while (iteratorKey != Bimap.endS())//until the end of the map
    {
        fileOut.open("output.txt", ios::app);
        if (!fileOut)
            return false;
        fileOut << iteratorKey.GetPointerS()->first<<endl;
        fileOut.close();
        iteratorKey++;//step to the next object in the map
    }//while
    return true;
}//sortByName
void Menu::Clean (BiMap<City<long>, string>& Bimap)
{
    Bimap.Delete();//delete function = clear map
}//Clean
//in case that the user type to the file number not between 1 and 12
bool Menu::InvalidOutPut()
{
    fstream fileOut;
    fileOut.open("output.txt", ios::app);
    if (!fileOut)
        return false;
    fileOut <<"Not available"<<endl;
    fileOut.close();
    return true;
}//InvalidOutPut
bool Menu::check(string str)//check if the string is only letters and -
{
    int i = ZERO;
    while (str[i] != END_SIGN)
    {
        if (str[i] < A || str[i] > Z)
            if (str[i] < A_SMALL || str[i] > Z_SMALL)
                if (str[i] != HYPHEN)
                    return false;
        i++;
    }//while
    return true;
}//check