/*--------------------transaction.h---------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
---------------------------------------------------------------
Purpose - This class will contain the different transactions that
the customer desires. The commands were read from the store class
and are being used in the transaction vector. Each element in the
vector contains the Transaction class. This is also an abstract
parent class.
----------------------------------------------------------------
<fstream> and <sstream> is used for reading the file,
and splitting lines.
--------------------------------------------------------------*/
#ifndef transactions_h
#define transactions_h

#include <iostream>
#include "inventory.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "customer.h"
#include "bintree.h"
#include <stdio.h>
#include <sstream>
#include <fstream>

using namespace std;

class Transaction
{
public:
    //Constructor
    Transaction();
    
    //Overloading Constructor
    Transaction(const BinTree& tree, const Customer& person);
    
    //Virtual Destructor
    virtual ~Transaction();
    
    //Virtual setStream
    virtual void setStream(string line, string& transaction, bool& found);
    
    //Pure Virtual getTree
    virtual BinTree getTree() const = 0;
    
    //Pure virtual getCustomer
    virtual Customer getCustomer() const = 0;

protected:
    //Protected variables needed for child class.
    Inventory* movie;
    Customer p;
    BinTree theTree;
};
#endif /* transactions_h */
