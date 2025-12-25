/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#ifndef HW4Q3_PERSON_H
#define HW4Q3_PERSON_H

#include <iostream>
#include <cstring>
#define ONE 1
#define ZERO 0
#define NAME "Israel Israeli"
#define ID_NUMBER 123456789
#define DEFAULT_SIZE 14
#define A_UPPERCASE 'A'
#define Z_UPPERCASE 'Z'
#define A_LOWERCASE 'a'
#define Z_LOWERCASE 'z'
#define SPACE ' '
#define HYPHEN '-'
#define TEN 10
#define NINE 9
#define SEVEN 7
#define DISCOUNT 0.9
#define HALF 0.5
#define TWO 2
#define MAXIMUM_LENGTH 20
using namespace std;

class Person {

protected:
    char * Name;
    long ID;
    static int AmountOfPersons;//count the person in the list

private:
    bool ValidName( char * Name)const;//checking the name
    bool ValidID(long ID)const;//checking the ID

public:
    Person(char * Name, long ID);//constructor
    Person(const Person & PersonToCopy);//copy constructor
    virtual ~Person();//destructor
    static int GetAmountOfPersons(){return AmountOfPersons;}//the amount in the list of people
    int GetID() const{return ID;}//return the ID of the person
    virtual void print(ostream &output)const = 0;//print the object
};
#endif //HW4Q3_PERSON_H
