/*----------------------return.h---------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-----------------------------------------------------------
Purpose - Derived from the Transaction class, this
will return (+1) a movie from the stock, updating
the inventory.
----------------------------------------------------------*/

#ifndef return_h
#define return_h

#include <stdio.h>
#include "transactions.h"

using namespace std;

class Return : public Transaction
{
public:
    //Constructor
    Return();
    
    //Destructor
    ~Return();
    
    //Overloading Constructor
    Return(const BinTree& tree);
    
    //setStream
    void setStream(string line, string& transaction);
    
    //getTree
    BinTree getTree() const;
    
    //getCustomer
    Customer getCustomer() const;
};

#endif /* return_hpp */
