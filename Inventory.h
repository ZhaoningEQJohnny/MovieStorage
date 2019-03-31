#pragma once
#include "Transaction.h"
/*

Inventory class (inherit from class Transaction):
-Allows to output all the movie info which was stored in the storage

Assumption:

-Assume it is expected to output all the movie no matter the stock is 0 or not

*/


class Inventory : public Transaction
{
public:
	Inventory();															//Default constructor
	~Inventory();															// Deconstructor
	bool doTransact(HashTable&, BinTree&);									//execute transaction
};																			