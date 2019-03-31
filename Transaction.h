#pragma once
#include "Classic.h"
#include "Drama.h"
#include "Comedy.h"
#include <time.h>
#include "HashTable.h"
#include  "BinTree.h"
#include "Customer.h"

/*
Transaction class

-The super class of all type transaction
-store the particular customer info and movie info which is related with this transaction
-Transaction would opereate with the collections of customer and movie


Assumption:

-Assume there's only one video type which is DVD

*/



class Transaction
{
public:
	Transaction();																				//Default Constructor
	Transaction(Customer& cust);																//Constructor with parameter
	Transaction(Customer& cust,  Movie& movie, char mediaType, char trType);
   ~Transaction();																				//Destructor
	
   char getTrType() const;																		// Getter/Settor
   Movie* getMovie ()const;
   Customer* getCust() const;
   char getMediaType()const;
    virtual bool doTransact(HashTable&, BinTree&);												//Execute transaction

private:
	char trType;																				//Transaction type
	Movie* movie;																				//Movie Type
	Customer* cust;																				//Customer 
	char mediaType;																				// media type
};