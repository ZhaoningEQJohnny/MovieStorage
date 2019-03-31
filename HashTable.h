#pragma once
#include "Customer.h"
#include <iostream>
using namespace std;

/*
HashTable class: 

-a data structure wich design to store customer object with open hashing 

-Allows to insert customer object based on the hashFunction
-Allows to delete all the data
-Allows to find the customer object based on the hashFunction




*/

class HashTable
{
public:
	HashTable();															//default constructor
	~HashTable();															// Destructor
	bool insertItem(Customer&);												//insert customer into bucket
	int hashFunction(int id);												//hash function, generate hash code
	bool deleteTable();														//delete function
	bool find(int id, Customer* & retrieve);								//find specific customer by id
private:
	struct Bucket
	{
		Customer* cust;
		Bucket* next;
	};

	Bucket** chain;					//head chain array
	int size;
};