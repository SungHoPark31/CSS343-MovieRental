 /*--------------------------bintree.cpp---------------------------
 Sung Ho Park, Makoto Quincy Booth
 1/25/2020
 2/1/2020
 -----------------------------------------------------------------
 Purpose - This is the bintree class. This file creates the
 binary search tree and inserts data from the nodeData class.
 It also retrieves objects from the nodeData, and prints the data
 in order/
 ------------------------------------------------------------------
 Had to use <iostream> and <string> for basic necessity.
 cout's and strings. <assert.h> for debug.
 <vector> is used to create an array.
 -----------------------------------------------------------------*/

#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <cmath>
#include <vector>
#include "bintree.h"

using namespace std;

/*-------------------------BinTree---------------------------------
 Description:
 Default Constructor that creates an empty tree.
 
 Precondition: None
 Postcondition: Creates an empty tree
 -----------------------------------------------------------------*/
BinTree::BinTree()
{
    //Create an empty tree. Everything inside of
    //root is initialized to null.
    root = new Node();
}
//End of default constructor

/*------------------Copy constructor---------------------------
 Description:
 Copy Constructor that copies another tree with this one.

 Precondition: The parameter that is passed in is an existing
 object.
 Postcondition: Performs a deep copy of the other tree to
 this tree.
-------------------------------------------------------------*/
BinTree::BinTree(const BinTree &other)
{
    //Copy everything over to this tree.
    root = copyHelper(other.root);
}
//End of Copy constructor

/*---------------------------Destructor---------------------------
 Description:
 Destroys the tree.

 Precondition: None
 Postcondition: Destroys all nodes in the tree and the tree.
-----------------------------------------------------------------*/
BinTree::~BinTree()
{
    //call destroy to completely destroy all the root.
    destroy(root);
    delete root;
}
//End of Destructor

/*-----------------------------isEmpty-----------------------------
 Description:
 Checks if the tree is empty

 Precondition: None
 Postcondition: Returns true if the tree is empty, false
 if not.
------------------------------------------------------------------*/
bool BinTree::isEmpty() const
{
    //If the root is null, then it is empty.
    if(root->data == nullptr)
    {
        return true;
    }
    else
    {
        //Otherwise, it is not, so it is false
        return false;
    }
}
//End of isEmpty

/*------------------------------makeEmpty-------------------------------
 Description:
 Makes the tree empty.

 Precondition: None
 Postcondition: Destroys all nodes in the tree and the tree.
 Helper for the destructor. 
----------------------------------------------------------------------*/
void BinTree::makeEmpty()
{
    //Destroy everything but the root.
    destroy(root);
    
    //Since it is completely destroyed, make a new root
    //and set it to null to make it empty.
    root->left = nullptr;
    root->right = nullptr;
    root->data = nullptr;
}
//End of makeEmpty

/*----------------------------destroy-----------------------------
 Description:
 Destroys the tree.

 Precondition: The Node that is being passed in exists.
 Postcondition: Destroys all nodes in the tree and the tree.
 Helper for the destructor and make Empty.
------------------------------------------------------------------*/
void BinTree::destroy(Node* thisRoot)
{
    //If thisRoot is not nullptr.
    if(thisRoot)
    {
        //Go left and right
        destroy(thisRoot->left);
        destroy(thisRoot->right);
        
        //delete the root
        if(thisRoot != root)
        {
            delete thisRoot;
        }
    }
    else
    {
        //If the root is a nullptr, then exit.
        return;
    }
}
//End of destroy

/*----------------------------operator=---------------------------
 Description:
 Basically a Copy Constructor that copies another tree
 with this one. Except that it uses the assignment operator

 Precondition: The parameter that is passed in is an existing
 object.
 Postcondition: Performs a deep copy of the other tree to
 this tree.
------------------------------------------------------------------*/
BinTree& BinTree::operator=(const BinTree &other)
{
    //If the other is null, then make this null.
    if(other.root == nullptr)
    {
        root = nullptr;
    }
    //If the trees are the same, then don't really do anything
    //Just return this.
    else if(this == &other)
    {
        return *this;
    }
    else
    {
        //Empty the tree down to one root.
        makeEmpty();
        //Perform the deep copy recursively.
        root = copyHelper( other.root);
    }
    //Return this.
    return *this;
}
//End of operator=

