/*-----------------------customer.h--------------------------
Sung Ho Park, Makoto Quincy Booth
3/7/2020
-----------------------------------------------------
Purpose - This class is used to get the customer.
It uses the HashTable class to get the ID (key),
and return the customer (value).
-----------------------------------------------------
<vector> was used for the transaction history,.
------------------------------------------------------------*/
#ifndef customer_h
#define customer_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer
{
public:
    //Constructor
    Customer();
    
    //Destructor
    ~Customer();
    
    //setData to initialize
    void setData(string line);
    
    //getCustomerID
    int getCustomerID() const;
    
    //GetCustomer Name
    string getName() const;
    
    //equals operator
    bool operator==(const Customer& rhs) const;
    
    //Assignment operator
    void operator=(const Customer& rhs);
    
    //Not equals
    bool operator!=(const Customer& rhs) const;
    
    //Prints out the vector
    void printHistory() const;
    
    //Push back to the vector.
    void addHistory(string& trans);
    
    //Copies the array.
    void setArray(const Customer& rhs);
    
private:
    //Private variables.
    int identifier;
    string customerName;
    string transactionHistory[101];
    int size = 0;
};

#endif /* customer_h */
