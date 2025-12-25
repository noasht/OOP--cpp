/* Assignment: 5
Author: Noa Shem Tov
 */

# ifndef BIMAP_H_MENU_H
# define BIMAP_H_MENU_H

# include <string>
# include "BiMap.h"
# include "City.h"
# include <fstream>
# include "Exception.h"
# include "exceptionCity.h"
# include "exceptionRep.h"

template <class iteratorFor, class dataType>
bool Find (iteratorFor IT,dataType ValueRequested,int size)//template for finding object in the map the function get:
//the operator for the map; the value that we're looking for ; the size of the map
{
    int i = ONE;
    while (i <= size)
    {
        if(IT->first == ValueRequested)//if the value found
            return true;
        i++;
        IT++;
    }//while
    return false;//else if the value is not in the map
}//find
enum {TWO = 2,THREE, FOUR, FIVE, SIX, SEVEN,EIGHT,NINE,TEN,ELEVEN,TWELVE};

class Menu {
private:
    bool FoundIDCity (BiMap<City<long>, string>& Bimap, long ID)const;//return true if the object exist in the map
public:
    Menu (BiMap<City<long>, string>& Bimap);//constructor
    bool AddCity (BiMap<City<long>, string>& Bimap,fstream &file);//option 1
    bool addName (BiMap<City<long>, string>& Bimap, fstream &file);//option 2
    bool eraseByCity (BiMap<City<long>, string>& Bimap,fstream &file);//option 3
    bool eraseByName (BiMap<City<long>, string>& Bimap,fstream &file);//option 4
    bool getCity (BiMap<City<long>, string>& Bimap,fstream &file);//option 5
    bool getName (BiMap<City<long>, string>& Bimap,fstream &file);//option 6
    bool isCity (BiMap<City<long>, string>& Bimap,fstream &file);//option 7
    bool isName (BiMap<City<long>, string>& Bimap,fstream &file);//option 8
    bool sortByCity (BiMap<City<long>, string>& Bimap);//option 9
    bool sortByName (BiMap<City<long>, string>& Bimap);//option 10
    void Clean (BiMap<City<long>, string>& Bimap);//option 11
    bool InvalidOutPut();//if the input is not between 1 and 12
    bool check(string str);//check the string id it includes only letters and hyphen
};
#endif //BIMAP_H_MENU_H