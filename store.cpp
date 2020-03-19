/*----------------------store.cpp---------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-----------------------------------------------------
Purpose - This is the implementation of the store.h
file
-----------------------------------------------------
<sstream> was used for splitting strings and <fstream>
was used to read in the text files.
-----------------------------------------------------*/
#include "store.h"
#include "inventory.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

/*------------------------Store---------------------------
Description: Constructor for store. It will have
access to all the classes.

Precondition: None
Postcondition: Initializes the private variables.
---------------------------------------------------------*/
Store::Store()
{
    //Creates the inventory of movies for the store.
    createInventory();
    
    //Initializes all the customers.
    initializeCustomer();
    
    //Reads the actions and commands and executes.
    readCommands();
}
//End of Constructor

/*-----------------------~Store-----------------------------
Description: Constructor for store. It will have
access to all the classes.

Precondition: None
Postcondition: Initializes the private variables.
-----------------------------------------------------------*/
Store::~Store()
{
    
}
//End of destructor

/*-------------------createInventory-------------------------
Description: Creates the inventory movies by reading
in the movie.txt and creates a Movie object. After that
object is created, it is added to the BinTree.

Precondition: None
Postcondition: After reading the files, the binary
search tree should be filled with Inventory objects. 
-----------------------------------------------------------*/
void Store::createInventory()
{
    //Initialize the string line
    string line;
       
    //Initialize the genre. This will determine what genre the
    //movie will be.
    string genre;
        
    //Read the file.
    ifstream infile("data4movies.txt");
        
    //If there is no file, then send error messages.
    if(!infile)
    {
        cout << "The file cannot be opened" << endl;
    }
    else
    {
        //Otherwise, go through the entire file, until
        //end of file.
        while(!infile.eof())
        {
            //Get the first line, excluding the commas.
            getline(infile, line);
         
            if(line == "")
                break;
            
            //Split the line
            istringstream ss(line);
            
            //Read the genre.
            ss >> genre;
            
            //Check the genre and add it to the BSTree
            if(genre == "C,")
            {
                //If the genre is c, create a classic class.
                Classic* cla1 = new Classic;
                
                //Initialize all the private variables.
                cla1->setData(line);
                
                //Make an inventory class and set it to classic object
                //because the binary search tree takes in Inventory objects.
                Inventory* pointer = cla1;
                
                //Insert it to the binTree.
                inventoryList.insert(pointer);
            }
            else if (genre == "D,")
            {
                //If the genre is D, create a Drama class.
                Drama* d1 = new Drama;
                
                //Initialize all the private variables.
                d1->setData(line);
                
                //Make an inventory class and set it to drama object
                //because the binary search tree takes in Inventory objects.
                Inventory* pointer = d1;
                
                //Insert it to the binTree.
                inventoryList.insert(pointer);
            }
            else if(genre == "F,")
            {
                //If the genre is F, create a comedy class.
                Comedy* c1 = new Comedy;
                
                //Initialize all the private variables.
                c1->setData(line);
                
                //Make an inventory class and set it to drama object
                //because the binary search tree takes in Inventory objects.
                Inventory* pointer = c1;
                
                //Insert it to the binTree.
                inventoryList.insert(pointer);
            }
            else
            {
                //Do nothing
            }
        }
    }
    //After you are done, close the file.
    infile.close();
}
//End of createInventory

/*-------------------initializeCustomer-------------------------
Description: Initializes the customer and places it
in the hash table.

Precondition: None
Postcondition: After reading the files, the hash
table should be filled.
--------------------------------------------------------------*/
void Store::initializeCustomer()
{
    //Initialize the string line
    string line;
        
    //Read the file.
    ifstream infile("data4customers.txt");
        
    //If there is no file, then send error messages.
    if(!infile)
    {
        cout << "The file cannot be opened" << endl;
    }
    else
    {
        //Otherwise, go through the entire file, until
        //end of file.
        while(!infile.eof())
        {
            //Get the first line, excluding the commas.
            getline(infile, line);
         
            //If the line is empty, then break.
            if(line == "")
                break;
            
            //Make a customer and set it.
            Customer person;
            person.setData(line);
            
            //Insert it into the hash using the customerID
            //as a key.
            int id = person.getCustomerID();
            customerList.add(id, person);
        }
    }
    //After you are done, close the file.
    infile.close();
}
//End of initialize Customer.

/*-------------------readCommands-------------------------
Description: Reads in the commands.txt and executes the
commands or actions written in the file.

Precondition: None
Postcondition: Reads in the commands.txt and executes the
commands or actions written in the file.
-----------------------------------------------------------*/
void Store::readCommands()
{
    //Initialize the string line
    string line;
    
    //Initialize the command.
    string command;
    
    //Read the file.
    ifstream infile("data4commands.txt");
        
    //If there is no file, then send error messages.
    if(!infile)
    {
        cout << "The file cannot be opened" << endl;
    }
    else
    {
        
        //Otherwise, go through the entire file, until
        //end of file.
        while(!infile.eof())
        {
            //Get the first line, excluding the commas.
            getline(infile, line);
         
            //If the line is blank, then break
            if(line == "")
                break;
            
            //Split the string
            istringstream ss(line);
            
            //Get the command.
            ss >> command;
            
            //Make a temporary customer
            Customer person;
            
            //Have transaction history ready, this is what will be inserted
            //in the transaction history of the customer.
            string transactionHis;
            
            //Check the command.
            if(command == "B")
            {
                //Read in the ID and change it to an integer.
                string sID;
                ss >> sID;
                int id = stoi(sID);
                
                //Get this customer by accessing the hash table.
                person = customerList.getVal(id);
                
                //Make a Borrow transaction.
                Borrow b(inventoryList);
                
                //Execute the line and update transaction history accordingly.
                b.setStream(line, transactionHis);
                
                //Assign this inventorylist to Borrow objects inventory list
                //because you want to keep updating.
                inventoryList = b.getTree();
                
                //Add transaction history to customer.
                person.addHistory(transactionHis);
                
                //Set the person to the value in the hashtable where the
                //key is.
                customerList.setVal(id, person);
            }
            else if(command == "R")
            {
                //Read in the ID and change it to an integer.
                string sID;
                ss >> sID;
                int id = stoi(sID);
                
                //Get this customer by accessing the hash table.
                person = customerList.getVal(id);
                
                //Make a Return transaction.
                Return r(inventoryList);
                
                //Execute the line and update transaction history accordingly.
                r.setStream(line, transactionHis);
                
                //Assign this inventorylist to Return objects inventory list
                //because you want to keep updating.
                inventoryList = r.getTree();
                
                //Add transaction history to customer.
                person.addHistory(transactionHis);
                
                //Set the person to the value in the hashtable where the
                //key is.
                customerList.setVal(id, person);
            }
            else if(command == "H")
            {
                //Read in the ID and change it to an integer.
                string sID;
                ss >> sID;
                int id = stoi(sID);
                
                //Print out the History by getting the Customer from the
                //hash table.
                cout << "History for " << customerList.getVal(id).getName()
                                                    << " " << id << ":" << endl;
                cout << "-----------------------------------" << endl;
                customerList.getVal(id).printHistory();
                cout << endl;
            }
            else if(command == "I")
            {
                cout << endl;
                //Print out the Binary Tree
                cout << "Inventory: " << endl;
                cout << inventoryList << endl;
            }
            else
            {
                //Do nothing.
                cout << "Invalid Command" << endl;
            }
        }
    }
    //After you are done, close the file.
    infile.close();
}
//End of readCommand
