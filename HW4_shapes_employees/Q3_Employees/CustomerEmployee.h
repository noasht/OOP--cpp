/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#ifndef HW4Q3_CUSTOMEREMPLOYEE_H
#define HW4Q3_CUSTOMEREMPLOYEE_H
#include "Customer.h"
#include "Employee.h"

class CustomerEmployee : public Customer , public Employee {

public:
    CustomerEmployee(float salary,float * PayList, int sizeOfPayList, char * Name, long ID);
    CustomerEmployee(const CustomerEmployee & object);
    void print(ostream &output)const;
    virtual void Buy(float pay);
};
#endif //HW4Q3_CUSTOMEREMPLOYEE_H
