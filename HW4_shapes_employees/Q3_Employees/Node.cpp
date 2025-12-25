/* Assignment: 4 Question 3
Author: Noa Shem Tov
 */

#include "Node.h"

Node::Node()
{
    pointerToPerson = nullptr;
    Next = nullptr;
}//default constructor
Node::Node(Employee &Add)//conversion constructor Employee -> Node
{
    pointerToPerson = &Add;
    Next = nullptr;
}//conversion constructor
Node::Node(CustomerEmployee &Add)//conversion constructor CustomerEmployee -> Node
{
    pointerToPerson = &Add;
    Next = nullptr;
}//conversion constructor
Node::Node(Customer &Add)//conversion constructor Customer -> Node
{
    pointerToPerson = &Add;
    Next = nullptr;
}//conversion constructor
