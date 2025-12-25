/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#ifndef HW4Q3_EMPLOYEE_H
#define HW4Q3_EMPLOYEE_H

#include "Person.h"

class Employee : virtual public Person {

protected:
    float salary;

public:
    Employee(float salary, char * Name, long ID);
    Employee(const Employee & EmployeeToCopy);
    void print(ostream &output)const;
    bool UpdateSalary(float salary);
    float GetSalary()const{return salary;}
};
#endif //HW4Q3_EMPLOYEE_H
