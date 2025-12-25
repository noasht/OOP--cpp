/* Assignment: 2
Author: Noa Shem Tov   */

#ifndef HW2_LINKEDLIST_H
#define HW2_LINKEDLIST_H

#include "MyNumber.h"

class LinkedList {

private:
    class Node { //private inner class
    private:
        MyNumber * MyNumPointer;//pointer to object MuNumber
        Node * Next;//the pointer for the next Node

    public:
        Node(){ MyNumPointer = nullptr; Next = nullptr;}//default constructor
        Node(const Node & ObjectForCopy)//copy constructor
        {
            MyNumPointer = new MyNumber (*(ObjectForCopy.MyNumPointer));//copy the value for the object MyNumber
            if(ObjectForCopy.Next != nullptr)//if there is next to the node, and it's not the only node
                Next = new Node (*(ObjectForCopy.Next));//copy also the next
            else
                Next = nullptr;//else, put null
        }//copy constructor
       explicit Node(const MyNumber & Add)//conversion constructor MyNumber -> Node
       {
           MyNumPointer = new MyNumber(Add);//copy the value for the object MyNumber
           Next = nullptr;//null because is not node is just MyNumber
       }//conversion constructor
        MyNumber* GetMyNumPointerInNode() const {return MyNumPointer;}//get MyNumPointer
        Node* GetNext() const {return Next;}//get Next
        void SetNext(Node & TheNextNode)
        {
            Next = new Node (TheNextNode);//change the next to pointer on another Node, the prev Next id still exits but another pointer point on it
        }//SetNext
        Node& operator= (const Node& Another)//operatoe=
        {
            if(this != &Another)//only if its another object
            {
                delete Next;
                Next = Another.Next;
                *MyNumPointer = *Another.MyNumPointer;//operator = of MyNumber
            }//if
            return *this;
        }//operator=
        void SetMyNumPointer(MyNumber & AddressForNewMyNum)
        {
            *MyNumPointer = AddressForNewMyNum;//operator = of MyNumber
        }//SetMyNumPointer
    };

    Node * Head;

    void DeleteList();//recursive function,deleted the list
    void putInPlace(const MyNumber & addNumber);//put the object in the right place
    void DeleteNodeByValue(int number);//delete one node

public:
    LinkedList();//constructor
    LinkedList(const LinkedList &AnotherList);//copy Constructor
    ~LinkedList();//destructor
    LinkedList& operator = (const LinkedList &AnotherList);//operator =
    bool DoesExistInList(int value)const;//check id the value exist in the list
    const LinkedList operator + (const LinkedList &AnotherList)const;//create new list that is the sum of 2 different lists
    LinkedList& operator +=(const MyNumber & addNumber);//add object to the list
    LinkedList& operator -=(const MyNumber & addNumber);//remove object from the list
    friend ostream &operator << (ostream &output, const LinkedList &List);//operator <<
};
#endif //HW2_LINKEDLIST_H
