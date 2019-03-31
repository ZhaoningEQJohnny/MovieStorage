#pragma once
#include "Transaction.h"
#include "Customer.h"

/*

History class (inherit from class Transaction):
-Show all the transaction from the specific customer in chronological  order
-The output also contain the transaction occured date&time, 
 since the program execute at the same time, it can only be distinguish when you use debug to process the B/R command


Conditions:
-Customer must exist

*/


class History : public Transaction
{
public:
	History();																//Default constructor
	History(Customer& cust);												//Constructor with parameter
	~History();																// Deconstructor
	bool doTransact(HashTable&, BinTree&);									//execute transaction
};																			