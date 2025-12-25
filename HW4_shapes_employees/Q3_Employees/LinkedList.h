/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#ifndef HW4Q3_LINKEDLIST_H
#define HW4Q3_LINKEDLIST_H

#include "Node.h"

class LinkedList {

private:
    Node * Head;

    void DeleteList();//recursive function,deleted the list
    LinkedList& putInPlace( Node* add);//put the object in the right place

public:
    LinkedList();//constructor
    ~LinkedList();//destructor
    Node * GetHead()const{return Head;}
    bool NotExistInList(long ID)const;//check id the value exist in the list
    LinkedList& operator += ( Customer& add);//add object to the list
    LinkedList& operator += (CustomerEmployee& add);//add object to the list
    LinkedList& operator += (Employee & add);//add object to the list
    friend ostream &operator << (ostream &output, const LinkedList &List);//operator <<
};
#endif //HW4Q3_LINKEDLIST_H
