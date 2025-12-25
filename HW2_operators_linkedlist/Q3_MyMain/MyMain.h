/* Assignment: 2
Author: Noa Shem Tov */

#ifndef HW2_MYMAIN_H
#define HW2_MYMAIN_H

#include "LinkedList.h"

class MyMain {

private:

    MyNumber num1;
    MyNumber num2;
    LinkedList list1;
    LinkedList list2;
    //main menu
   void NumbersMenu();
   void UpdateValueToNum1();
   void UpdateValueToNum2();
   void ListMenu();
    //numbers menu
   void	AddTheNumbers();
   void MultipleTheNumbers();
   void DevideTheNumbers();
   void ModuloTheNmbers();
   void AddOneToNum1();
   void CompareNumbers();
   void PrintNumbersAsInt();
    //list menu
   void AddNum1ToList();
   void RemoveNum1FromList();
   void PrintList();
   void AddLists();

public:
    MyMain();
};


#endif //HW2_MYMAIN_H
