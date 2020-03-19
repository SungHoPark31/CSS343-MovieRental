/*----------------------store.h-----------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-----------------------------------------------------
Purpose - The store will read the file and create
customer array, transactions vector, and inventory
BSTree.
-----------------------------------------------------
<sstream> was used to split strings.
-----------------------------------------------------*/
#ifndef store_h
#define store_h

#include "inventory.h"
#include "movie.h"
#include "customer.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include "transactions.h"
#include "borrow.h"
#include "return.h"
#include "bintree.h"
#include "hashTable.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Store
{
public:
    //Constructor
    Store();
    
    //Destructor
    ~Store();
    
    //Creating inventory
    void createInventory();
    
    //Initializes the customer and puts it in the hash
    void initializeCustomer();
    
    //Execute the commands.
    void readCommands();

private:
    //Hash table for customerList.
    HashTable<int, Customer> customerList;
    
    //InventoryList.
    BinTree inventoryList;
};

#endif /* store_h */
