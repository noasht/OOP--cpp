/* Assignment: 2
Author: Noa Shem Tov   */

#include "MyMain.h"

//option for the main menu
enum { UPDATE_NUM1 = 1,UPDATE_NUM2, MOVE_TO_NUMBERS_MENU, MOVE_TO_LIST_MENU, EXIT };

//option for the second menu NUMBERS
enum { ADD = 1 , MULT, DEVIDE, MOUDULO , PLUS_ONE, COMPARE,PRINT_INT , RETURN_TO_MAIN };

//option for the third menu LISTS
enum {ADD_NUM1 = 1, REMOVE_NUM1, PRINT , ADD_LIST ,RETURN_TO_MAIN_MENU};

 MyMain::MyMain()
{
    int choice = NEG_ONE;//the choice of the user
    while (choice != EXIT)//until the user want to sign out
    {
        cout << "Please choose one of the following option:" << endl;
        cout << "\t1.Update value to Num1" << endl;
        cout << "\t2.Update value to Num2" << endl;
        cout << "\t3.Move to Numbers Menu" << endl;
        cout << "\t4.Move to List Menu" << endl;
        cout << "\t5.Exit " << endl;
        cin >> choice;
        switch (choice)
        {
            case UPDATE_NUM1:
                UpdateValueToNum1();
                break;
            case UPDATE_NUM2:
                UpdateValueToNum2();
                break;
            case MOVE_TO_NUMBERS_MENU:
                NumbersMenu();
                break;
            case MOVE_TO_LIST_MENU:
                ListMenu();
                break;
            case EXIT:
                cout<<"Goodbye"<<endl;
        }//switch
    }//while
}//MyMain

//main menu
void MyMain::NumbersMenu()
{
     int choice = NEG_ONE;
    while (choice != RETURN_TO_MAIN)
    {
        cout << "Please choose one of the following option:" << endl;
        cout << "\t1.Add the numbers" << endl;
        cout << "\t2.Multiple the numbers" << endl;
        cout << "\t3.Devide the numbers" << endl;
        cout << "\t4.Modulo the numbers" << endl;
        cout << "\t5.Add 1 to num1" << endl;
        cout << "\t6.Compare numbers" << endl;
        cout << "\t7.Print numbers as int" << endl;
        cout << "\t8.Return to main menu" << endl;
        cin >> choice;
        switch (choice) {
            case ADD:
                AddTheNumbers();
                break;
            case MULT:
                MultipleTheNumbers();
                break;
            case DEVIDE:
                DevideTheNumbers();
                break;
            case MOUDULO:
                ModuloTheNmbers();
                break;
            case PLUS_ONE:
                AddOneToNum1();
                break;
            case COMPARE:
                CompareNumbers();
                break;
            case PRINT_INT:
                PrintNumbersAsInt();
                break;
            case RETURN_TO_MAIN:
                cout << "The main menu:" << endl;
        }//switch
    }//while
}//NumbersMenu
void MyMain::UpdateValueToNum1()
{
    long number;
    cout<<"please enter number to adding the object num1"<<endl;
    cin>>number;
    if(number > ZERO)//only if the value is valid
        num1.SetByNumber(number);
}//UpdateValueToNum1
void MyMain::UpdateValueToNum2()
{
    long number;
    cout<<"please enter number to adding the object num2"<<endl;
    cin>>number;
    if(number > ZERO)//only if the value is valid
        num2.SetByNumber(number);
 }//UpdateValueToNum2
void MyMain::ListMenu()
{
    int choice = NEG_ONE;
    while (choice != RETURN_TO_MAIN_MENU)
    {
        cout << "Please choose one of the following options:" << endl;
        cout << "\t1.Add Num1 To List" << endl;
        cout << "\t2.Remove num1 from list" << endl;
        cout << "\t3.Print list" << endl;
        cout << "\t4.Add Lists" << endl;
        cout << "\t5.Return To Main Menu" << endl;
        cin >> choice;
        switch (choice)
        {
            case ADD_NUM1:
                AddNum1ToList();
                break;
            case REMOVE_NUM1:
                RemoveNum1FromList();
                break;
            case PRINT:
                PrintList();
                break;
            case ADD_LIST:
                AddLists();
                break;
            case RETURN_TO_MAIN_MENU:
                cout << "return to main menu" << endl;
        }//switch
    }//while
}//ListMenu

