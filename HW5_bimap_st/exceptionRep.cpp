/* Assignment: 5
Author: Noa Shem Tov
 */

#include "exceptionRep.h"

exceptionRep::exceptionRep(const char * RepresentativeName, char * error): Exception(error)
{
    int size = stringLength(RepresentativeName);//the size of the string
    this->RepresentativeName = new char [size];
    for (int i = ZERO; i < size; ++i)
        this->RepresentativeName[i] = RepresentativeName[i];//copy each cell
}//constructor
exceptionRep::~exceptionRep()
{
    delete [] RepresentativeName;
    RepresentativeName = nullptr;
}//destructor
bool exceptionRep::handel()const
{
    Exception::handel();
    fstream fileOut;
    fileOut.open("output.txt", ios::app);
    if (!fileOut)
        return false;
    fileOut << "This exception in regarding <" << RepresentativeName <<  ">" <<endl;
    fileOut.close();
    return true;
}//Handle