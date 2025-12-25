/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#ifndef HW4Q2_LINKEDLIST_H
#define HW4Q2_LINKEDLIST_H

#include "Shape.h"
#include "Circle.h"
#include "Cuboid.h"
#include "Cylinder.h"
#include "Ring.h"
#include "Rectangle.h"

class LinkedList {

private:
    class Node { //private inner class
    private:
        Shape * kindOfShape;//pointer to object
        Node * Next;//the pointer for the next Node

    public:
        Node(){ kindOfShape = nullptr; Next = nullptr;}//default constructor
        explicit Node(Circle & Add)//conversion constructor Circle -> Node
        {
            kindOfShape = &Add;//the object Circle
            Next = nullptr;//null because is not node is just Circle
        }//conversion constructor
        explicit Node(Cylinder & Add)//conversion constructor Cylinder -> Node
        {
            kindOfShape = &Add;//the object Cylinder
            Next = nullptr;//null because is not node is just Cylinder
        }//conversion constructor
        explicit Node(Cuboid & Add)//conversion constructor Cuboid -> Node
        {
            kindOfShape = &Add;//the object Cuboid
            Next = nullptr;//null because is not node is just Cuboid
        }//conversion constructor
        explicit Node(Ring & Add)//conversion constructor Ring -> Node
        {
            kindOfShape = &Add;//the object Ring
            Next = nullptr;//null because is not node is just Ring
        }//conversion constructor
        explicit Node (Rectangle & Add)//conversion constructor Rectangle -> Node
        {
            kindOfShape = &Add;//the object Rectangle
            Next = nullptr;//null because is not node is just Rectangle
        }//conversion constructor
        Shape* GetMyPointerInNode() const {return kindOfShape;}//get kindOfShape
        Node* GetNext() const {return Next;}//get Next
        void SetNext(Node & TheNextNode)
        {
            Next = &TheNextNode;//change the next to pointer on another Node
        }//SetNext
    };

    Node * Head;

    void DeleteList();//recursive function,deleted the list
    void putInPlace(Cuboid & add);//put the object in the right place
    void putInPlace(Cylinder & add);//put the object in the right place
    void putInPlace(Circle & add);//put the object in the right place
    void putInPlace(Ring & add);//put the object in the right place
    void putInPlace(Rectangle & add);//put the object in the right place

public:
    LinkedList();//constructor
    ~LinkedList();//destructor
    LinkedList& operator +=(Circle & add);//add object to the list
    LinkedList& operator +=(Cylinder & add);//add object to the list
    LinkedList& operator +=(Cuboid & add);//add object to the list
    LinkedList& operator +=(Rectangle & add);//add object to the list
    LinkedList& operator +=(Ring & add);//add object to the list
    friend ostream &operator << (ostream &output, const LinkedList &List);//operator <<
    friend void PrintByColor(LinkedList& list);
    friend void PrintBiggerThenMinVolume(LinkedList& list);
    friend void PrintByKindOfShape(LinkedList & list);
    friend void PrintSumArea(LinkedList & list);
};
#endif //HW4Q2_LINKEDLIST_H