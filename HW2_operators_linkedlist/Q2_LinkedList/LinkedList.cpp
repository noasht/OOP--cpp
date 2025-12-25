/* Assignment: 2
Author: Noa Shem Tov  */

#include "LinkedList.h"
LinkedList::LinkedList()//default constructor
{
    Head = nullptr;//empty list
}//LinkedList
LinkedList::LinkedList(const LinkedList &AnotherList)//copy constructor
{
    if(AnotherList.Head != nullptr)//copy only when the list isn't empty
        Head = new Node(*(AnotherList.Head));//create new object
    else Head = nullptr;//if the AnotherList is empty
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
        delete Head;//delete the this
        Head = TheNextObject;//the next node need to be deleted
    }while (Head != nullptr);//until the end of the list
}//DeleteList
LinkedList& LinkedList::operator = (const LinkedList &AnotherList)
{
    if(Head != nullptr)
        DeleteList();//if the list is not empty
    Head = new Node (*(AnotherList.Head));//set the head it will be in tha same value
    Node * pointerOnAnother = AnotherList.Head->GetNext();//the pointer that walk on the AnotherList
    Node * pointerOnThis = nullptr;//the pointer that walk on the this
    Node * PrevNode = Head;//the prev for set the next to the new object that need to be added
    while (pointerOnAnother != nullptr)
    {
        pointerOnThis = new Node(*(pointerOnAnother));//create new node
        PrevNode->SetNext(*pointerOnThis);//set the next of the prev -> Connect the chain
        PrevNode = PrevNode->GetNext();//the prev move to the new node
        pointerOnAnother = pointerOnAnother->GetNext();//also the pointer on the AnotherList
    }//while
    return *this;
}//operator =
bool LinkedList:: DoesExistInList (int value) const
{
    Node * ObjectToCheck = Head;//get the head
    while(ObjectToCheck != nullptr)//if the list is not empty
    {
        int number = ObjectToCheck->GetMyNumPointerInNode()->DecimalValueOfTheObject();
        if( value == number)//check if the value exist in the list
           return true;//if yes, return true
        ObjectToCheck = ObjectToCheck->GetNext();//if not, need to be moved the next node in the list
    }//while
    return false;
}//DoesExistInList
const LinkedList LinkedList:: operator + (const LinkedList &AnotherList)const
{
    Node * pointerForThis = this->Head;//pointer that walk on the object this
    Node * pointerForAnother = AnotherList.Head;//pointer that walk on the object AnotherList
    Node * HeadOfNewList = nullptr;//will contain the head if the new list
    Node * pointerForNewNode = nullptr;//pointer that walk on the new list
    Node * PrevNode = nullptr;//prev in the new list to connect the list
    int number;//the value that will be in the MyNumber POINTER
    MyNumber SumMyNum;//temp object for MyNumber
    if(pointerForThis != nullptr && pointerForAnother != nullptr)//create the head of the list after that the rest
    {
        number = (int)*(pointerForThis->GetMyNumPointerInNode()) + (int)*(pointerForAnother->GetMyNumPointerInNode());//the current value
        SumMyNum.SetByNumber((long)number);//create object with the current value
        HeadOfNewList = new Node (SumMyNum);//conversion constructor
        PrevNode = HeadOfNewList;//the prev now that there is a new node is the head
        pointerForAnother = pointerForAnother->GetNext();//get the next node in the another object
        pointerForThis = pointerForThis->GetNext();//get the next node in this object
        while (pointerForThis != nullptr && pointerForAnother != nullptr)//doing sum until one of them will end or in the same time, not matter
        {
            number = (int) *(pointerForAnother->GetMyNumPointerInNode()) + (int) *(pointerForThis->GetMyNumPointerInNode());//the current value
            SumMyNum.SetByNumber((long) number);//create object with the current value
            pointerForNewNode = new Node(SumMyNum);//conversion constructor
            PrevNode->SetNext(*pointerForNewNode);//the prev set the next for move to the new node that added to list
            PrevNode = PrevNode->GetNext();//the prev advance
            pointerForAnother = (pointerForAnother->GetNext());//the pointers also move the next node
            pointerForThis = pointerForThis->GetNext();//the pointers also move the next node
        }//while
    }//if
    while(pointerForThis != nullptr)//if this list is longer than the another, it will copy the rest, doing the same processes
    {
        number = (int) *(pointerForThis->GetMyNumPointerInNode());
        SumMyNum.SetByNumber((long) number);
        pointerForNewNode = new Node(SumMyNum);
        PrevNode->SetNext(*pointerForNewNode);
        PrevNode = PrevNode->GetNext();
        pointerForThis = pointerForThis->GetNext();
    }//while
    while(pointerForAnother != nullptr)//if another list is longer than this, it will copy the rest,doing the same processes
    {
        number = (int) *(pointerForAnother->GetMyNumPointerInNode());
        SumMyNum.SetByNumber((long) number);
        pointerForNewNode = new Node(SumMyNum);
        PrevNode->SetNext(*pointerForNewNode);
        PrevNode = PrevNode->GetNext();
        pointerForAnother = pointerForAnother->GetNext();
    }//while
    LinkedList NewList;//create LinkedList
    NewList.Head = HeadOfNewList;//set the head
    return NewList;
}//operator +
LinkedList& LinkedList::operator +=(const MyNumber & addNumber)
{
    if(!(this->DoesExistInList((int)addNumber)))//only if the value doesn't exist
        putInPlace(addNumber);//put the object in the list
    return *this;
}//operator +=
void LinkedList::putInPlace(const MyNumber & addNumber)
{
    if(Head != nullptr)//if the list isn't empty
    {
        int number = (int)addNumber;//the value in decimal
        Node * Smaller = Head;//need to be smaller than the value
        Node * Bigger = Head->GetNext();//need to be bigger than the value, the new node will come between them
        Node *AddNode;//the pointer for the new node that need to be added
        if((int)*(Smaller->GetMyNumPointerInNode()) > number)//if the value is the smallest and need to be in the beginning
        {
            AddNode = new Node (addNumber);//create the new object with conversion constructor
            AddNode->SetNext(*Smaller);//the new object will pointer on the head
            Head = AddNode;//the head is the new object
            return;
        }//if
        while (Bigger != nullptr)
        {
            if(((int)*(Smaller->GetMyNumPointerInNode()) < number) && ((int)*(Bigger->GetMyNumPointerInNode())) > number)//if the value need to be between two object
            {
                AddNode = new Node(addNumber);//create the new object with conversion constructor
                AddNode->SetNext(*Bigger);//the new object need to point at the bigger than him
                Smaller->SetNext(*AddNode);//the smaller need to point at the new object
                return;
            }//if
            // the right place not found yet the pointers need to move to the next Nodes
            Bigger = Bigger->GetNext();
            Smaller = Smaller->GetNext();
        }//while
        //if the value was bigger than whole list, need to be added to the end of the list
        AddNode = new Node(addNumber);
        Smaller->SetNext(*AddNode);
        return;
    }//if
    Head = new Node(addNumber);//the list is empty
}
LinkedList& LinkedList::operator -=(const MyNumber & addNumber)
{
    int value = addNumber.DecimalValueOfTheObject();//the value in decimal, for the search
    if(this->DoesExistInList(value) == true)//only if the value exist there is something to delete
        DeleteNodeByValue(value);//delete the object that contain the same value
    return *this;
}//operator -=
void LinkedList::DeleteNodeByValue(int value)
{
    if((int)*(Head->GetMyNumPointerInNode()) == value)//if is the head that need to be deleted
    {
        Node * NewHead = Head->GetNext();//get the next node
        delete Head->GetMyNumPointerInNode();//deleted the prev object of MyNumber
        Head = NewHead;//the new head is the next of the prev
    }//if
    else
    {
        Node * prevNode = Head;//th prev is the head
        Node * ObjectToDelete = Head->GetNext();//the next
        Node * NextNode = ObjectToDelete->GetNext();//the next of the current
        while (ObjectToDelete != nullptr)
        {
            if((int)*(ObjectToDelete->GetMyNumPointerInNode()) == value)//the object that need to be deleted
            {
                if(NextNode != nullptr)
                    prevNode->SetNext(*NextNode);//connect the list
                delete *(ObjectToDelete->GetMyNumPointerInNode());//delete the prev object MyNumber
                return;
            }//
            prevNode = prevNode->GetNext();//move to the next node
            ObjectToDelete = ObjectToDelete->GetNext();//move to the next node
            if(NextNode != nullptr)
                NextNode = NextNode->GetNext();
        }//while
    }//else
}//DeleteNode
ostream &operator << (ostream &output, const LinkedList &List)//operator<<
{
    if(List.Head != nullptr)//the list is not empty
    {
        LinkedList Walk;//the pinter that walk on the list
        Walk.Head = List.Head;//turn to node
        while (Walk.Head != nullptr)
        {
            output<<(int)*Walk.Head->GetMyNumPointerInNode()<<endl;
            Walk.Head= Walk.Head->GetNext();//move to the next node
        }//while
    }//if
    return output;
}//operator <<
