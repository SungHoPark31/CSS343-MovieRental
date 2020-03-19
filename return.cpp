/*----------------------return.cpp---------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-------------------------------------------------------------
Purpose - This is the implementation of the borrow.h file
-------------------------------------------------------------
Everything from transactions.h file was used here.
------------------------------------------------------------*/

#include "return.h"

/*------------------------Return-----------------------------
Description: Constructor that initializes the private variables.

Precondition: None
Postcondition: Initializes the private variables.
-----------------------------------------------------------*/
Return::Return()
{
    movie = NULL;
    
}
//End of Constructor

/*------------------Overloading Constructor-------------------
Description: Constructor that initializes the private variables.

Precondition: None
Postcondition: Initializes the private variables.
-------------------------------------------------------------*/
Return::Return(const BinTree& tree)
{
    theTree = tree;
}
//End of Overloading Constructor

/*------------------------~Return------------------------------
Description: Destroys this object

Precondition: None
Postcondition: Destroys the object just before the end of
the object's lifetime.
--------------------------------------------------------------*/
Return::~Return()
{
    
}
//End of Destructor

/*-----------------------setStream--------------------------
Description: Reads in the line and executes the action to
the BSTree of Movies.

Precondition: The objects and variables exist.
Postcondition: Reads in the line and executes the action to
the BSTree of Movies.
------------------------------------------------------------*/
void Return::setStream(string line, string& transaction)
{
    //Split the string
    istringstream ss(line);
       
    //Get the command
    string command;
    ss >> command;
    
    //Get the id
    string sID;
    ss >> sID;
    
    //Get the type. In this case, it is dvd
    string type;
    ss >> type;
    
    //If it is not a DVD, then return invalid.
    if(type != "D")
    {
        //Set the transaction to invalid and print it out.
        transaction = "Invalid Type";
        cout << "Invalid Type" << endl;
        
        //If it is not DVD, then exit the method.
        return;
    }
    
    //Print out who this transaction is for.
    cout << sID << ": ";
    
    //Get the genre.
    string genre;
    ss >> genre;
    
    //This is the string after the genre.
    string movieData = line.substr(11);
    
    //If the genre is comedy
    if(genre == "F")
    {
        //Get the date from the line using substring.
        string dateString = movieData.substr(movieData.size() - 5,
                                                        movieData.size());
        
        //Get the movie information from the line.
        string movieTitle = movieData.substr(0, movieData.size() - 7);
        
        //When reading in the line, we have the information about movie and
        //the date. Use those information to execute the actions needed.
        //There shouldn't be duplicate movies of Comedy.
        theTree.ComedyTransaction(movieTitle, "R", transaction);
    }
    //If the genre is Drama.
    else if(genre == "D")
    {
        //Have a temporary vector that will take
        //in separated strings.
        vector<string> splitstrings;
        
        //Split the line by spaces.
        istringstream ss(movieData);
    
        //While the string is still good...
        while(ss.good())
        {
            //Have a temp string.
            string sub;
            
            //Get the line before the comma, also exluding the comma.
            getline(ss, sub, ',');
            
            //Push it into the vector.
            splitstrings.push_back(sub);
        }
        
        //Get the values and set it to temporary variables.
        string dire = splitstrings[0];
        string title = splitstrings[1].substr(1);
        
        //When reading the line with the genre Drama, we see the the
        //information given to us is the title and the director.
        //Use this information to execute the actions needed and update the
        //transaction. There also shouldn't be duplicates.
        theTree.DramaTransaction(title, dire, "R", transaction);
    }
    //If the genre is Classic.
    else if(genre == "C")
    {
        //Split the movieData
        istringstream ss(movieData);
        
        //Get the quantity and change it to integer.
        string sQuan;
        ss >> sQuan;
        int quantity = stoi(sQuan);
        
        //Get the date from the line and change it to integer.
        string year;
        ss >> year;
        int date = stoi(year);
        
        //Get the actor names from the line.
        string actorFirst;
        ss >> actorFirst;
        string actorLast;
        ss >> actorLast;
        
        //When we are reading the line with the genre Classic, title is not
        //given to us except actor's first and last name, and the date.
        //This means that we use those two information and a boolean value to
        //find the title.
        string title = "";
        bool found = false;
        theTree.retrieveTitle(found, actorLast, date, title, transaction);
        
        //We are finding the titles first because the binary search tree is
        //sorted by titles.

        //Now that we have title, we can execute the actions needed.
        theTree.ClassicTransaction(quantity, date, actorLast, "R", title, transaction);
    }
    else
    {
        //If the genre is not F, D, or C, it is invalid.
        transaction = "Invalid Genre";
        cout << "Invalid Genre" << endl;
    }
}
//End of setStream

/*-------------------------getTree----------------------------
 Description: Returns the BSTree of Movies.

 Precondition: None
 Postcondition: Returns the BSTree of Movies.
------------------------------------------------------------*/
BinTree Return::getTree() const
{
    return theTree;
}
//End of getTree

/*------------------------getCustomer-------------------------
 Description: Returns the customer

 Precondition: None
 Postcondition: Returns the customer.
------------------------------------------------------------*/
Customer Return::getCustomer() const
{
    return p;
}
//End of getCustomer
