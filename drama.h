/*---------------------------drama.h----------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
------------------------------------------------------------------
Purpose - Derived from the Movie class, this will
contain the genre which is read from the Store class.
This is a genre of the Movie class that is contained
in the BSTree.
--------------------------------------------------------------*/

#ifndef drama_h
#define drama_h

#include <iostream>
#include <stdio.h>
#include <fstream>
#include "movie.h"
#include "inventory.h"

using namespace std;

class Drama : public Movie
{
public:
    //Constructor
    Drama();
    
    //Destructor
    ~Drama();
    
    //setdata and display
    virtual void setData(string line);
    virtual void display() const;
    
    //Overriding operators
    virtual bool operator==(const Inventory& rhs) const;
    virtual bool operator<(const Inventory& rhs) const;
    virtual bool operator>(const Inventory& rhs) const;
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

#endif /* drama_h */
