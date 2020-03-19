/*--------------------customer.cpp-----------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-----------------------------------------------------
Purpose - This is the implementation of the customer.h
file
-----------------------------------------------------
<fstream> and <sstream> is used for reading the file,
and splitting lines.
-----------------------------------------------------*/

#include "customer.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/*----------------------Constructor-----------------------
Description: Constructor

Precondition: None
Postcondition: Constructs the objects.
--------------------------------------------------------*/
Customer::Customer()
{
    size = 0;
}
//End of constructor

/*-----------------------Destructor-------------------------
Description: Constructor

Precondition: None
Postcondition: Constructs the objects.
-----------------------------------------------------------*/
Customer::~Customer()
{
    
}
//End of destructor

/*-------------------------setData---------------------------
Description: This will take the line and split it, initializing
the private variables of the class.

Precondition: The Parameter passed in exists.
Postcondition: Initializes the private variables from the
data from the line.
-----------------------------------------------------------*/
void Customer::setData(string line)
{
    //Split the line.
    istringstream ss(line);
            
    //Take in the id and change it into
    //an integer value
    string sID;
    ss >> sID;
    int identification = stoi(sID);
    
    //Set the private variable to the identification.
    identifier = identification;
            
    //Get the last and first names of the
    //customer.
    string customerLast;
    string customerFirst;
    ss >> customerLast;
    ss >> customerFirst;
            
    //Set the private customerName to the combination of customer first
    //and customer last name.
    customerName = customerLast + " " + customerFirst;
}
//End of setData

/*--------------------getCustomerID-------------------------
Description: Gets CustomerID

Precondition: None
Postcondition: Returns Id of customer
-----------------------------------------------------------*/
int Customer::getCustomerID() const
{
    return identifier;
}
//End of getCustomerID

/*-----------------------getName----------------------------
Description: Gets customer namw

Precondition: None
Postcondition: returns the name of customer
----------------------------------------------------------*/
string Customer::getName() const
{
    return customerName;
}
//End of getName

/*----------------------operator==---------------------------
Description: Checks if this customer and the
other customer being passed in is the same.

Precondition: The Parameter passed in exists
Postcondition: Returns true if they are the same.
-----------------------------------------------------------*/
bool Customer::operator==(const Customer& rhs) const
{
    //If the id and the names are the same...
    if(identifier == rhs.identifier && customerName == rhs.customerName)
    {
        //Check if the array size is the same.
        if(size == rhs.size)
        {
            //If they are the same, check each element and see if they
            //are the same.
            for(int i = 0; i < size; i++)
            {
                //If they are, keep going.
                if(transactionHistory[i] == rhs.transactionHistory[i])
                {
                    continue;
                }
                else
                {
                    //Otherwise, if you find a difference, then they
                    //not the same.
                    return false;
                }
            }
            //If you finish the for loop without having it false, return
            //true, they are the same.
            return true;
        }
        else
        {
            //Otherwise, they are different.
            return false;
        }
    }
    else
    {
        //Strictly here because of the compiler.
        return false;
    }
}
//End of operator ==

/*------------------------operator=---------------------------
Description: Assigns all private variables to the rhs.

Precondition: The Parameter passed in exists
Postcondition: Assigns all private variables to the rhs.
-------------------------------------------------------------*/
void Customer::operator=(const Customer& rhs)
{
    //If they are the same, then don't do anything.
    if(*this == rhs)
    {
        //Do nothing.
    }
    else
    {
        //Initiate every private variable.
        identifier = rhs.identifier;
        customerName = rhs.customerName;
        
        //Size of this transaction history is 0 to "clear" it.
        size = 0;
        
        //Do a deep copy of the transactionHistory array.
        for(int i = 0; i < rhs.size; i++)
        {
            transactionHistory[i] = rhs.transactionHistory[i];
            //Increment the size as you are adding.
            size++;
        }
    }
}
//End of operator =

/*-----------------------operator!=--------------------------
Description: Checks if this customer and the other customer
being passed in is not the same.

Precondition: The Parameter passed in exists
Postcondition: Returns true if they are not the same.
------------------------------------------------------------*/
bool Customer::operator!=(const Customer& rhs) const
{
    //Return the opposite of the ==.
    return !operator==(rhs);
}
//End of operator!=

/*------------------------printHistory------------------------
Description: Prints the history from latest to earliest.

Precondition: None
Postcondition: Prints the history from latest to earliest.
-----------------------------------------------0-------------*/
void Customer::printHistory() const
{
    //If the size is zero,
    if(size == 0)
    {
        //It is empty.
        cout << "History is Empty" << endl;
    }
    else
    {
        //Otherwise, start from size - 1 and decrement until 0.
        for(int i = size - 1; i >= 0; i--)
        {
            cout << transactionHistory[i] << endl;
        }
    }
}
//End of print History

/*------------------------addHistory-------------------------
Description: Adds transaction history to the customer.
 
Precondition: The parameter passed in exists.
Postcondition: Adds transaction history to array
------------------------------------------------------------*/
void Customer::addHistory(string& trans)
{
    //set the passed in value to position of size.
    transactionHistory[size] = trans;
    
    //After you add, increase the size.
    size++;
}
//End of addHistory.

/*------------------------setArray-------------------------
Description: Acts as a method that copies one array to
another.
 
Precondition: The parameter passed in exists.
Postcondition: Copies the passed in array to this array.
------------------------------------------------------------*/
void Customer::setArray(const Customer& rhs)
{
    //"Clear" the array.
    size = 0;
    
    //Copy over the elements
    for(int i = 0; i < rhs.size; i++)
    {
        transactionHistory[i] = rhs.transactionHistory[i];
        
        //As you add, increment the size.
        size++;
    }
}
//End of setArray