/*---------------------------copyHelper---------------------------
 Description:
 Basically a Copy Constructor that copies another tree
 with this one. This is a helper method that copies the tree
 recursively.

 Precondition: The both parameter that is passed in is an existing
 object. Node and BinTree
 Postcondition: Performs a deep copy of the other tree to
 this tree.
------------------------------------------------------------------*/
BinTree::Node* BinTree::copyHelper( Node *other)
{
    //This will return the copy of the root, therefore returning the
    //tree. Create a temp variable.
    Node *copyRoot = nullptr;
    //Base case: If the other is eventually null, make this root
    //null.
    if(other == nullptr)
    {
        //make the copyRoot null
        copyRoot = nullptr;
    }
    else //if(copyRoot == nullptr)
    {
        copyRoot = new Node();
        copyRoot->data = other->data;
        
        //Go left and right and keep copying.
        copyRoot->left = copyHelper(other->left);
        copyRoot->right = copyHelper(other->right);
    }
    return copyRoot;
}
//End of copyHelper

/*---------------------------operator==-----------------------------
 Description:
 Checks if one tree is the same as another.

 Precondition: The parameter that is passed in is an existing
 object.
 Postcondition: Returns true if the two trees are the same.
 False otherwise.
-------------------------------------------------------------------*/
bool BinTree::operator==(const BinTree &other) const
{
    //Have a boolean to keep track of the tree. If it is false
    //anywhere, it'll return false.
    bool match = false;
    return equalsHelper(root, other.root, match);
}
//End of == operator

/*-------------------------equalsHelper---------------------------
 Description:
 Checks if one tree is the same as another. This is a helper
 for both the == and the !=. For the == operator, anytime
 where the tree differs in anyway, returns false.

 Precondition: The parameter that is passed in is an existing
 object.
 Postcondition: Returns true if the two trees are the same.
 False otherwise.
--------------------------------------------------------------------*/
bool BinTree::equalsHelper(Node* root, Node* other, bool &match) const
{
    //If both of them are empty, then return true.
    if(root == nullptr && other == nullptr)
    {
        match = true;
    }
    //If one of the roots is a nullptr, still return true because
    //we went through the tree.
    else if(root == nullptr && other != nullptr)
    {
        match = true;
    }
    else if(root != nullptr && other == nullptr)
    {
        match = true;
    }
    else
    {
        //If it is equal, then keep going.
        if(*root->data == *other->data)
        {
            equalsHelper(root->left, root->left, match);
            equalsHelper(root->right, root->right, match);
        }
        else
        {
            //If it is not, then just stop everything.
            match = false;
        }
    }
    //Return the result. If it manages to go through the
    //entire test, then it is a successful operator==.
    //If not, then it'll return false.
    return match;
}
//end of equalsHelper

/*----------------------------operator!=-------------------------------
 Description:
 Checks if one tree is not the same as another.

 Precondition: The parameter that is passed in is an existing
 object.
 Postcondition: Returns true if the two trees are not the same.
 False otherwise.
-----------------------------------------------------------------------*/
bool BinTree::operator!=(const BinTree &other) const
{
    //If they are the same, then return false.
    bool match = false;
    if(equalsHelper(root, other.root, match) == true)
    {
        return false;
    }
    else
    {
        //If there is one problem with the equals helper, then
        //it is not equal, therefore return true.
        return true;
    }
}
//End of != operator

/*------------------------------insert------------------------------------
 Description:
 Insert the node into the tree.

 Precondition: There is a node object.
 Postcondition: Returns true if insert is successful. False if not.
-----------------------------------------------------------------------*/
bool BinTree::insert(Inventory* insertNode)
{
    //Call the helper function.
    return insertHelper(root, insertNode);
}
//End of insert

