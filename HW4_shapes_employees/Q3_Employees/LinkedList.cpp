/* Assignment: 4 Question 3
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
bool LinkedList:: NotExistInList (long ID) const
{
    Node* pointer = this->Head;
    while (pointer != nullptr)
    {
        if(pointer->GetMyPointerInNode() != nullptr)
        {
            if (pointer->GetMyPointerInNode()->GetID() == ID)
                return false;
        }//if
        pointer = pointer->GetNext();
    }//while
    return true;
}//DoesExistInList
LinkedList& LinkedList::operator += (Employee & add)//add object to the list
{
    Node *New = new Node(add);
    putInPlace(New);
    return *this;
}//
LinkedList& LinkedList::operator +=(Customer & add)//add object to the list
{

    Node *New = new Node(add);
    putInPlace(New);
    return *this;
}//
LinkedList& LinkedList::operator +=(CustomerEmployee & add)//add object to the list
{
    Node *New = new Node(add);
    putInPlace(New);
    return *this;
}//
ostream &operator << (ostream &output, const LinkedList &List)
{
    int Amount = Person::GetAmountOfPersons();
    Node * pointer = List.Head;
    for (int i = ZERO; i < Amount; ++i)
    {
        pointer->GetMyPointerInNode()->print(output);
        pointer = pointer->GetNext();
    }//for
    return output;
}//print operator
LinkedList& LinkedList::putInPlace(Node* add)//put the object in the right place
{
    Node * pointer = this->Head;
    if(pointer != nullptr)
    {
        while (pointer->GetNext() != nullptr)
            pointer = pointer->GetNext();
        pointer->SetNext(add);
    }//if
    else this->Head = add;
    return *this;
}//putInPlace