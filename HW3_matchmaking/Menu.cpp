/* Assignment: 3
Author: Noa Shem Tov, ID: 207000134   */

#include "Menu.h"
#define FEMALE 'F'

Menu::Menu()
{
    cout<<'\n';
    while (ONE)
    {
        cout<<"=================================================================="<<endl;
        cout << "Please choose one of the following options: " << endl;
        cout << "     1 ) Add a new client to the database" << endl;
        cout << "     2 ) Remove an existing client from the database" << endl;
        cout << "     3 ) Print all clients" << endl;
        cout << "     4 ) Print all matches for a client" << endl;
        cout << "     5 ) Quit the program" << endl;
        cout<<"=================================================================="<<endl;
        int choice;
        cin>>choice;
        getchar();
        switch (choice)
        {
            case ONE:
                AddClient();
                break;
            case TWO:
                RemoveClient();
                break;
            case THREE:
                PrintThaAgency();
                break;
            case FOUR:
                SearchAllOptions();
                break;
            case FIVE:
                cout<<"The agency close\nThank you for using our service\nGoodBye"<<endl;
                return;
            default:
                cout<<"please chose one of the option below "<<endl;
        }//switch
    }//while
}//Menu constructor
Menu& Menu::AddClient()
{
    char BufferID [MAX_SIZE_ID];
    cout<<"In order to register with the matchmaking office, please write down the following details"<<endl;
    cout<< "your ID:  "<<endl;
    cin.get(BufferID,MAX_SIZE_OF_STRING);
    MyString IDPerson (BufferID);
    char BufferName [MAX_SIZE_OF_STRING];
    getchar();
    cout<< "your full name: "<<endl;
    cin.getline(BufferName,MAX_SIZE_OF_STRING);
    MyString NamePerson (BufferName);
    cout<< "your Gender: \nM for male F for female"<<endl;
    char genderPerson;
    cin>>genderPerson;
    cout<< "your age - only 18+"<<endl;
    int AgePerson;
    cin>>AgePerson;
    int AmountHobbiesPerson;
    cout << "please enter the amount of your hobbies: "<<endl;
    cin>>AmountHobbiesPerson;
    getchar();
    char **hobbiesPerson = nullptr;
    if(AmountHobbiesPerson > ZERO)
    {
        hobbiesPerson = new char * [AmountHobbiesPerson];
        for(int i = ZERO; i < AmountHobbiesPerson; i++)
            hobbiesPerson[i] = inputHobbies(hobbiesPerson[i],i);
    } //if
    else AmountHobbiesPerson = ZERO;
    int VIP;
    cout<<"are you VIP client? for YES type 1 for NO type 0"<<endl;
    cin>>VIP;
    if(VIP == ONE)
    {
        cout<<"pleas type how many hobbies you want in common "<<endl;
        cin>>VIP;
        Client * Person = new VIPClient (IDPerson, NamePerson, genderPerson, AgePerson, hobbiesPerson, AmountHobbiesPerson,VIP);
        Agency += (*Person);
        Client * ThePerson = Agency.IsPersonFound(Person->GetID());//returned the address or null
        if(ThePerson == nullptr)//the person not exist
            cout<<"please try again,The details are incorrect"<<endl;
        else
        cout<<"VIP client added to the Agency\nwelcome"<<endl;
    }//if
    else
    {
        Client * Person = new Client (IDPerson, NamePerson, genderPerson, AgePerson, hobbiesPerson, AmountHobbiesPerson);
        Agency += (*Person);
        Client * ThePerson = Agency.IsPersonFound(Person->GetID());//returned the address or null
        if(ThePerson == nullptr)//the person not exist
            cout<<"please try again,The details are incorrect"<<endl;
        else
        cout<<"you added as a client\nwelcome"<<endl;
    }//else
    if(hobbiesPerson != nullptr)//delete the array of hobby
    {
        for(int i = ZERO; i < AmountHobbiesPerson; i++)
            delete [] hobbiesPerson[i];
        delete [] hobbiesPerson;
        hobbiesPerson = nullptr;
    }//if
    IDPerson.DeleteOB();
    NamePerson.DeleteOB();
    return *this;
}//AddClient
char* Menu::inputHobbies(char * &Hobby, int numberOfHobby)const
{
    char Buffer [MAX_SIZE_OF_STRING];//buffer of 120 char
    cout<<"pleas enter hobby number "<< numberOfHobby + ONE<<endl;
    cin.getline(Buffer,MAX_SIZE_OF_STRING);
    Hobby = new char [(int)(strlen(Buffer)) + ONE];//the new hobby
    strcpy(Hobby,Buffer);
    return Hobby;
}//inputHobbies
Menu& Menu::RemoveClient()
{
    char BufferID [MAX_SIZE_OF_STRING];
    cout<<"In order to delete the client from the data base pleas enter Client's ID"<<endl;
    cin.get(BufferID,MAX_SIZE_OF_STRING);
    MyString IDPerson (BufferID);
    Client * ThePerson = Agency.IsPersonFound(IDPerson);//returned the address for the object, if there is no object returned null
    if(ThePerson == nullptr)
    {
        if(Agency.GetArrOfClient() == nullptr)
        {
            cout << "The agency has no clients" << endl;
            return *this;
        }//if
        cout << "There is no person with this ID in the system " << endl;
        return *this;
    }//if
    Agency -= *(ThePerson);//remove the object using the -= of Client
    if(ThePerson->GetGender() == FEMALE)
        cout<<"I hope you found your husband"<<endl;
    else cout<<"I hope you found your wife"<<endl;
    cout<<"Client successfully removed"<<endl;
    IDPerson.DeleteOB();
    return *this;
}//RemoveClient
void Menu::PrintThaAgency()const
{
    if(Agency.GetArrOfClient() == nullptr)
        cout<<"There is no client's"<<endl;
    else cout<<Agency;//operator << of MatchMaking
}//PrintThaAgency
void Menu::SearchAllOptions()const
{
    char BufferID [MAX_SIZE_OF_STRING];
    cout<<"In order to find a match for the client please type Client's ID"<<endl;
    cin.get(BufferID,MAX_SIZE_OF_STRING);
    MyString IDPerson (BufferID);//created MyString from id
    Client * ThePerson = Agency.IsPersonFound(IDPerson);//returned the address or null
    if(ThePerson == nullptr)//the person not exist
    {
        if(Agency.GetArrOfClient() == nullptr)
        {
            cout << "The agency has no clients" << endl;
            return;
        }//if
        cout << "There is no person with this ID in the system " << endl;
        return;
    }//if
    if(!(Agency.searchByID(IDPerson)))//if there is no match
        cout<<"Sorry\nThere is currently no match for the customer"<<endl;
    IDPerson.DeleteOB();
}//SearchAllOptions