/*----------------------------insertHelper-----------------------------
 Description:
 Insert the node into the tree. Helper function inserts to the
 tree recursively.

 Precondition: There is an existing object for Node and Nodedata.
 Postcondition: Returns true if insert is successful. False if not.
----------------------------------------------------------------------*/
bool BinTree::insertHelper(Node* thisRoot, Inventory* insertNode)
{
    //If the root is null, or it is an empty tree,
    //insert it.
    if(thisRoot->data == nullptr)
    {
        //Set the datas
        thisRoot->data = insertNode;
        thisRoot->left = nullptr;
        thisRoot->right = nullptr;
        
        //This is a successful insert.
        return true;
    }
    else if(thisRoot->data->getTitle() == insertNode->getTitle())
    {
        //If they are the same, then add it to the inventory.
        
        //Make a new Node
        Node* newNode = new Node;
        
        //If the right is null, then add it there.
        if(thisRoot->right == nullptr)
        {
            thisRoot->right = newNode;
            newNode->data = insertNode;
            return true;
        }
        else
        {
            //If it is not null and there is something in between,
            //Add the duplicate inbetween.
            Node *temp = new Node;
            temp = thisRoot->right;
            newNode->data = insertNode;
            thisRoot->right = newNode;
            newNode->right = temp;
            return true;
        }
        return false;
    }
    //If the data root is greater than the insertNode, go left.
    //Dereference because you don't want to compare their references.
    else if(thisRoot->data->getTitle() > insertNode->getTitle())
    {
        //If the left is nullptr...
        if(thisRoot->left == nullptr)
        {
            //Make a new Node
            Node* newNode = new Node;
            
            //Set that new Node to the left
            thisRoot->left = newNode;
            
            //Go left
            return insertHelper(thisRoot->left, insertNode);
        }
        else
        {
            //Go left
            return insertHelper(thisRoot->left, insertNode);
        }
    }
    //Otherwise, go right.
    else if(thisRoot->data->getTitle() < insertNode->getTitle())
    {
        //If the right is nullptr...
        if(thisRoot->right == nullptr)
        {
            //Make a new Node
            Node* newNode = new Node;
            
            //Set that new Node to the right
            thisRoot->right = newNode;
            
            //Go right
            return insertHelper(thisRoot->right, insertNode);
        }
        else
        {
            //Go right
            return insertHelper(thisRoot->right, insertNode);
        }
    }
    return false;
}
//End of insertHelper.

/*--------------------------printInOrder----------------------------
 Description:
 Prints all the nodes in the tree in order.

 Precondition: There is an existing node object.
 Postcondition: Prints all the nodes in the tree in order.
-------------------------------------------------------------------*/
void BinTree::inOrder(Node* root) const
{
    //If the root is nullptr, then just return
    if (root == nullptr)
    {
        return;
    }
    
    //In order: left, root, right
    inOrder(root->left);
    root->data->display();
    inOrder(root->right);
}
//End of printInOrder.

ostream& operator<<(ostream &out, const BinTree &tree)
{
    BinTree::Node* root = tree.root;
    tree.inOrder(root);
    return out;
}

/*---------------------------ComedyTransaction-------------------------
 Description:
 Performs the Transaction on Comedy.

 Precondition: The variables exist.
 Postcondition: Performs the Transaction on Comedy.
---------------------------------------------------------------------*/
void BinTree::ComedyTransaction(string title, string action,
                                                    string& transaction)
{
    //Call the helper function.
    retrieveAndTransactComedy(root, title, action, transaction);
}
//End of ComedyTransaction

