/*-------------------------classic.h---------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
---------------------------------------------------------------
Purpose - Derived from the Movie class, this will
contain the genre which is read from the Store class.
The private variables for this class are different
because it contains just the actor and release date.
This is a genre of the Movie class that is contained
in the BSTree.
--------------------------------------------------------------*/

#ifndef classic_h
#define classic_h

#include <iostream>
#include <stdio.h>
#include <fstream>
#include "movie.h"
#include "inventory.h"

using namespace std;

class Classic : public Movie
{
public:
    //Constructor
    Classic();
    
    //Destructor
    ~Classic();
    
    //SetData and display
    virtual void setData(string line);
    virtual void display() const;
    
    //Overriding operators
    virtual bool operator==(const Inventory& rhs) const;
    virtual bool operator<(const Inventory& rhs) const;
    virtual bool operator>(const Inventory& rhs) const;
    //virtual bool operator=(const Inventory& other) const = 0;
    
    //splitting an extra string.
    void splitAndInitialize(string line);
    
    //Increase and decrease stock
    void increase(int stock);
    void decrease(int stock);
    
    //Getters needed.
    int getStock() const;
    int getMaxStock() const;
    string getTitle() const;
    string getGenre() const;
    string getDirector() const;
    int getYear() const;
    string getActor() const;
    string getActorLast() const;
    int getMonth() const;
    
private:
    string actorName;
    string actorLastName;
    int month;
};

#endif /* classic_h */
