/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#ifndef HW4Q3_NODE_H
#define HW4Q3_NODE_H

#include "Person.h"
#include "CustomerEmployee.h"
#include "Customer.h"
#include "Employee.h"

class Node {
private:
    Person * pointerToPerson;//pointer to object Person
    Node *Next;//the pointer for the next Node

public:
    Node();//default constructor
    Node(Employee &Add);//conversion constructor Person -> Node
    Node(Customer &Add);//conversion constructor Customer -> Node
    Node(CustomerEmployee &Add);//conversion constructor CustomerEmployee -> Node
    Person *GetMyPointerInNode() const { return pointerToPerson; }//get the Pointer
    Node *GetNext() { return Next; }//get Next
    void SetNext(Node* TheNextNode)
    {
        Next = TheNextNode;//change the next to pointer on another Node, the prev Next id still exits but another pointer point on it
    }//SetNext
};
#endif //HW4Q3_NODE_H