/*------------------------retrieveAndTransactComedy-----------------------
 Description:
 Helper function that performs the Transaction on Comedy.

 Precondition: The variables exist.
 Postcondition: Performs the Transaction on Comedy.
-------------------------------------------------------------------------*/
void BinTree::retrieveAndTransactComedy(Node* root, string title,
                                        string action, string& transaction)
{
    //Base Case: If the root is null...
    if(root == nullptr)
    {
        //Return false. Or if it is not found.
        cout << "Cannot Find this movie " << title << endl;
        transaction = title + " is not in the store.";
        return;
    }
    //If the data is found...
    else if(root->data->getTitle() == title)
    {
        //If the action is borrow...
        if(action == "B")
        {
            //check the movie's stock.
            //If the stock of this movie is 0, then it fails.
            if(root->data->getStock() == 0)
            {
                //Update transaction
                transaction = "Failed because stock for " + title  +
                                                            " is empty.";
                
                //Display that the action failed.
                cout << "Cannot Borrow " << title <<
                                        "because it is out of stock." << endl;
            }
            //Otherwise, you can perform the action.
            else
            {
                //Borrow and update the transaction
                root->data->decrease(root->data->getStock());
                cout << "Borrowed " << root->data->getTitle() << endl;
                transaction = "Borrowed: " + title;
            }
        }
        else if(action == "R")
        {
            //If the action is R, then return the stock and update
            //the transaction.
            root->data->increase(root->data->getStock());
            cout << "Returned " << root->data->getTitle() << endl;
            transaction = "Returned: " + title;
        }
        else
        {
            cout << "Invalid action" << endl;
        }
        return;
    }
    //If the the data is greater than the value passed in
    else if(root->data->getTitle() > title)
    {
        //Go left
        retrieveAndTransactComedy(root->left, title, action, transaction);
    }
    //If the the data is less than the value passed in,
    else if(root->data->getTitle() < title)
    {
        //Go right
        retrieveAndTransactComedy(root->right, title, action, transaction);
    }
    //Rare case, but needed if not found.
}
//End of retrieveAndTransactComedy

/*------------------------ClassicTransaction-----------------------------
 Description:
 Performs the Transaction on Classic.

 Precondition: The variables exist.
 Postcondition: Performs the Transaction on Classic.
-----------------------------------------------------------------------*/
void BinTree::ClassicTransaction(int quantity, int date,
                                        string actorL, string action,
                                        string &title, string& transaction)
{
    //Call the helper method
    retrieveAndTransactClassic(root, quantity, date,
                               actorL, action, title, transaction);
}
//End of ClassicTransaction

/*---------------------retrieveAndTransactClassic-------------------------
 Description:
 Helper function that performs the Transaction on Classic.

 Precondition: The variables exist.
 Postcondition: Performs the Transaction on Classic.
------------------------------------------------------------------------*/
void BinTree::retrieveAndTransactClassic(Node* root, int quantity, int date,
                                         string actorL, string action,
                                         string &title, string &transaction)
{
    //Base Case: If the root is null...
    if(root == nullptr)
    {
        //Return false. Or if it is not found.
        cout << "Cannot Find this movie with " << actorL
                                        << " " << date << endl;
        
        //Update the string.
        transaction = title + " is not in the store.";
        return;
    }
    //If the data is found...
    else if(root->data->getTitle() == title)
    {
        //If the action is B
        if(action == "B")
        {
            bool contained = true;
            //Because the line has qunatity, it is going to borrow the
            //movie quantity amount of times.
            for(int i = 0; i < quantity; i++)
            {
                if(root->data->getStock() == 0)
                {
                    //If the stock is 0, then you can't borrow.
                    cout << title << " with " << actorL <<
                    " cannot be borrowed anymore" << endl;
                    
                    //Since this is classic, and there are multiple movies,
                    //but with different major actors, find the same movie
                    //with a different actor and stock is not 0.
                    alternative(root, root->data->getTitle(), actorL,
                                                        i, transaction);
                    
                    //This is here so that if you found the movie.
                    contained = false;
                    break;
                }
                else
                {
                    //If the stock is not 0, then borrow it.
                    root->data->decrease(root->data->getStock());
                }
            }
            //If you made it without having contained to be false.
            if(contained == true)
            {
                //Print out borrowed
                cout << "Borrowed " << root->data->getTitle() << " with "
                        << quantity << " Times"  << endl;
                
                //Change the quantity to a string and update transaction.
                string sQuan = to_string(quantity);
                transaction = "Borrowed " + sQuan + " copies of " + title
                                 + " with " + root->data->getActor()
                                                        + " " + actorL;
            }
        }
        //If the action is R
        else if(action == "R")
        {
            //Because the line has qunatity, it is going to return the
            //movie quantity amount of times.
            for(int i = 0; i < quantity; i++)
            {
                root->data->increase(root->data->getStock());
            }
            
            //Change the quantity to a string and update the transaction.
            string sQuan = to_string(quantity);
            transaction = "Returned " + sQuan + " copies of " + title
                             + " with " + root->data->getActor() + " "
                                                                + actorL;
        }
        else
        {
            //Otherwise, it is invalid.
            cout << "Invalid action" << endl;
        }
    }
    //If the the data is greater than the value passed in
    else if(root->data->getTitle() > title)
    {
        //Go left
        retrieveAndTransactClassic(root->left, quantity, date,
                                actorL, action, title, transaction);
    }
    //If the the data is less than the value passed in,
    else if(root->data->getTitle() < title)
    {
        //Go right
        retrieveAndTransactClassic(root->right, quantity, date,
                                actorL, action, title, transaction);
    }
    //Rare case, but needed if not found.
}
//End of retrieveAndTransactClassic

