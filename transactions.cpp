/*-----------------transactions.cpp--------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-----------------------------------------------------
Purpose - This an abstract class of transaction. Nothing
needs to be implemented because the child class will
take care of it.
-------------------------------------------------------*/

#include "transactions.h"

Transaction::Transaction()
{
    
}

Transaction::Transaction(const BinTree& tree, const Customer& person)
{

}

Transaction::~Transaction()
{
    
}


void Transaction::setStream(string line, string &transaction, bool &found)
{

}

BinTree Transaction::getTree() const
{
    return theTree;
}
