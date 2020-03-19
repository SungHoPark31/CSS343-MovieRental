/*-------------------------inventory.h----------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-----------------------------------------------------------------
Purpose - It is an abstract class. The inventory
displays all the movies and contains a Binary Search
Tree that contains NodeData. This was read from the
Store class and is using the inventory BSTree. Movie
class is going to be connected to the Inventory class.
-----------------------------------------------------------------
<fstream> is used to read files.
-----------------------------------------------------------------*/

#ifndef inventory_h
#define inventory_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Inventory
{
public:
    //Constructor
    Inventory();
    
    //Destructor
    virtual ~Inventory();
    
    //SetData and display
    virtual void setData(string line) = 0;
    virtual void display() const = 0;
    
    //Increasing and decreasing stock
    virtual void increase(int stock) = 0;
    virtual void decrease(int stock) = 0;
    
    //Overriding operators.
    virtual bool operator==(const Inventory& other) const = 0;
    virtual bool operator<(const Inventory& other) const = 0;
    virtual bool operator>(const Inventory& other) const = 0;
    //virtual bool operator=(const Inventory& other) const = 0;
    
    //Getters needed.
    virtual int getStock() const= 0;
    virtual int getMaxStock() const = 0;
    virtual string getTitle() const = 0;
    virtual string getGenre() const = 0;
    virtual string getDirector() const = 0;
    virtual int getYear() const = 0;
    virtual string getActor() const = 0;
    virtual string getActorLast() const = 0;
    virtual int getMonth() const = 0;
    
protected:
    int stockNumber;
    int maxStock;
    string title;
    string director;
    string genre;
    int year;
    string actorName;
    string actorLastName;
    int month;
};

#endif /* inventory_h */
