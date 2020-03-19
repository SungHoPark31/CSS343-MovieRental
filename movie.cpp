/*-------------------------movie.cpp-----------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
----------------------------------------------------------------
Purpose - Implements movie.h file but is also an
abstract class
----------------------------------------------------------------*/

#include <iostream>
#include "movie.h"
#include "inventory.h"

using namespace std;

/*-------------------------Movie--------------------------
Description: Constructor that initializes the private
variables.

Precondition: None
Postcondition: Initializes the private variables.
----------------------------------------------------------*/
Movie::Movie()
{
    //Initializes the variables
    title = "";
    director = "";
    year = 0;
    stockNumber = 0;
}
//End of Constructor

/*--------------------------~Movie---------------------------
 Description: Destructor.

 Precondition: None
 Postcondition: Will destroy this object just before the end
 of an object's lifespan.
-------------------------------------------------------------*/
Movie::~Movie()
{
    
}
//End of destructor

/*--------------------------setData-----------------------------
 Description: Pure virtual method that will be
 using polymprphism.

 Precondition: None
 Postcondition: Sets the private variables with the data that is
 from the string line.
---------------------------------------------------------------*/
void Movie::setData(string line)
{
    //Keep this abstract because the child class
    //will take care of it.
}
//End of setData

/*-----------------------display------------------------------
 Description: Pure virtual method that will be using polymprphism.

 Precondition: None
 Postcondition: Displays the data.
--------------------------------------------------------------*/
void Movie::display()
{
    //Displays the Data.
    cout << genre << ", " << stockNumber
    << ", " << title << ", " << director <<
    ", " << year << endl;
}
//End of display

/*-----------------------increase-------------------------------
 Description: "Returns" the movie back to the inventory.

 Precondition: None
 Postcondition: Increases the stock by 1.
--------------------------------------------------------------*/
void Movie::increase(int stock)
{
    //Update the stock number
    stock = stock + 1;
    stockNumber = stock;
}
//End of increase

/*-------------------------decreases------------------------------
 Description: "Borrows" the movie from the inventory.

 Precondition: None
 Postcondition: Decreases the stock by 1.
----------------------------------------------------------------*/
void Movie::decrease(int stock)
{
    //If the stock number is zero, then they cannot
    //borrow anymore.
    if(stock == 0)
    {
        cout << "You cannot borrow anymore of this movie" << endl;
    }
    else
    {
        //Update the stock number
        stock = stock - 1;
        stockNumber = stock;
    }
}
//End of decrease


/*--------------------------operator==-----------------------------
 Description: Compares the Movie objects.

 Precondition: The parameter is an object of Inventory.
 Postcondition: Returns true if the Movie variables are the same
 as the other.
-----------------------------------------------------------------*/
bool Movie::operator==(const Inventory &other) const
{
    //If the year is the same...
    if(year == other.getYear())
    {
        //Check the director...
        if(director == other.getDirector())
        {
            //...Then check the genre...
            if(genre == other.getGenre())
            {
                //...Then check the title
                if(title == other.getTitle())
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

/*---------------------------operator<---------------------------
 Description: Compares the Movie objects.

 Precondition: The parameter is an object of Inventory.
 Postcondition: Returns true if the Movie variables of this object
 is less than the other
----------------------------------------------------------------*/
bool Movie::operator<(const Inventory &other) const
{
    //Check if any of the data is less than the other.
    if(year < other.getYear() || stockNumber < other.getStock()
       || title < other.getTitle() || director < other.getDirector())
    {
        return true;
    }
    else
    {
        return false;
    }
}
//End of operator <

/*----------------------------operator>-------------------------------
 Description: Compares the Movie objects.

 Precondition: The parameter is an object of Inventory.
 Postcondition: Returns true if the Movie variables of this object
 is great than the other
--------------------------------------------------------------------*/
bool Movie::operator>(const Inventory &other) const
{
    //Check if any of the data is less than the other.
    if(year > other.getYear() || stockNumber > other.getStock()
    || title > other.getTitle() || director > other.getDirector())
    {
        return true;
    }
    else
    {
        return false;
    }
}
//End of operator >

/*----------------------------getStock--------------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns stock
---------------------------------------------------------------------*/
int Movie::getStock() const
{
    return stockNumber;
}
//End of getStock

/*-----------------------------getMaxStock-----------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns max stock
---------------------------------------------------------------------*/
int Movie::getMaxStock() const
{
    return maxStock;
}
//end of get Max stock

/*----------------------------getTitle------------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the title
-----------------------------------------------------------------*/
string Movie::getTitle() const
{
    return title;
}
//End of get title

/*--------------------------getGenre------------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns genre
---------------------------------------------------------------*/
string Movie::getGenre() const
{
    return genre;
}
//End of genre

/*------------------------getDirector-------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the director od the movie
---------------------------------------------------------------*/
string Movie::getDirector() const
{
    return director;
}
//End of director

/*------------------------getYear-------------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the year of release
-------------------------------------------------------------*/
int Movie::getYear() const
{
    return year;
}
//End of getYear

/*------------------------getActor----------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the actor of the movie
--------------------------------------------------------------*/
string Movie::getActor() const
{
    return actorName;
}
//End of getActor

/*----------------------getActorLast-------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the actor's last name
----------------------------------------------------------*/
string Movie::getActorLast() const
{
    return actorLastName;
}
//End of getActorLast

/*-------------------------getMonth--------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the month of release
-------------------------------------------------------------*/
int Movie::getMonth() const
{
    return month;
}
//End of getMonth
