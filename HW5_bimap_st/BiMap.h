/* Assignment: 5
Author: Noa Shem Tov
 */

#ifndef HW5_BIMAP_H
#define HW5_BIMAP_H

#include <iostream>
#include <map>

using namespace std;

template<class Value, class Key>

class BiMap {

private:
    map <Value, Key> MapByValue;//the map that the key is the City in this program
    map <Key, Value> MapByKey;//the key in this map is the name

public://using for convenience
    using ValueType = Value;
    using KeyType = Key;
    using ItVK = typename map<Value, Key>::iterator;
    using ItKV = typename map<Key, Value>::iterator;

public:
    BiMap(){;}//constructor
    ~BiMap() { Delete();}//destructor
    bool insert(Value, Key);//insert by value
    bool insert(Key, Value);//insert by key
    bool erase(Value value);//erase by value
    bool erase(Key key);//erase by key
    Value operator[](Key key);//operator by key
    Key operator[](Value value);//operator by value
    int size() const { return MapByValue.size();}//return the size of the maps
    void Delete (){MapByKey.clear();MapByValue.clear();}//delete the elements from the maps
    class iteratorF {
    public:
        using ValueType = typename BiMap<Value,Key>::ValueType;//using for convenience
        using PointerType = ValueType*;//using for convenience
        using RefernceType = ValueType&;//using for convenience
        iteratorF(){;}//constructor
        iteratorF& operator++()
        {
            valuePointer++;
            return *this;
        }//operator++ prefix
        iteratorF operator++(int)
        {
            iteratorF itF = *this;
            ++(*this);
            return itF;
        }//operator++ postfix
        PointerType operator->() { return this;}
        RefernceType operator*(){ return *this;}
        bool operator==(const iteratorF& other)const
        {
            return (valuePointer == other.valuePointer);
        }//operator==
        bool operator!=(const iteratorF other)const
        {
            return (!(*this == other));
        }//operator!=
        ItVK GetPointerF(){return valuePointer;}//get the pointer on the map by value
        void SetPointerF(const ItVK &It){ valuePointer = It;}//set the pointer
    private:
        ItVK valuePointer;//iterator for map by value
    };// class iteratorF
    class iteratorS {
    public:
        using KeyType = typename BiMap<Value,Key>::KeyType;//using for convenience
        using PointerType = KeyType*;//using for convenience
        using RefernceType = KeyType&;//using for convenience
        iteratorS(){;}//constructor
        iteratorS& operator++()
        {
            keyPointer++;
            return *this;
        }//operator++ prefix
        iteratorS operator++(int)
        {
            iteratorS itS = *this;
            ++(*this);
            return itS;
        }//operator++ postfix
        PointerType operator->() { return this;}
        RefernceType operator*(){ return *this;}
        bool operator==(const iteratorS& other)const
        {
            return (keyPointer == other.keyPointer);
        }//operator==
        bool operator!=(const iteratorS other)const
        {
            return (!(*this == other));
        }//operator!=
        ItKV GetPointerS(){return keyPointer;}//get the pointer on the map by key
        void SetPointerS(const ItKV &It){ keyPointer = It; }//set the pointer
    private:
        ItKV keyPointer;//iterator for map by key
    };//class iteratorS
    iteratorF beginF()
    {
        iteratorF it;
        it.SetPointerF(MapByValue.begin());//set the iterator for the map's beginning
        return it;
    }//beginF
    iteratorF endF()
    {
        iteratorF it;
        it.SetPointerF(MapByValue.end());//set the iterator for the map's end
        return it;
    }//endF
    iteratorS beginS()
    {
        iteratorS it;
        it.SetPointerS(MapByKey.begin());//set the iterator for the map's beginning
        return it;
    }//beginS
    iteratorS endS()
    {
        iteratorS it;
        it.SetPointerS(MapByKey.end());//set the iterator for the map's end
        return it;
    }//endS
};//class BiMap
template<class Value, class Key>
bool BiMap<Value, Key>::insert(Value value, Key key)
{
    ItVK pointerVK = MapByValue.find(value);//if the value already existent need to change the map's value
    ItKV pointerKV = MapByKey.find(key);//if the key existent but not the value -> it false, can't do insert
    if (pointerKV != MapByKey.end() && pointerVK != MapByValue.end())
        return false;//both are exist in the BiMap
    if (pointerKV == MapByKey.end() && pointerVK == MapByValue.end())//if both of them not existent
    {
        MapByValue.insert(pair<Value,Key>(value, key));//insert by value
        MapByKey.insert(pair<Key,Value>(key, value));//insert by key
        return true;//the insert succeeded
    }//if
    if (pointerKV == MapByKey.end())//the value existent, do need to do update
    {
        Key temp = MapByValue.at(value);//find the previous key that need to delete
        MapByKey.erase(temp);//delete the key from the key's map
        MapByKey.insert(pair<Key,Value>(key, value));//do insert for the new object, the value that already was with the new key
        MapByValue[value] = key;//update the key
        return true;//return true the insert succeeded
    }//if
    return false;//the key existent but the value doesn't
//    Value temp = MapByKey.at(key);
//    MapByValue.erase(temp);
//    MapByValue.insert(pair<Value,Key>(value, key));
//    MapByKey[key] = value;
//    return true;
}//bool insert
template<class Value, class Key>
bool BiMap<Value, Key>::insert(Key key, Value value)
{
    ItVK pointerVK = MapByValue.find(value);//if the value existent but the key doesn't -> it false the insert can't be done
    ItKV pointerKV = MapByKey.find(key);//if the key already existent need to do update
    if (pointerKV != MapByKey.end() && pointerVK != MapByValue.end())
        return false;//both of them existent in the maps -> the insert can't be done
    if (pointerKV == MapByKey.end() && pointerVK == MapByValue.end()) //new object
    {
        MapByValue.insert(pair<Value,Key>(value, key));
        MapByKey.insert(pair<Key,Value>(key, value));
        return true;
    }//if
    if (pointerKV == MapByKey.end())//the value existent but the key doesn't -> the insert can't be done
    {
        return false;
//        Key temp = MapByValue.at(value);
//        MapByKey.erase(temp);
//        MapByKey.insert(pair<Key,Value>(key, value));
//        MapByValue[value] = key;
//        return true;
    }//if
    //when need to do update//
    Value temp = MapByKey.at(key);//find the old value
    MapByValue.erase(temp);//delete it from the map
    MapByValue.insert(pair<Value,Key>(value, key));//insert the new value with the same key
    MapByKey[key] = value;//update the value in the key map
    return true;//return true the insert succeeded
}//bool insert
template<class Value, class Key>
bool BiMap<Value, Key>::erase(Value value)
{
    if (MapByValue.find(value) == MapByValue.end())//if is there is no value like that in the map there is nothing that needs to be deleted
        return false;
    Key temp = MapByValue.at(value);//find the key of this value
    MapByValue.erase(value);//delete from the map by value
    MapByKey.erase(temp);//delete the key
    return true;//erase succeeded
}//erase By Value
template<class Value, class Key>
bool BiMap<Value, Key>::erase(Key key)//if is there is no value like that in the map there is nothing that needs to be deleted
{
    if (MapByKey.find(key) == MapByKey.end())
        return false;
    Value temp = MapByKey.at(key);//find the key of this value
    MapByKey.erase(key);//delete from the map by key
    MapByValue.erase(temp);//delete from the map by value
    return true;//erase succeeded
}//erase By Key
template<class Value, class Key>
Value BiMap<Value, Key>::operator[](const Key key)
{
    auto & KeyMap = MapByKey;//using KeyMap instead MapByKey
    if(KeyMap.find(key) != KeyMap.end())//check if the key exists
    {
        Value ValueOfKey = KeyMap.at(key);//find his pair
        return ValueOfKey;
    }//
    Value obj = Value();//the key doesn't exist, but something need to be return so ->
    return obj;//<-
}//operator []
template<class Value, class Key>
Key BiMap<Value, Key>::operator[](const Value value)
{
    auto &ValueMap = MapByValue;//using ValueMap instead MapByValue
    if (ValueMap.find(value) != ValueMap.end())//check if the value exists
    {
        Key KeyOfValue = ValueMap.at(value);//find his pair
        return KeyOfValue;
    }//
    Key obj = Key();//the value doesn't exist, but something need to be return so ->
    return obj;//<-
}//operator []
#endif //HW5_BIMAP_H
