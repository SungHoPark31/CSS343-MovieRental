/*------------------------hashTable.h-----------------------
Sung Ho Park, Makoto Quincy Booth
3/12/2020
------------------------------------------------------------
Purpose - This is a template class of Hash Tables.
------------------------------------------------------------
<algorithms>, <maps> were used for specific algorithms
and maps were used for the key value type of data
structure.
-----------------------------------------------------------*/

#ifndef hashTable_h
#define hashTable_h

#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include "customer.h"

using namespace std;

//Template class.
template <typename k, typename v>
class HashTable
{
public:
    //Constructor
    HashTable();
    
    //Overloading Constructor
    HashTable(const k key, const v value);
    
    //IsEmpty
    bool isEmpty();
    
    //getNumOfKeys
    int getNumOfKeys();
    
    //add
    bool add(k key, v value);
    
    //remove
    bool remove(k key);
    
    //clear the table.
    void clear();
    
    //Gets the value from the key
    v getVal(const k key);
    
    //Sets the value
    void setVal(k key, v value);
    
    //Contains.
    bool contains(k key) const;
    
    //Get the vector of keys
    vector<k> getKeyVec() const;
    
    //Gets the Vector of values.
    vector<v> getValVec() const;
    
    //Prints the keys
    void printKeys() const;
    
    //Removes the key from the vector
    void removeKeyFromVector(k input);
    
private:
    //Private variables
    map<k, v> hash;
    vector<k> keys;
    vector<v> values;
    int numOfKeys;
};

/*---------------------Constructor--------------------------
Description: Constructs the HashTable objects.

Precondition: None
Postcondition: Initializes the private variables.
---------------------------------------------------------*/
template <typename k, typename v>
HashTable<k, v>::HashTable()
{
    //Num keys is 0
    numOfKeys = 0;
}
//End of Constructor.

/*------------------Overloading Constructor------------------
Description: Constructs the HashTable objects and
initializes the private variables with the
parameters. This adds a key in the hash table.

Precondition: None
Postcondition: Initializes the private variables.
------------------------------------------------------------*/
template <typename k, typename v>
HashTable<k, v>::HashTable(const k key, const v value)
{
    //Because this constructor is adding a key and
    //value, increment numOfKeys
    numOfKeys++;
    hash[key] = value;
    keys.push_back(key);
}
//End of Destructor

/*------------------------isEmpty----------------------------
Description: Checks if the hash table is empty or not.

Precondition: None
Postcondition: Returns true if numKeys is 0
------------------------------------------------------------*/
template <typename k, typename v>
bool HashTable<k, v>::isEmpty()
{
    //Checks if the keys is 0.
    if (numOfKeys == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//End of isEmpty

/*-----------------------getNumOfKeys------------------------
Description: Gets the number of keys.

Precondition: None
Postcondition: Returns numKeys
------------------------------------------------------------*/
template <typename k, typename v>
int HashTable<k, v>::getNumOfKeys()
{
    return numOfKeys;
}
//End of getNumKeys

/*----------------------------add-----------------------------
Description: Adds key and value to the hash table.

Precondition: The objects being passed in is created.
Postcondition: Adds key and value to the HashTable.
-------------------------------------------------------------*/
template <typename k, typename v>
bool HashTable<k, v>::add(k key, v value)
{
    //Counts if the key value is 0 in the hash table.
    if (hash.count(key) == 0)
    {
        //The 0 represents empty.
        //If there is a key == 0. Then add the key and
        //the value to the hash table.
        numOfKeys++;
        hash[key] = value;
        keys.push_back(key);
        return true;
    }
    else
    {
        //If that key is filled, then false.
        return false;
    }
}
//End of add.

/*----------------------------Remove----------------------------
Description: Removes key and value to the hash table.

Precondition: The objects being passed in is created.
Postcondition: Removes key and value to the HashTable.
--------------------------------------------------------------*/
template <typename k, typename v>
bool HashTable<k, v>::remove(k key)
{
    //If the key value is 1, meaning there is a value
    //in that key...
    if (hash.count(key) == 1)
    {
        //Erase the key.
        hash.erase(key);
        removeKeyFromVector(key);
        return true;
    }
    else
    {
        //If there is nothing, empty spot, don't
        //remove
        return false;
    }
}
//End of Remove.

/*----------------------------clear----------------------------
Description: Clears the hash table.

Precondition: None
Postcondition: Clears the HashTable.
-------------------------------------------------------------*/
template <typename k, typename v>
void HashTable<k, v>::clear()
{
    //Uses the vector STL's clear
    hash.clear();
    keys.clear();
}
//End of clear.

/*---------------------------getVal------------------------------
Description: Gets the value from the hash table.

Precondition: The objects being passed in is created.
Postcondition: Gets the value from the hash table.
--------------------------------------------------------------*/
template <typename k, typename v>
v HashTable<k, v>::getVal(const k key)
{
    return hash[key];
}
//End of getVal

/*---------------------------setVal----------------------------
Description: Sets the value from the hash table.

Precondition: The objects being passed in is created.
Postcondition: Sets the value from the hash table.
--------------------------------------------------------------*/
template <typename k, typename v>
void HashTable<k, v>::setVal(k key, v value)
{
    hash.erase(key);
    hash[key] = value;
}
//End of SetVal

/*--------------------------contains---------------------------
Description: Checks if a key is in the Hash Table.

Precondition: The objects being passed in is created.
Postcondition: Returns true if that key is in the
hash table.
-------------------------------------------------------------*/
template <typename k, typename v>
bool HashTable<k, v>::contains(k key) const
{
    //1 means filled. If it is filled, then return
    //true.
    if (hash.count(key) == 1)
    {
        return true;
    }
    else
    {
        //0 means empty, then return false.
        return false;
    }
}

/*----------------------------getKeyVec---------------------------
Description: Gets the vector keys.

Precondition: None
Postcondition: Gets the vector keys.
--------------------------------------------------------------*/
template <typename k, typename v>
vector<k> HashTable<k, v>::getKeyVec() const
{
    return keys;
}
//End of getKey

/*--------------------------getValVec-------------------------
Description: Gets the Value from the vector

Precondition: None
Postcondition: Gets the vector values.
-------------------------------------------------------------*/
template <typename k, typename v>
vector<v> HashTable<k, v>::getValVec() const
{
    return values;
}
//End of getVal

/*---------------------------printKeys--------------------------
Description: Prints the keys.

Precondition: None
Postcondition: Prints the keys.
-------------------------------------------------------------*/
template <typename k, typename v>
void HashTable<k, v>::printKeys() const
{
    for (int i = 0; i < keys.size(); i++)
    {
        cout << keys[i] << endl;
    }
}
//End of printKeys

/*----------------------removeKeyFromVector----------------------
Description: Removes the key passed in for input
from the vector that stores all keys

Precondition: Parameters object exists.
Postcondition: Removes the key passed in for input from the
vector that stores all keys
----------------------------------------------------------------*/
template <typename k, typename v>
void HashTable<k, v>::removeKeyFromVector(k input)
{
    //Look for the key value.
    for (int i = 0; i < keys.size(); i++)
    {
        //If you found it, remove it.
        if (keys[i] == input)
        {
            keys.erase(keys.begin() + i);
        }
    }
}

#endif /* hashTable_hpp */
