/*----------------------inventory.cpp-----------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-------------------------------------------------------------
Purpose - Implements the inventory.h file but is abstract
-----------------------------------------------------------*/
#include "inventory.h"
#include <iostream>

using namespace std;

/*-----------------------Inventory--------------------------
 Description: Constructor that initializes the private
 variables.
 
 Precondition: None
 Postcondition: Initializes the private variables.
 ---------------------------------------------------------*/
Inventory::Inventory()
{
    //Initialize all the variables.
    stockNumber = 0;
    maxStock = 0;
    title = "";
    director = "";
    year = 0;
    actorLastName ="";
    actorName = "";
    month = 0;
}
//End of Constructor

/*----------------------~Inventory-------------------------
 Description: Destructor.

 Precondition: None
 Postcondition: Will destroy this object just before the
 end of an object's lifespan.
----------------------------------------------------------*/
Inventory::~Inventory()
{
    
}
//End of Destructor

/*-------------------------setData--------------------------
 Description: Pure virtual method that will be using
 polymprphism.

 Precondition: The parameter exists
 Postcondition: Sets the private variables with the data
 that is from the string line.
---------------------------------------------------------*/
void Inventory::setData(string line)
{
    
}
//End of setData

/*------------------------display----------------------------
 Description: Pure virtual method that will be using
 polymprphism.

 Precondition: None
 Postcondition: Displays the data.
-----------------------------------------------------------*/
void Inventory::display() const
{
    //Displays the Data.
    cout << genre << ", " << stockNumber
    << ", " << title << ", " << director <<
    ", " << year << endl;
}
//End of display

/*-------------------------increase----------------------------
 Description: "Returns" the movie back to the inventory.

 Precondition: The parameter exists.
 Postcondition: increases the stock by 1.
-------------------------------------------------------------*/
void Inventory::increase(int stock)
{
    //Update the stock number
    stock = stock + 1;
    stockNumber = stock;
}
//End of increase

/*---------------------------decreases----------------------------
 Description: "Borrows" the movie from the inventory.

 Precondition: the parameter exists.
 Postcondition: Decreases the stock by 1.
---------------------------------------------------------------*/
void Inventory::decrease(int stock)
{
    //If the stock number is zero, then they cannot
    //borrow anymore.
    if(stock == 0)
    {
        cout << "You cannot borrow anymore of this movie" << endl;
    }
    else
    {
        //Decrease the stock number by 1.
        stock = stock - 1;
        stockNumber = stock;
    }
}
//End of decrease

/*------------------------operator==------------------------------
 Description: Compares the Inventory objects.

 Precondition: The parameter is an object of Inventory.
 Postcondition: Returns true if the Inventory variables are
 the same as the other.
--------------------------------------------------------------*/
bool Inventory::operator==(const Inventory& other) const
{
    //If the year is the same...
    if(year == other.year)
    {
        //Check the director...
        if(director == other.director)
        {
            //...Then check the genre...
            if(genre == other.genre)
            {
                //...Then check the title
                if(title == other.title)
                {
                    return true;
                }
            }
        }
    }
    //If all else fails, then return false.
    return false;
}
//End of operator==

/*----------------------operator<-------------------------
 Description: Compares the Inventory objects.

 Precondition: The parameter is an object of Inventory.
 Postcondition: Returns true if the Inventory variables of
 this object is less than the other
---------------------------------------------------------*/
bool Inventory::operator<(const Inventory& other) const
{
    //Check if any of the data is less than the other.
    if(year < other.year || stockNumber < other.stockNumber
       || title < other.title || director < other.director)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//End of operator<

/*------------------------operator>---------------------------
 Description: Compares the Inventory objects.

 Precondition: The parameter is an object of Inventory.
 Postcondition: Returns true if the Inventory variables of
 this object is great than the other
------------------------------------------------------------*/
bool Inventory::operator>(const Inventory& other) const
{
    //Check if any of the data is less than the other.
    if(year > other.year || stockNumber > other.stockNumber
       || title > other.title || director > other.director)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//End of operator>

/*------------------------getStock-------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns stock
----------------------------------------------------------*/
int Inventory::getStock() const
{
    return stockNumber;
}
//End of getStock

/*-----------------------getMaxStock------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns max stock
------------------------------------------------------------*/
int Inventory::getMaxStock() const
{
    return maxStock;
}
//end of get Max stock

/*--------------------------getTitle----------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the title
-------------------------------------------------------------*/
string Inventory::getTitle() const
{
    return title;
}
//End of get title

/*----------------------------getGenre---------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns genre
-------------------------------------------------------------*/
string Inventory::getGenre() const
{
    return genre;
}
//End of genre

/*------------------------getDirector---------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the director od the movie
---------------------------------------------------------------*/
string Inventory::getDirector() const
{
    return director;
}
//End of director

/*--------------------------getYear----------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the year of release
------------------------------------------------------------*/
int Inventory::getYear() const
{
    return year;
}
//End of getYear

/*-----------------------getActor-----------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the actor of the movie
---------------------------------------------------------------*/
string Inventory::getActor() const
{
    return actorName;
}
//End of getActor

/*-----------------------getActorLast---------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the actor's last name
--------------------------------------------------------------*/
string Inventory::getActorLast() const
{
    return actorLastName;
}
//End of getActorLast

/*----------------------------getMonth----------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the month of release
---------------------------------------------------------------*/
int Inventory::getMonth() const
{
    return month;
}
//End of getMonth