//numbers menu
void MyMain::AddTheNumbers()
{
    MyNumber SUM = num1 + num2;//the sum of 2 object;
    SUM.BinaryPrint();
}//AddTheNumbers
void MyMain::MultipleTheNumbers()
{
    MyNumber SUM = num1 * num2;//the product
    SUM.BinaryPrint();
}//MultipleTheNumbers
void MyMain::DevideTheNumbers()
{
     int valueNUM1 = num1.DecimalValueOfTheObject();//the value of num1 in decimal
     int valueNUM2 = num2.DecimalValueOfTheObject();//the value of num2 in decimal
     if(valueNUM1 != ZERO)
     {
         MyNumber DIV12 = num2 / num1;
         cout<<valueNUM2<< " / "<<valueNUM1<<" in binary is ";
         DIV12.BinaryPrint();
     }//if
     else
         cout<<"ERROR num1 == ZERO, It is impossible to divide by zero"<<endl;
    if(valueNUM2 != ZERO)
    {
        MyNumber DIV12 = num1 / num2;
        cout<<valueNUM1<< " / "<<valueNUM2<<" in binary is ";
        DIV12.BinaryPrint();
    }//if
    else
        cout<<"ERROR num2 == ZERO, It is impossible to divide by zero"<<endl;
}//DevideTheNumbers
void MyMain::ModuloTheNmbers()
{
    int valueNUM1 = num1.DecimalValueOfTheObject();
    int valueNUM2 = num2.DecimalValueOfTheObject();
    if(valueNUM1 != ZERO)
    {
        MyNumber DIV12 = num2 % num1;
        cout<<valueNUM2<< " % "<<valueNUM1<<" in binary is ";
        DIV12.BinaryPrint();
    }//if
    else
        cout<<"ERROR num1 == ZERO"<<endl;
    if(valueNUM2 != ZERO)
    {
        MyNumber DIV12 = num1 % num2;
        cout<<valueNUM1<< " % "<<valueNUM2<<" in binary is ";
        DIV12.BinaryPrint();
    }//if
    else
        cout<<"ERROR num2 == ZERO"<<endl;
}//ModuloTheNmbers
void MyMain::AddOneToNum1()
{
    ++num1;
}//AddOneToNum1
void MyMain::CompareNumbers()
{
    int valueNum1 = num1.DecimalValueOfTheObject();
    int valueNum2 = num2.DecimalValueOfTheObject();
    if(num1.AreTheseTwoObjectEquals(num2))
    {
        cout<<"num1 and num2 are equal"<<endl;
        cout<<"the Binary number of "<<valueNum1<<" is"<<endl;
        num1.BinaryPrint();
    }//if
   else
   {
        if (num1 < num2)
        {
            cout<< "num2 is bigger than num1" << endl;
            cout<<"the Binary number of "<<valueNum2<<" is"<<endl;
            num2.BinaryPrint();
        }//if
        else
        {
            cout<< "num1 is bigger than num2" << endl;
            cout<<"the Binary number of "<<valueNum1<<" is"<<endl;
            num1.BinaryPrint();
        }//if
    }//else
}//CompareNumbers
void MyMain::PrintNumbersAsInt()
{
    cout<<"the values of num1 and num2 are "<<endl;
    cout<<num1.DecimalValueOfTheObject()<< " " <<num2.DecimalValueOfTheObject() <<endl;
}//PrintNumbersAsInt

//list menu
void MyMain::AddNum1ToList()
{
     int choice;
     cout<<"we need to add num1 to a list"<<endl;
     cout<<"please choose which list you would like to add to "<<endl;
     cout<<"type 1 for the first list , 0 for the second"<<endl;
     cin>>choice;
     if(choice == ONE)
         list1 += num1;
     else
         list2 += num1;
}//AddNum1ToList
void MyMain::RemoveNum1FromList()
{
    int choice;
    cout<<"we need to remove num1 from a list"<<endl;
    cout<<"please choose which list you would like to remove from "<<endl;
    cout<<"type 1 for the first list , 0 for the second"<<endl;
    cin>>choice;
    if(choice == ONE)
        list1 -= num1;
    else
        list2 -= num1;
}//RemoveNum1FromList
void MyMain::PrintList()
{
    int choice;
    cout<<"we need to print a list"<<endl;
    cout<<"please choose which list you would like to print "<<endl;
    cout<<"type 1 for the first list , 0 for the second"<<endl;
    cin>>choice;
    if(choice == ONE)
        cout<<list1;
    else
        cout<<list2;
}//PrintList
void MyMain::AddLists()
{
    LinkedList listNew = list2 + list1;
    cout<<listNew;
}//AddLists