/*------------------------DramaTransaction----------------------------
 Description:
 Performs the Transaction on Drama.

 Precondition: The variables exist.
 Postcondition: Performs the Transaction on Drama.
----------------------------------------------------------------------*/
void BinTree::DramaTransaction(string title, string director,
                                    string action, string& transaction)
{
    //Call the helper function.
    retrieveAndTransactDrama(root, title, director, action, transaction);
}
//end of DramaTransaction

/*----------------------retrieveAndTransactDrama------------------------
 Description:
 Helper function that performs the Transaction on Drama.

 Precondition: The variables exist.
 Postcondition: Performs the Transaction on Drama.
----------------------------------------------------------------------*/
void BinTree::retrieveAndTransactDrama(Node *root, string title,
                                       string director, string action,
                                       string& transaction)
{
    //Base Case: If the root is null...
       if(root == nullptr)
       {
           //Return false. Or if it is not found.
           cout << "Cannot Find this movie " << title << " " <<
                                                        director << endl;
           
           //Update the transaction
           transaction = title + " is not in the store.";
           return;
       }
       //If the data is found...
       else if(root->data->getTitle() == title &&
                            root->data->getDirector() == director)
       {
           //If the action is B
           if(action == "B")
           {
               //Check if the stock is zero. If it is not, then continue.
               if(root->data->getStock() == 0)
               {
                   //If the stock is zero, then print out that they cannot
                   //borrow it.
                   cout << "Cannot Borrow " << title <<
                                    "because it is out of stock." << endl;
                   
                   //Update the transaction.
                   transaction = "Cannot Borrow " + title +
                                            "because it is out of stock";
               }
               else
               {
                   //If the stock is not zero, then execute.
                   root->data->decrease(root->data->getStock());
                   cout << "Borrowed " << root->data->getTitle() << endl;
                   
                   //Update the transaction.
                   transaction = "Borrowed: " + title +
                                            " directed by " + director;
               }
           }
           //If the action is R
           else if(action == "R")
           {
               //Execute the action.
               root->data->increase(root->data->getStock());
               cout << "Returned " << root->data->getTitle() << endl;
               
               //Update transaction
               transaction = "Returned: " + title +
                                        "directed by " + director;
           }
           else
           {
               //Otherwise, it is invalid.
               cout << "Invalid action" << endl;
           }
           return;
       }
       //If the the data is greater than the value passed in
       else if(root->data->getTitle() > title)
       {
           //Go left
           retrieveAndTransactDrama(root->left, title, director,
                                                action, transaction);
       }
       //If the the data is less than the value passed in,
       else if(root->data->getTitle() < title)
       {
           //Go right
           retrieveAndTransactDrama(root->right, title, director,
                                                action, transaction);
       }
       //Rare case, but needed if not found.
}
//End of retrieveAndTransactDrama

