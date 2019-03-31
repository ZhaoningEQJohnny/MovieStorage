#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "MovieFactory.h"
#include "HashTable.h"
#include "BinTree.h"
#include "TransactionFactory.h"
#include "Customer.h"

/*

BusinessLogic class:  Main control of the whole process

-Initialize the customer info
-Initialize the movie info
-Execute the command
	Condition:
		- All the info must be formatted and valid.

Assumption:
-Assume all the info is formatted correctly

*/



using namespace std;

class BusinessLogic
{
public:
	bool initialCustomers(ifstream& infile, HashTable& custTable);			//Initialize customer
	bool initialMovies(ifstream& infile, BinTree& movieTree);				//initialize movie
	bool commandExecution(ifstream& infile,  BinTree& movieTree, HashTable& custTable);	//execute command

};