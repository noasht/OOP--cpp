/* Assignment: 4 Question 2
Author: Noa Shem Tov
 */

#include "LinkedList.h"

#define ZERO 0

#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define NO 'N'
#define YES 'Y'
#define TWENTY 20

void menu(LinkedList &list);//the menu
void CreateTheChain(LinkedList &list );//create the chain's shapes
void CreateCircle(LinkedList &list);
void CreateCylinder(LinkedList &list);
void CreateRectangle(LinkedList &list);
void CreateRing(LinkedList &list);
void CreateCuboid(LinkedList &list);
void MenuFunctions(LinkedList &list);
void PrintTheList(LinkedList &list);
void PrintSumVolume();
bool StringComparison(char *str1, char *str2);

int main()
{
    LinkedList list;
    menu(list);
    return 0;
}//MAIN
void menu(LinkedList &list)
{
    cout << "\tHello!";
    CreateTheChain(list);
    MenuFunctions(list);
}//menu
void MenuFunctions(LinkedList &list)
{
    while (ONE) {
        cout << "Please choose one of the following options: " << endl;
        cout << "     1 ) Print the all shapes" << endl;
        cout << "     2 ) Print by color" << endl;
        cout << "     3 ) Print by volume" << endl;
        cout << "     4 ) Print by shape" << endl;
        cout << "     5 ) Print the sum of the areas of all shapes" << endl;
        cout << "     6 ) Print the sum of the volumes of all shapes " << endl;
        cout << "     7 ) Quit the program" << endl;
        int choice;
        cin >> choice;
        getchar();
        switch (choice) {
            case ONE:
                PrintTheList(list);
                break;
            case TWO:
                PrintByColor(list);
                break;
            case THREE:
                PrintBiggerThenMinVolume(list);
                break;
            case FOUR:
                PrintByKindOfShape(list);
                break;
            case FIVE:
                PrintSumArea(list);
                break;
            case SIX:
                PrintSumVolume();
                break;
            case SEVEN:
                cout << "Thanks and goodbye" << endl;
                return;
            default:
                cout << "please chose one of the option below " << endl;
        }//switch
    }//while
}//MenuFunctions
void CreateTheChain(LinkedList &list )
{
    cout << "\nPlease enter the amount of the shapes you want to type" << endl;
    int Amount;
    cin >> Amount;
    if(Amount < ONE)
        Amount = TWO;
    int i = ZERO;
    while (i < Amount) {
        cout << "What kind of shape do you want to type\nPlease choose one of the following options: " << endl;
        cout << "     1 ) Circle" << endl;
        cout << "     2 ) Cylinder" << endl;
        cout << "     3 ) Ring" << endl;
        cout << "     4 ) Rectangle" << endl;
        cout << "     5 ) Cuboid" << endl;
        int choice;
        cin >> choice;
        getchar();
        switch (choice) {
            case ONE:
                cout<<"Shape "<< i + ONE<<" out of "<< Amount <<endl;
                CreateCircle(list);
                i++;
                break;
            case TWO:
                cout<<"Shape "<< i + ONE<<" out of "<< Amount <<endl;
                CreateCylinder(list);
                i++;
                break;
            case THREE:
                cout<<"Shape "<< i + ONE<<" out of "<< Amount <<endl;
                CreateRing(list);
                i++;
                break;
            case FOUR:
                cout<<"Shape "<< i + ONE<<" out of "<< Amount <<endl;
                CreateRectangle(list);
                i++;
                break;
            case FIVE:
                cout<<"Shape "<< i + ONE<<" out of "<< Amount <<endl;
                CreateCuboid(list);
                i++;
                break;
            default:
                cout << "please chose one of the option below " << endl;
        }//switchCase
    }//for
}//CreateTheChain
void CreateCircle(LinkedList &list)
{
    cout << "Please enter the following data for the Circle" << endl;
    char color[TWENTY];
    cout << "Please type the color for the Circle" << endl;
    cin.getline(color, TWENTY);
    float radius;
    cout << "Please type the radius for the Circle" << endl;
    cin >> radius;
    Circle *Ob = new Circle(radius, color);
    list += *Ob;
    cout<<"Circle added successfully"<<endl;
}//CreateCircle
void CreateCylinder(LinkedList &list)
{
    cout << "Please enter the following data for the Cylinder" << endl;
    char color[TWENTY];
    cout << "Please type the color for the Cylinder" << endl;
    cin.getline(color, TWENTY);
    float radius;
    cout << "Please type the radius for the Cylinder" << endl;
    cin >> radius;
    float height;
    cout << "Please type the height for the Cylinder" << endl;
    cin >> height;
    Cylinder *Ob = new Cylinder(height, radius, color);
    list += *Ob;
    cout<<"Cylinder added successfully"<<endl;
}//CreateCylinder
void CreateRectangle(LinkedList &list)
{
    cout << "Please enter the following data for the Rectangle" << endl;
    char color[TWENTY];
    cout << "Please type the color for the Rectangle" << endl;
    cin.getline(color, TWENTY);
    float length;
    float width;
    cout << "Please type the length for the Rectangle" << endl;
    cin >> length;
    cout << "Please type the width for the Rectangle" << endl;
    cin >> width;
    Rectangle *Ob = new Rectangle(length, width, color);
    list += *Ob;
    cout<<"Rectangle added successfully"<<endl;
}//CreateRectangle
void CreateRing(LinkedList &list)
{
    cout << "Please enter the following data for the Ring" << endl;
    char color[TWENTY];
    cout << "Please type the color for the Ring" << endl;
    cin.getline(color, TWENTY);
    float radius;
    cout << "Please type the radius number 1 for the Ring" << endl;
    cin >> radius;
    float radius1;
    cout << "Please type the radius number 2 for the Ring" << endl;
    cin >> radius1;
    Ring *Ob = new Ring(radius, radius1, color);
    list += *Ob;
    cout<<"Ring added successfully"<<endl;
}//CreateRing
void CreateCuboid(LinkedList &list)
{
    cout << "Please enter the following data for the Cuboid" << endl;
    char color[TWENTY];
    cout << "Please type the color for the Cuboid" << endl;
    cin.getline(color, TWENTY);
    float length;
    float width;
    cout << "Please type the length for the Cuboid" << endl;
    cin >> length;
    cout << "Please type the width for the Cuboid" << endl;
    cin >> width;
    float height;
    cout << "Please type the height for the Cuboid" << endl;
    cin >> height;
    Cuboid *Ob = new Cuboid(height, length, width, color);
    list += *Ob;
    cout<<"Cuboid added successfully"<<endl;
}//CreateCuboid
void PrintTheList(LinkedList &list)
{
    cout << "The shapes are " << endl;
    cout << list;
}//PrintTheList
bool StringComparison(char *str1, char *str2)
{
    int size = (int)strlen(str1);
    if (size != strlen(str2))//first checking the size
        return false;
    for (int i = 0; i < size; ++i)//second checking each cell
    {
        if (str1[i] != str2[i])
            return false;
    }//for
    return true;
}//StringComparison
void PrintByColor(LinkedList &list)
{
    char flag = NO;//sign to know if there is shapes like the user want
    cout << "To print the objects, please enter a color" << endl;
    char color[TWENTY];
    cin.getline(color, TWENTY);
    LinkedList::Node *Walk = list.Head;
    while (Walk != nullptr)
    {
        if (StringComparison(Walk->GetMyPointerInNode()->GetColor(), color))
        {
            cout << *Walk->GetMyPointerInNode();
            flag = YES;
        }//if
        Walk = Walk->GetNext();//move to the next object
    }//while
    if (flag == NO)
        cout << "There are no shapes in this color" << endl;
}//PrintByColor
void PrintBiggerThenMinVolume(LinkedList &list)
{
    char flag = NO;//sign to know if there is shapes like the user want
    cout << "To print the objects, please enter a Volume" << endl;
    float MinVolume;
    cin >> MinVolume;
    LinkedList::Node *Walk = list.Head;
    while (Walk != nullptr)
    {
        //checking if the object is shape that has a volume
        Cylinder * tempCylinder = dynamic_cast<Cylinder*>((Walk->GetMyPointerInNode()));
        Cuboid * tempCuboid = dynamic_cast<Cuboid*>((Walk->GetMyPointerInNode()));
        if (tempCylinder != nullptr && tempCylinder->Volume() > MinVolume)
        {
            if( tempCylinder->Volume() > MinVolume)
            {
                cout << *tempCylinder;
                flag = YES;
            }//if
        }//if->if
        else if( tempCuboid != nullptr && tempCuboid->Volume() > MinVolume)
        {
            cout << *tempCuboid;
            flag = YES;
        }//if
        Walk = Walk->GetNext();
    }//while
    if (flag == NO)
        cout << "There are no shapes that have a larger volume" << endl;
}//PrintBiggerThenMinVolume
void PrintByKindOfShape(LinkedList &list)
{
    cout<<"To print the objects, please enter a kind of shape"<< endl;
    char shape[TWENTY];
    char flag = NO;
    cin.getline(shape,TWENTY);
    LinkedList::Node *Walk = list.Head;
    while (Walk != nullptr)
    {
        if (StringComparison(Walk->GetMyPointerInNode()->GetShape(),shape))//if is the same shape
        {
            cout << *Walk->GetMyPointerInNode();//print the object
            flag = YES;
        }//if->if
        Walk = Walk->GetNext();
    }//while
    if (flag == NO)
        cout << "No shape exists"<< endl;
}//PrintByKindOfShape
void PrintSumVolume()
{
    cout << "\tThe sum of the volumes of all shapes " << Shape::GetVolume() << endl;
}//PrintSumVolume
void PrintSumArea(LinkedList & list)
{
    float SumArea = ZERO;
    LinkedList::Node *Walk = list.Head;
    while (Walk != nullptr)
    {
        SumArea += Walk->GetMyPointerInNode()->Area();//calculate the area in each cell
        Walk = Walk->GetNext();
    }//while
    cout << "\tThe sum of the areas of all shapes " << SumArea << endl;
}//PrintSumArea
