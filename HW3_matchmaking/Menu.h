/* Assignment: 3
Author: Noa Shem Tov, ID: 207000134   */

#ifndef HW3_MENU_H
#define HW3_MENU_H

#include "MatchmakingAgency.h"

#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define MAX_SIZE_OF_STRING 120
#define MAX_SIZE_ID 9

class Menu {

private:
    MatchmakingAgency Agency;

    Menu& AddClient();//adding
    Menu& RemoveClient();//removing
    void PrintThaAgency()const;//print
    void SearchAllOptions()const;//search the options by id
    char* inputHobbies(char * &Hobby, int numberOfHobby)const;//private function coping of hobbies not in flat way

public:
    Menu();
};
#endif //HW3_MENU_H
