/* Assignment: 5
Author: Noa Shem Tov
 */

#ifndef BIMAP_H_EXCEPTIONCITY_H
#define BIMAP_H_EXCEPTIONCITY_H

#include "Exception.h"

class exceptionCity : public Exception {

private:
    char * CityName;
public:
    exceptionCity(char * CityName, char * error);//constructor
    virtual ~exceptionCity();//destructor
    bool handel()const;//virtual function
};
#endif //BIMAP_H_EXCEPTIONCITY_H
