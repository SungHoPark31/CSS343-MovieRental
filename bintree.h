 /*------------------------bintree.h---------------------------
 Sung Ho Park, Makoto Quincy Booth
 1/25/2020
 ---------------------------------------------------------------
 Purpose - This is the bintree header class. Implementation
 is in the cpp file, but this class declares every function
 that'll be implemented in the cpp file and some private
 functions.
 --------------------------------------------------------------
 Had to use <iostream> and <string> for basic necessity.
 cout's and strings. <fstream> is used for txt file io.
 -------------------------------------------------------------*/

#ifndef bintree_h
#define bintree_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "inventory.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

using namespace std;

class BinTree
{
    // you add class method comments and assumptions...
    friend ostream& operator<<(ostream &output, const BinTree &tree);
    
public:
    // constructor
    BinTree();
    
    // copy constructor
    BinTree(const BinTree &);
    
    // destructor, calls makeEmpty
    ~BinTree();
    
    // true if tree is empty, otherwise false
    bool isEmpty() const;
    
    // make the tree empty so isEmpty returns true
    void makeEmpty();
    
    //Operator Overload
    BinTree& operator=(const BinTree &);
    bool operator==(const BinTree &other) const;
    bool operator!=(const BinTree &other) const;
    
    //Insert to the Tree
    bool insert(Inventory* insertNode);
    
    //Transaction.
    void ComedyTransaction(string title, string action, string& transaction);
    
    //Transaction
    void ClassicTransaction(int quantity, int date, string actorF,
                             string action, string &title, string& transaction);
    
    //retrieve title
    void retrieveTitle(bool found, string actorF, int date,
                            string &title, string& transaction);
    
    //Transaction
    void DramaTransaction(string title, string director,
                                    string action, string& transaction);
    
    //Get the height of a specific node.
    int getHeight(const Inventory &root) const;
    
private:
    struct Node
    {
        //Pointer to the data object
        Inventory* data = nullptr;
        
        //Left subtree pointer
        Node* left = nullptr;
        //Right subtree pointer
        Node* right = nullptr;
        
        //Destructor for Node
        ~Node()
        {
            left = nullptr;
            delete left;
            right = nullptr;
            delete right;
            data = nullptr;
            delete data;
        }
    };

    //Root of the tree
    Node* root = nullptr;
    
    //Here are some helper functions for the public functions.
    //The reason why there are a lot of helper functions is
    //because these public functions cannot be solved using
    //recursion. SO, having private helper functions enable
    //the entire program to be solvable recursively.
    
    //Helper function that copies the tree recursively.
    Node* copyHelper( Node* other);
    //void copyHelper(Node* copyRoot, Node *other);
    
    //Helper method to recursively destroy the tree
    void destroy(Node* thisRoot);
    
    //Helper method for insert
    bool insertHelper(Node* thisRoot, Inventory* insertNode);
    
    //Prints in order
    void inOrder(Node* root) const;
    
    //Helper for finding comparison operator. 
    bool equalsHelper(Node* root, Node* other, bool &match) const;
    
    //Helper for comedyTransaction
    void retrieveAndTransactComedy(Node* root, string title,
                                string action, string& transaction);
    
    
    //Helper for classic transaction
    void retrieveAndTransactClassic(Node* root, int quantity,
                                    int date, string actorL,
                                    string action, string &title,
                                    string &transaction);
    
    //Giving alternatives
    void alternative(Node* root, string title, string actorL,
                                    int i, string& transaction);
    
    //Helper for drama Transaction
    void retrieveAndTransactDrama(Node *root, string title,
                                    string director, string action,
                                                string &transaction);
  
    //Gets the title
    void retrieveTitleHelper(Node* root, bool found, string actorF,
                             int date, string &title,
                                        string& transaction);
};

#endif /* nodedata_h */
