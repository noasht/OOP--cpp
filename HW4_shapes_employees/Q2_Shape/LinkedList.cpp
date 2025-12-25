/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#include "LinkedList.h"

LinkedList::LinkedList()//default constructor
{
    Head = nullptr;//empty list
}//LinkedList
LinkedList::~LinkedList()
{
    if(Head != nullptr)
        DeleteList();//only of the list not empty there is something to delete
}//~LinkedList
void LinkedList::DeleteList()
{
    Node * TheNextObject;//the pointer for the next object to be deleted
    do//do-while
    {
        TheNextObject = ((this->Head)->GetNext());//next Node
        delete Head->GetMyPointerInNode();//delete the this
        Head = TheNextObject;//the next node need to be deleted
    }while (Head != nullptr);//until the end of the list
}//DeleteList
LinkedList& LinkedList::operator +=(Circle & add)//add object to the list
{
    putInPlace(add);
    return *this;
}//Circle add
LinkedList& LinkedList::operator +=(Cylinder & add)//add object to the list
{
    putInPlace(add);
    return *this;
}//Cylinder add
LinkedList& LinkedList::operator +=(Cuboid & add)//add object to the list
{
    putInPlace(add);
    return *this;
}//Cuboid add
LinkedList& LinkedList::operator +=(Rectangle & add)//add object to the list
{
    putInPlace(add);
    return *this;
}//Rectangle add
LinkedList& LinkedList::operator +=(Ring & add)//add object to the list
{
    putInPlace(add);
    return *this;
}//Ring add
void LinkedList::putInPlace(Cuboid & add)//put the object in the right place
{
    Node * Walk = Head;
    if(Walk != nullptr)//if the list not empty
    {
        while (Walk->GetNext() != nullptr)
            Walk = Walk->GetNext();
        Node *New = new Node (add);
        Walk->SetNext(*New);
        return;
    }//if
    Node *New = new Node (add);//the first node = the head
    Head = New;
}
void LinkedList::putInPlace(Cylinder & add)//put the object in the right place
{
    Node * Walk = Head;
    if(Walk != nullptr)//if the list not empty
    {
        while (Walk->GetNext() != nullptr)
            Walk = Walk->GetNext();
        Node *New = new Node (add);
        Walk->SetNext(*New);
        return;
    }//if
    Node *New = new Node (add);//the first node = the head
    Head = New;
}
void LinkedList::putInPlace(Circle & add)//put the object in the right place
{
    Node * Walk = Head;
    if(Walk != nullptr)//if the list not empty
    {
        while (Walk->GetNext() != nullptr)
            Walk = Walk->GetNext();
        Node *New = new Node (add);
        Walk->SetNext(*New);
        return;
    }//if
    Node *New = new Node (add);//the first node = the head
    Head = New;
}
void LinkedList::putInPlace(Ring & add)//put the object in the right place
{
    Node * Walk = Head;
    if(Walk != nullptr)//if the list not empty
    {
        while (Walk->GetNext() != nullptr)
            Walk = Walk->GetNext();
        Node *New = new Node (add);
        Walk->SetNext(*New);
        return;
    }//if
    Node *New = new Node (add);//the first node = the head
    Head = New;
}
void LinkedList::putInPlace(Rectangle & add)//put the object in the right place
{
    Node * Walk = Head;
    if(Walk != nullptr)//if the list not empty
    {
        while (Walk->GetNext() != nullptr)
            Walk = Walk->GetNext();
        Node *New = new Node (add);
        Walk->SetNext(*New);
        return;
    }//if
    Node *New = new Node (add);//the first node = the head
    Head = New;
}
ostream &operator << (ostream &output, const LinkedList &List)//operator<<
{
    if(List.Head != nullptr)//the list is not empty
    {
        LinkedList Walk;//the pinter that walk on the list
        Walk.Head = List.Head;//turn to node
        while (Walk.Head != nullptr)
        {
            Walk.Head->GetMyPointerInNode()->print(output);
            Walk.Head= Walk.Head->GetNext();//move to the next node
        }//while
    }//if
    return output;
}//operator <<
