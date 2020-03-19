/*------------------------comedy.h---------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-------------------------------------------------------------
Purpose - Derived from the Movie class, this will
contain the genre which is read from the Store class.
This is a genre of the Movie class that is contained
in the BSTree.
-----------------------------------------------------------*/

#ifndef comedy_h
#define comedy_h

#include <iostream>
#include <stdio.h>
#include <fstream>
#include "movie.h"
#include "inventory.h"

using namespace std;

class Comedy : public Movie
{
public:
    //Constructor
    Comedy();
    
    //Destructor
    ~Comedy();
    
    //Setdata and display
    virtual void setData(string line);
    virtual void display() const;
    
    //Overriding operators
    virtual bool operator==(const Inventory& other) const;
    virtual bool operator<(const Inventory& other) const;
    virtual bool operator>(const Inventory& other) const;
    //virtual bool operator=(const Inventory& other) const = 0;
    
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
};

#endif /* comedy_h */
