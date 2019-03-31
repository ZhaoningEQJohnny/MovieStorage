#pragma once
#include "Transaction.h"


/*

Return class (inherit from class Transaction):
-allows customer return the movie if movie has borrowed before
	-Conditions
		-Movie has to be found in the storage
		-Movie stock must be borrowed before
		-Customer must exist
		-Media type must be valid (Has to be 'D' as DVD type)
Assumption:
-Assume there is only one media type :D

*/


class Return : public Transaction
{
public:
	Return();																	//Default constructor
	Return(Customer& cust, Movie& movie, char mediaType, char trType);   		//Constructor with parameter
	~Return();																	// Deconstructor
																				
	bool doTransact(HashTable&, BinTree&);										//execute transaction
};