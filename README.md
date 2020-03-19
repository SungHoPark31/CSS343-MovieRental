# CSS343-MovieRental
Uses Inheritance, Binary Search Tree, and Hash Tables to 
implement a movie rental store.

A local movie rental store wishes to automate their inventory tracking system. 
Currently there are three types of movies/videos (in DVD media) to be tracked:
- Comedy (denoted as ‘F’ for funny)
- Drama (denoted as ‘D’)
- Classics (denoted as ‘C’)

Borrows and returns of items by customers are also to be tracked. 
Four types of actions are desired in the system:
- Borrow (denoted as ‘B’): (stock – 1) for each item borrowed
- Return (denoted as ‘R’): (stock + 1) for each item returned
- Inventory (denoted as ‘I’): outputs the inventory of all the items in the store
- History (denoted as ‘H’): outputs all the transactions of a customer

You will design and implement a program that will initialize the
contents of the inventory from a file (data4movies.txt), the customer
list from another file (data4customers.txt), and then process an 
arbitrary sequence of commands from a third file (data4commands.txt).

In data4movies.txt, the information about each movie is listed as follows:
- For comedy movies: F, Stock, Director, Title, Year it released
- For drama movies: D, Stock, Director, Title, Year it released
- For classics movies: C, Stock, Director, Title, Major actor Release date

For example,
F, 10, Nora Ephron, You've Got Mail, 1998
D, 10, Steven Spielberg, Schindler's List, 1993 
C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938 
C, 10, George Cukor, Holiday, Cary Grant 9 1938 
Z, 10, Hal Ashby, Harold and Maude, Ruth Gordon 2 1971
D, 10, Phillippe De Broca, King of Hearts, 1967

Important notes about data4movies.txt:
- You may assume correct formatting, but codes may be invalid; e.g.,
in this data, the 'Z' code is an invalid entry so this line has 
to be discarded and users should be notified about this issue.

- While the stock for each line is 10, do not assume that is the 
case in your design and implementation.

- The classical movie type has a different format than the other two. 
It contains Major actor which is always formatted as two strings, 
first name and last name, separated by a space. Then the Release 
date contains month and year information, and no comma (but a space) 
between Major actor and Release date. In addition, for classical 
movies, one movie (e.g., Holiday) may have multiple lines so the 
total stock of this movie will be the sum of all the stocks in the
lines about this movie (e.g., 20 for Holiday in the above example).
