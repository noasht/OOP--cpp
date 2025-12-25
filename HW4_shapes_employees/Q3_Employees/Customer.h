/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#ifndef HW4Q3_CUSTOMER_H
#define HW4Q3_CUSTOMER_H
#include "Person.h"

class Customer : virtual public Person {

protected:
    float * PayList;
    int sizeOfPayList;

public:
    Customer(float * PayList, int sizeOfPayList, char * Name, long ID);
    Customer(const Customer & EmployeeToCopy);
    ~Customer();
    void print(ostream &output)const;
    virtual void Buy(float pay);
};
#endif //HW4Q3_CUSTOMER_H
