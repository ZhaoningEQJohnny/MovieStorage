#include "pch.h"
#include <iostream>
#include "HashTable.h"

HashTable::HashTable()
{
	size = 10;
	chain = new Bucket*[size];
	for (int i = 0; i < size; i++)
	{
		chain[i] = NULL;
	}
}
HashTable::~HashTable()
{
	deleteTable();
}
bool HashTable::insertItem(Customer& cust)
{
	int hashIndex = hashFunction(cust.getCusID());
	Customer* newCust = new Customer(cust.getCusID(), cust.getFName(), cust.getLName());
	//make a pointer point to the head
	Bucket* headBuk = chain[hashIndex];

	if (chain[hashIndex] == NULL)
	{
		Bucket* newBuk = new Bucket;
		newBuk->cust = newCust;
		chain[hashIndex] = newBuk;
		chain[hashIndex]->next = NULL;
	}
	else
	{
		Bucket* newBuk = new Bucket;
		newBuk->cust = newCust;
		newBuk->next = headBuk->next;
		headBuk->next = newBuk;
	}
	return true;
}
int HashTable::hashFunction(int x)
{
	return (x% size);
}
bool HashTable::deleteTable()
{
	for (int i = 0; i < size; i++)
	{
		Bucket* curBuk = chain[i];
		while (curBuk != NULL)
		{
			Bucket* temp = curBuk;
			curBuk = curBuk->next;
			if (temp->cust != NULL)
			{
				delete temp->cust;
				temp->cust = NULL;
			}
			delete temp;
			temp = NULL;
		}
	}
	return true;

}

bool HashTable::find(int cid, Customer* & retrieve)
{
	int hashIndex = hashFunction(cid);
	Bucket* curBuk = chain[hashIndex];
	while (curBuk != NULL)
	{
		if (curBuk->cust->getCusID() == cid)
		{
			delete retrieve;
			retrieve = curBuk->cust;
			return  true;
		}
		curBuk = curBuk->next;
	}
	return false;
}


