/*-----------------------classic.cpp----------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
----------------------------------------------------------------
Purpose - Implements the classic.h file.
-----------------------------------------------------------------
 Uses <sstream> to split the strings. <vector> was used
 to keep track of the split strings
----------------------------------------------------------------*/

#include "classic.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*-------------------------Classic-----------------------------
Description: Constructor that initializes the private variables.

Precondition: None
Postcondition: Initializes the private variables.
-------------------------------------------------------------*/
Classic::Classic()
{
    genre = "C";
}
//End of Constructor

/*--------------------------~Classic-----------------------------
 Description: Destructor.

 Precondition: None
 Postcondition: Will destroy this object just before the end of
 an object's lifespan.
---------------------------------------------------------------*/
Classic::~Classic()
{

}
//End of destructor

/*----------------------------setData-------------------------------
Description: This will take the line and split it, initializing the
private variables of the class.

Precondition: parameter exists.

Postcondition: Initializes the private variables from the data from
the line.
-----------------------------------------------------------------*/
void Classic::setData(string line)
{
    //Have a temporary vector that will take in separated strings.
    vector<string> splitstrings;
    
    //Split the line by spaces.
    istringstream ss(line);
    
    //While the string is still good...
    while(ss.good())
    {
        //Have a temp string.
        string sub;
        
        //Get the line before the comma, also exluding the comma.
        getline(ss, sub, ',');
        
        //Push it into the vector.
        splitstrings.push_back(sub.substr(1));
    }
    
    //Initialize all the variables.
    int stock = stoi(splitstrings[1]);
    stockNumber = stock;
    director = splitstrings[2];
    title = splitstrings[3];
    
    //This is a special case. Since the last sentence will
    //contain, actor, actorLast, month, year, we have
    //to split again.
    splitAndInitialize(splitstrings[4]);
}
//End of setData

/*---------------------splitAndInitialize---------------------------
Description: This will take the line and split it, initializing the
private variables of the class.

Precondition: parameter exists.

Postcondition: Initializes the private variables from the data from
the line.
-------------------------------------------------------------------*/
void Classic::splitAndInitialize(string split)
{
    //Create a temporary vector
    vector<string> splitline;
    
    //Split it with the spaces.
    istringstream ss(split);
    
    //Initialize.
    ss >> actorName;
    ss >> actorLastName;
    
    //Since the last two is month and year, change
    //the variables to integers.
    string sMonth;
    string sYear;
    
    ss >> sMonth;
    ss >> sYear;
    
    month = stoi(sMonth);
    year = stoi(sYear);
}
//End of split and initialize

/*----------------------------display-------------------------------
 Description: Pure virtual method that will be using polymprphism.

 Precondition: None
 Postcondition: Displays the data.
-----------------------------------------------------------------*/
void Classic::display() const
{
    //Displays the Data.
    cout << genre << ", " << stockNumber
    << ", " << title << ", " << director << ", "
    << actorName << " " << actorLastName << ", "
    << month << ", "<<  year << endl;
}
//End of display

/*---------------------------operator==-----------------------------
 Description: Compares the Comedy objects.

 Precondition: The parameter is an object of Inventory.
 Postcondition: Returns true if the Comedy variables are the same as
 the other.
-------------------------------------------------------------------*/
bool Classic::operator==(const Inventory &other) const
{
    //Checks if all the private instance variables are equal
    //to each other.
    if(genre == other.getGenre())
    {
        if(year == other.getYear())
        {
            if(month == other.getMonth())
            {
                //Check the director...
                if(director == other.getDirector())
                {
                    //...Then check the title
                    if(title == other.getTitle())
                    {
                        return true;
                    }
                }
            }
        }
    }
    //If all else fails, then return false.
    return false;
}
//End of operator ==

/*----------------------------operator<-------------------------------
 Description: Compares the Comedy objects.

 Precondition: The parameter is an object of Inventory.
 Postcondition: Returns true if the Comedy variables of this object
 is less than the other
---------------------------------------------------------------------*/
bool Classic::operator<(const Inventory &other) const
{
    //Check if any of the data is less than the other.
    if(year < other.getYear() || month < other.getMonth() ||
    stockNumber < other.getStock() || title < other.getTitle()
    || director < other.getDirector() || actorName < other.getActor()
    || actorLastName < other.getActorLast())
    {
        return true;
    }
    else
    {
        return false;
    }
}
//End of operartor <

/*----------------------------operator>------------------------------
 Description: Compares the Comedy objects.

 Precondition: The parameter is an object of Inventory.
 Postcondition: Returns true if the Comedy variables of this object
 is great than the other
--------------------------------------------------------------------*/
bool Classic::operator>(const Inventory &other) const
{
    //Check if any of the data is less than the other.
    if(year > other.getYear() || month > other.getMonth() ||
       stockNumber > other.getStock() || title > other.getTitle()
       || director > other.getDirector() || actorName > other.getActor()
       || actorLastName > other.getActorLast())
    {
        return true;
    }
    else
    {
        return false;
    }
}
//End of operator >

/*-----------------------------increase----------------------------------
 Description: "Returns" the movie back to the inventory.

 Precondition: None
 Postcondition: increases the stock by 1.
----------------------------------------------------------------------*/
void Classic::increase(int stock)
{
    //Update the stock number
    stock = stock + 1;
    stockNumber = stock;
}
//End of increase

/*-----------------------------decreases------------------------------
 Description: "Borrows" the movie from the inventory.

 Precondition: None
 Postcondition: Decreases the stock by 1.
---------------------------------------------------------------------*/
void Classic::decrease(int stock)
{
    //If the stock number is zero, then they cannot
    //borrow anymore.
    if(stock == 0)
    {
        cout << "You cannot borrow anymore of this movie" << endl;
    }
    else
    {
        //Update the stock
        stock = stock - 1;
        stockNumber = stock;
    }
}
//End of decrease

/*-----------------------------getStock-----------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns stock
-------------------------------------------------------------------*/
int Classic::getStock() const
{
    return stockNumber;
}
//End of getStock

/*------------------------------getMaxStock--------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns max stock
-------------------------------------------------------------------*/
int Classic::getMaxStock() const
{
    return maxStock;
}
//end of get Max stock

/*------------------------------getTitle-----------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the title
------------------------------------------------------------------*/
string Classic::getTitle() const
{
    return title;
}
//End of get title

/*-------------------------------getGenre-----------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns genre
-------------------------------------------------------------------*/
string Classic::getGenre() const
{
    return genre;
}
//End of genre

/*----------------------------getDirector------------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the director of the movie
------------------------------------------------------------------*/
string Classic::getDirector() const
{
    return director;
}
//End of director

/*-----------------------------getYear-------------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the year of release
--------------------------------------------------------------------*/
int Classic::getYear() const
{
    return year;
}
//End of getYear

/*---------------------------getActor-----------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the actor of the movie
-----------------------------------------------------------------*/
string Classic::getActor() const
{
    return actorName;
}
//End of getActor

/*-------------------------getActorLast---------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the actor's last name
------------------------------------------------------------------*/
string Classic::getActorLast() const
{
    return actorLastName;
}
//End of getActorLast

/*---------------------------getMonth------------------------------
 Description: Gets the private varibales

 Precondition: None
 Postcondition: Returns the month of release
-----------------------------------------------------------------*/
int Classic::getMonth() const
{
    return month;
}
//End of getMonth
