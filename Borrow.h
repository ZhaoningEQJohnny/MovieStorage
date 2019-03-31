#pragma once
#include "Transaction.h"
/*
 
Borrow class (inherit from class Transaction): 
-allows customer borrow the movie if movie is not out of stock
	-Conditions
		-Movie has to be found in the storage
		-Movie stock must bigger than 0
		-Customer must exist
		-Media type must be valid (Has to be 'D' as DVD type)
Assumption:
-Assume there is only one media type :D

*/


class Borrow : public Transaction
{
public:
	Borrow();																		//Default constructor
	Borrow(Customer& cust, Movie& movie, char mediaType, char trType);				//Constructor with parameter
	~Borrow();																		// Deconstructor
	bool doTransact(HashTable&, BinTree&);											//execute transaction
};