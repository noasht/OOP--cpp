/* Assignment: 5
Author: Noa Shem Tov
 */

#ifndef BIMAP_H_EXCEPTIONREP_H
#define BIMAP_H_EXCEPTIONREP_H

#include "Exception.h"

class exceptionRep : public Exception {

private:
    char * RepresentativeName;
public:
    exceptionRep(const char * RepresentativeName, char * error);//constructor
    virtual ~exceptionRep();//destructor
    bool handel()const;//virtual function
};
#endif //BIMAP_H_EXCEPTIONREP_H