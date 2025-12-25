/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#include "Employee.h"

Employee::Employee(float salary, char * Name, long ID) : Person(Name,ID)
{
    this->salary = salary;
}//constructor
Employee::Employee(const Employee & EmployeeToCopy) : Person(EmployeeToCopy)
{
    this->salary = EmployeeToCopy.salary;
}//copy constructor
void Employee::print(ostream &output)const
{
    output<< "Employee"<<endl;
    output<< "The Employee's name is :\n"<<this->Name<<endl;
    output<< "The Employee's ID :\n"<< this->ID<<endl;
    output<<"The Employee's salary :\n"<< this->salary<<endl<<endl;
}//print
bool Employee::UpdateSalary(float salary)
{
    if(salary < ZERO)
        return false;
    if(this->salary * HALF > salary)
        return false;
    if(this->salary * TWO < salary)
        return false;
    this->salary = salary;
    return true;
}//UpdateSalary