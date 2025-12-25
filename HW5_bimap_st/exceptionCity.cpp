/* Assignment: 5
Author: Noa Shem Tov
 */
#include "exceptionCity.h"
exceptionCity::exceptionCity(char *CityName, char *error) : Exception(error)
{
    int size = stringLength(CityName);//the size of the string
    this->CityName = new char[size];
    for (int i = ZERO; i < size; ++i)
        this->CityName[i] = CityName[i];//copy each cell
}//constructor
exceptionCity::~exceptionCity()
{
    delete [] CityName;
    CityName = nullptr;
}//destructor
bool exceptionCity::handel() const
{
    fstream fileOut;
    fileOut.open("output.txt", ios::app);
    if (!fileOut)
        return false;
    fileOut << "Exception in City < " << this->CityName << " >" << endl;
    fileOut.close();
    Exception::handel();
    return true;
}//handel