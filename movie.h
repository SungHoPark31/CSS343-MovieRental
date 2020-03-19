/*--------------------------movie.h-------------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-----------------------------------------------------------------
Purpose - Abstract Class. This class contains
protected information about each movie such as stock,
title, director, and year. This is a parent class.
-----------------------------------------------------------------*/
#ifndef movie_h
#define movie_h

#include <iostream>
#include <stdio.h>
#include <fstream>
#include "inventory.h"
#include "movie.h"

using namespace std;

class Movie : public Inventory
{
public:
    //Constructor
    Movie();
    
    //Destructor
    virtual ~Movie();
    
    //Display
    virtual void display();
    
    //Overriding operators
    virtual bool operator==(const Inventory &other) const = 0;
    virtual bool operator<(const Inventory &other) const = 0;
    virtual bool operator>(const Inventory &other) const = 0;
    //virtual bool operator=(const Inventory& other) const = 0;
    
    //SetData
    virtual void setData(string line);
    
    //Increase and decrease the stock
    virtual void increase(int stock) = 0;
    virtual void decrease(int stock) = 0;
    
    //Getters needed.
    virtual int getStock() const = 0;
    virtual int getMaxStock() const = 0;
    virtual string getTitle() const = 0;
    virtual string getGenre() const = 0;
    virtual string getDirector() const = 0;
    virtual int getYear() const = 0;
    virtual string getActor() const = 0;
    virtual string getActorLast() const = 0;
    virtual int getMonth() const = 0;
    
protected:
    string title;
    string director;
    int year;
    int stockNumber;
};

#endif /* movie_h */