/*---------------------------alternative---------------------------
 Description: This is mostly for classic. Finds an alternative movie
 with the same title but different major actors and it
 makes sure that the stock is not 0.

 Precondition: The variables exist.
 Postcondition: Borrows from an alternative movie. If it doesn't,
 then there is no other movie in the store with the same title and
 stock is not 0.
------------------------------------------------------------------*/
void BinTree::alternative(Node* root, string title, string actorL,
                                        int i, string &transaction)
{
    //If the root is null.
    if(root == nullptr)
    {
        //Movie is not there.
        cout << "Cannot Find This Movie Anywhere Else in the Store: "
                                                        << title << endl;
        
        //Update transaction
        transaction = "Cannot find " + title +
                        " anywhere in the store or stock is empty";
        
        return;
    }
    //If the title is equal and the stock is the not 0 and it is
    //a different major actor, then execute.
    else if(root->data->getTitle() == title &&
            root->data->getStock() != 0 &&
            root->data->getActorLast() != actorL)
    {
        //Execute i times for the alternative. It is the same movie, just
        //different actor.
        for(int j = 0; j < i; j++)
        {
            //If the stock is 0, then call alternative again.
            if(root->data->getStock() == 0)
            {
                //If you cannot find it, break.
                break;
            }
            //Other wise, decrease it...
            root->data->decrease(root->data->getStock());
        }
        //If the stock is not 0
        if(root->data->getStock() != 0)
        {
            //...and display action.
            cout << "Borrowed " << title << " " << i << " times." << endl;
            
            //Change the quantity to string
            string it = to_string(i);
            
            //Update transaction
            transaction = "Borrowed " + it + "copies of " + title +
                        " with " + root->data->getActor() + " " +  actorL;
        }
        else
        {
            //Call alternative.
            alternative(root->right, title, actorL, i, transaction);
            cout << "Cannot borrow this movie. " << endl;
            
            //Update the transaction.
            transaction = "Cannot borrow " + title;
        }
    }
    //If any other case happens, then recurse right.
    else if((root->data->getTitle() == title &&
             root->data->getStock() == 0)||
            (root->data->getTitle() != title) ||
            root->data->getActorLast() == actorL)
    {
        //Recurse right because duplicates are on the right side.
        alternative(root->right, title, actorL, i, transaction);
    }
    else
    {
        //Just in case, return.
        return;
    }
}
//End of alternative

/*--------------------------retrieveTitle-------------------------
 Description:
 Since we do not have access to title in Classic command,
 we need to find it.

 Precondition: The variables exist.
 Postcondition: Finds the title and sets it to the parameter
 title.
------------------------------------------------------------------*/
void BinTree::retrieveTitle(bool found, string actorF, int date,
                            string& title, string& transaction)
{
    //Call Helper.
    retrieveTitleHelper(root, found, actorF, date, title, transaction);
}

/*--------------------------retrieveTitle---------------------------
 Description:
 Since we do not have access to title in Classic command,
 we need to find it. Helper method.

 Precondition: The variables exist.
 Postcondition: Finds the title and sets it to the parameter
 title.
-------------------------------------------------------------------*/
void BinTree::retrieveTitleHelper(Node* root, bool found,
                                  string actorF, int date,
                                  string &title, string &transaction)
{
    //If root is null...
    if(root == nullptr)
    {
        //Do Nothing
        transaction = title + "is not in the store";
        return;
    }
    //If you have year and last name identical to the other, then
    //you found the title.
    else if(root->data->getActorLast() == actorF &&
                                    root->data->getYear() == date)
    {
        //Change this to true because you found it.
        found = true;
        
        //Set the title.
        title = root->data->getTitle();
        return;
    }
    //If you don't find it, then recurse both left and right.
    else if(found == false)
    {
        retrieveTitleHelper(root->left, found, actorF, date, title, transaction);
        retrieveTitleHelper(root->right, found, actorF, date, title, transaction);
    }
}
