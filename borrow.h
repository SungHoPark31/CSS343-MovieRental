/*----------------------borrow.h---------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-----------------------------------------------------------
Purpose - Derived from the Transaction class, this
will take out (-1)  a movie from the stock, updating
the inventory.
-----------------------------------------------------------*/

#ifndef borrow_h
#define borrow_h

#include <iostream>
#include "transactions.h"
#include <stdio.h>
#include <string>

using namespace std;

class Borrow : public Transaction
{
public:
    //Constructor
    Borrow();
    
    //Destructor
    ~Borrow();
    
    //Overloading constructor
    Borrow(const BinTree& tree);
    
    //setStream
    void setStream(string line, string& transaction);
    
    //getTree
    BinTree getTree() const;
    
    //getCustomer
    Customer getCustomer() const;
    
};

#endif /* borrow_h */
