#pragma once
#include "Borrow.h"
#include "Return.h"
#include "Inventory.h"
#include "History.h"
#include "HashTable.h"
#include "BinTree.h"

/*
TransactionFactory class:


-A factory which can produce the different types of transaction object
-allows to retrieve  and analyze the info line to get the command order



*/


class TransactionFactory
{
public:
	Transaction* createTransaction(string line, HashTable& custTable, BinTree& movieTree);		//Generate transaction object

};