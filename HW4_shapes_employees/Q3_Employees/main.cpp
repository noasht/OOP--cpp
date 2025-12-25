/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#include "LinkedList.h"
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6

void Menu();
void AddPerson(LinkedList & list);
void AddPay(LinkedList & list);
void UpdateSalaryEmployee(LinkedList & list);
void AverageOfSalary(LinkedList & list);
void Print(LinkedList & list);
void AddCustomer(LinkedList & list);
void AddEmployee(LinkedList & list);
void AddBoth(LinkedList & list);
Person * FindThePerson(const LinkedList &list,long ID);
void Find_Types(const LinkedList & list, int amountPersons, int &AmountEmployee,int &AmountCustomer );

int main()
{
    Menu();
    return 0;
}//MAIN
void Menu()
{
    LinkedList list;
    cout<<endl<<"Welcome!"<<endl;
    while (ONE) {
        cout << "Please choose one of the following options: " << endl;
        cout << "     1 ) Add a person" << endl;
        cout << "     2 ) Add a purchase to a customer" << endl;
        cout << "     3 ) Update employee salary" << endl;
        cout << "     4 ) Average of salaries" << endl;
        cout << "     5 ) Print the person list" << endl;
        cout << "     6 ) Exit" << endl;
        int choice;
        cin >> choice;
        getchar();
        switch (choice)
        {
            case ONE:
                AddPerson(list);
                break;
            case TWO:
                AddPay(list);
                break;
            case THREE:
                UpdateSalaryEmployee(list);
                break;
            case FOUR:
                AverageOfSalary(list);
                break;
            case FIVE:
                Print(list);
                break;
            case SIX:
                cout << "Thanks and goodbye" << endl;
                return;
            default:
                cout << "please chose one of the option below " << endl;
        }//switch
    }//while
}
void AddPerson(LinkedList & list)
{
    while (ONE)
    {
        cout << "Please choose one of the following options: " << endl;
        cout << "     1 ) Add a customer" << endl;
        cout << "     2 ) Add a employee" << endl;
        cout << "     3 ) Add Both of them" << endl;
        int choice;
        cin >> choice;
        getchar();
        switch (choice)
        {
            case ONE:
                AddCustomer(list);
                return;
            case TWO:
                AddEmployee(list);
                return;
            case THREE:
                AddBoth(list);
                return;
            default:
                cout << "please chose one of the option below " << endl;
        }//switch
    }//while
}//add person
void AddCustomer(LinkedList & list)
{
    long IDPerson;
    cout<<"Please fill in the following details"<<endl;
    cout<<"Please enter customer's ID "<<endl;
    cin>>IDPerson;
    if(!list.NotExistInList(IDPerson))//checking if the ID already exist
    {
        cout<<"Already in the repository\nYou are returned to the main menu"<<endl;
        return;
    }//if
    cout<<"What's customer name"<<endl;
    getchar();
    char NameOfPerson [MAXIMUM_LENGTH];
    cin.getline(NameOfPerson,MAXIMUM_LENGTH);
    cout<<"How many purchases have the customer done so far?"<<endl;
    int sizeOfPaysPerson;
    cin>>sizeOfPaysPerson;
    if(sizeOfPaysPerson < ZERO)
    {
        cout<<"Improper number of purchases\nYou are returned to the main menu"<<endl;
        return;
    }//if
    float * TempPayList = nullptr;
    if(sizeOfPaysPerson == ZERO)
    {
        Customer * CustomerNew = new Customer (TempPayList,sizeOfPaysPerson,NameOfPerson,IDPerson);
        list += (*CustomerNew);
        cout<<"Customer added successfully"<<endl;
        return;
    }//if
    TempPayList = new float [sizeOfPaysPerson];
    int i = ZERO;
    cout<<"Please enter the purchase amounts one by one"<<endl;
    while (i < sizeOfPaysPerson)
    {
        cout<<"The purchase "<< i+ONE<< " value is:"<<endl;
        float valuePay;
        cin>>valuePay;
        if(valuePay <= ZERO)
            cout<<"A purchase amount should bigger than zero\nPlease type again"<<endl;
        else
        {
            TempPayList[i] = valuePay;
            i++;
        }//else
    }//while
    Customer * CustomerNew = new Customer (TempPayList,sizeOfPaysPerson,NameOfPerson,IDPerson);
    delete [] TempPayList;
    list += (*CustomerNew);
    cout<<"Customer added successfully"<<endl;
}//AddCustomer
void AddEmployee(LinkedList & list)
{
    long IDPerson;
    cout<<"Please fill in the following details"<<endl;
    cout<<"Please enter Employee's ID "<<endl;
    cin>>IDPerson;
    if(!list.NotExistInList(IDPerson))//checking if the ID already exist
    {
        cout<<"Already in the repository\nYou are returned to the main menu"<<endl;
        return;
    }//if
    cout<<"What's Employee name"<<endl;
    getchar();
    char NameOfPerson [MAXIMUM_LENGTH];
    cin.getline(NameOfPerson,MAXIMUM_LENGTH);
    float salary;
    cout<<"Please type Employee's salary"<<endl;
    cin>>salary;
    if(salary < ONE)
    {
        cout<<"Salary must be positive\nYou are returned to the main menu"<<endl;
        return;
    }//if
    Employee * EmployeeNew = new Employee (salary,NameOfPerson,IDPerson);
    list += (*EmployeeNew);
    cout<<"Employee added successfully"<<endl;
}//AddEmployee
void AddBoth(LinkedList & list)
{
    long IDPerson;
    cout<<"Please fill in the following details"<<endl;
    cout<<"Please enter ID "<<endl;
    cin>>IDPerson;
    if(!list.NotExistInList(IDPerson))//checking if the ID already exist
    {
        cout<<"Already in the repository\nYou are returned to the main menu"<<endl;
        return;
    }//if
    cout<<"What's the name"<<endl;
    char NameOfPerson [MAXIMUM_LENGTH];
    getchar();
    cin.getline(NameOfPerson,MAXIMUM_LENGTH);
    float salary;
    cout<<"Please type Employee's salary"<<endl;
    cin>>salary;
    if(salary < ONE)
    {
        cout<<"Salary must be positive\nYou are returned to the main menu"<<endl;
        return;
    }//if
    cout<<"How many purchases have done so far?"<<endl;
    int sizeOfPaysPerson;
    cin>>sizeOfPaysPerson;
    if(sizeOfPaysPerson < ZERO)
    {
        cout<<"Improper number of purchases\nYou are returned to the main menu"<<endl;
        return;
    }//if
    float * TempPayList = nullptr;
    if(sizeOfPaysPerson == ZERO)
    {
        CustomerEmployee * EmployeeCustomerNew = new CustomerEmployee (salary,TempPayList,sizeOfPaysPerson,NameOfPerson,IDPerson);
        list += (*EmployeeCustomerNew);
        cout<<"Added both as a person and as a customer successfully"<<endl;
        return;
    }//if
    TempPayList = new float [sizeOfPaysPerson];
    int i = ZERO;
    cout<<"Please enter the purchase amounts one by one"<<endl;
    while (i < sizeOfPaysPerson)
    {
        cout<<"The purchase "<< i+ONE<< " value is:"<<endl;
        float valuePay;
        cin>>valuePay;
        if(valuePay <= ZERO)
            cout<<"A purchase amount should bigger than zero\nPlease type again"<<endl;
        else
        {
            TempPayList[i] = valuePay;
            i++;
        }//else
    }//while
    CustomerEmployee * EmployeeCustomerNew = new CustomerEmployee (salary,TempPayList,sizeOfPaysPerson,NameOfPerson,IDPerson);
    delete [] TempPayList;
    list += (*EmployeeCustomerNew);
    cout<<"Added both as a person and as a customer successfully"<<endl;
}//AddBoth
void AddPay(LinkedList & list)
{
    if(Person::GetAmountOfPersons() == ZERO)
    {
        cout << "There are no people in the list" << endl;
        return;
    }//if
    cout<<"To add a purchase Please enter the purchase value"<<endl;
    cout<<"Please enter the purchase value"<<endl;
    float pay;
    cin>>pay;
    if(pay < ZERO)
    {
        cout<<"The purchase value must be a positive number, different from zero."<<endl;
        return;
    }//if
    cout<<"please enter the customer ID"<<endl;
    long ID;
    cin>>ID;
    if(list.NotExistInList(ID))
    {
        cout<<"There is no person with this ID number"<<endl;
        return;
    }//if
    Person * person = FindThePerson(list,ID);
    CustomerEmployee * customerAndEmployee = dynamic_cast<CustomerEmployee*>(person);
    if(customerAndEmployee != nullptr)
    {
        customerAndEmployee->Buy(pay);
        cout<<"Adding the purchase was done successfully"<<endl;
        return;
    }//
    Customer * customer = dynamic_cast<Customer*>(person);
    if(customer != nullptr)
    {
        customer->Buy(pay);
        cout<<"Adding the purchase was done successfully"<<endl;
        return;
    }//
    cout<<"ID is for an employee and not a customer"<<endl;
}//AddPay
Person * FindThePerson(const LinkedList &list,long ID)
{
    int AmountOfPersons = Person::GetAmountOfPersons();
    Node * pointer = list.GetHead();
    for (int i = ZERO; i < AmountOfPersons; ++i)
    {
        if(pointer->GetMyPointerInNode()->GetID() == ID)
            return pointer->GetMyPointerInNode();
        pointer = pointer->GetNext();
    }//for
    return nullptr;
}//FindThePerson
void UpdateSalaryEmployee(LinkedList & list)
{
    if(Person::GetAmountOfPersons() == ZERO)
    {
        cout << "There are no people in the list" << endl;
        return;
    }//if
    cout<<"Please enter Employee's ID"<<endl;
    long ID;
    cin>>ID;
    if(list.NotExistInList(ID))
    {
        cout<<"There is no person with this ID number"<<endl;
        return;
    }//if
    Person * person = FindThePerson(list,ID);
    CustomerEmployee * customerAndEmployee = dynamic_cast<CustomerEmployee*>(person);
    if(customerAndEmployee != nullptr)
    {
        float salary;
        cout<<"Please enter the new salary to complete the update"<<endl;
        cin>>salary;
        if(customerAndEmployee->UpdateSalary(salary))
        {
            cout << "The update was successfully completed" << endl;
            return;
        }
        cout<<"The salary is not valid. Unable to complete the update"<<endl;
        return;
    }//
    Employee * EmployeeTemp = dynamic_cast<Employee*>(person);
    if(EmployeeTemp != nullptr)
    {
        float salary;
        cout<<"Please enter the new salary to complete the update"<<endl;
        cin>>salary;
        if(EmployeeTemp->UpdateSalary(salary))
        {
            cout << "The update was successfully completed" << endl;
            return;
        }
        cout<<"The salary is not valid. Unable to complete the update"<<endl;
        return;
    }//
    cout<<"The ID number belongs to a customer"<<endl;
}//UpdateSalaryEmployee
void AverageOfSalary(LinkedList & list)
{
    int listSize = Person::GetAmountOfPersons();
    if(Person::GetAmountOfPersons() == ZERO)
    {
        cout << "There are no people in the list" << endl;
        return;
    }//if
    double SumOfSalary = ZERO;
    Node * pointer = list.GetHead();
    for (int i = ZERO; i < listSize; ++i)
    {
        Employee * pointerOfEmployee = dynamic_cast<Employee*>(pointer->GetMyPointerInNode());//checkin if the object is employee
        if(pointerOfEmployee != nullptr)
            SumOfSalary += pointerOfEmployee->GetSalary();
        pointer = pointer->GetNext();
    }//for
    if(SumOfSalary == ZERO)
    {
        cout << "There are no employees available to calculate the average"<<endl;
        return;
    }//if
    int personCust;
    int personEmployee;
    Find_Types(list,Person::GetAmountOfPersons(),personEmployee,personCust);
    cout<<"The average salary of "<<personEmployee<<" company employees is "<<SumOfSalary/personEmployee<<endl;
}//AverageOfSalary
void Print(LinkedList & list)
{
    if(list.GetHead() != nullptr)
    {
        cout<<"The persons are"<<endl<<endl;
        cout << list;
    }//if
    else cout<<"There are no people in the list"<<endl;
}//Print
void Find_Types(const LinkedList & list, int amountPersons, int &AmountEmployee,int &AmountCustomer )
{
    AmountEmployee = ZERO;
    AmountCustomer = ZERO;
    CustomerEmployee * pointerCE;
    Customer * pointerC;
    Node* pointerOnTheList = list.GetHead();
    for (int i = 0; i < amountPersons; ++i)
    {
        pointerCE = dynamic_cast<CustomerEmployee*>(pointerOnTheList->GetMyPointerInNode());//first checking if the object is in the both kinds
        if(pointerCE != nullptr)
        {
            AmountEmployee++;
            AmountCustomer++;
        } //if
        else
        {
            pointerC = dynamic_cast<Customer*>(pointerOnTheList->GetMyPointerInNode());
            if(pointerC != nullptr)
                AmountCustomer++;
            else AmountEmployee++;
        }//else
        pointerOnTheList = pointerOnTheList->GetNext();
    }//for
}//find_types
