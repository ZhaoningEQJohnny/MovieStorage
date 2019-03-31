#include "pch.h"
#include "Transaction.h"


Transaction::Transaction()
{
	cust = NULL;
	this->trType = 'I';
	movie = NULL;
	mediaType = 'Z';
}

Transaction::Transaction(Customer& cust)
{
	this->cust = &cust;
	this->trType = 'H';
	movie = NULL;
	mediaType = 'Z';
}


Transaction::Transaction(Customer& cust,  Movie& movie, char mediaType,char trType)
{
	this->cust = &cust;
	this->trType = trType;
	this->movie = &movie;
	this->mediaType = mediaType;
}

Transaction::~Transaction()
{
	movie = NULL;
	cust = NULL;
}

char Transaction::getTrType() const
{ 
	return trType;
}

Movie* Transaction::getMovie() const
{
	return movie;
}
Customer* Transaction::getCust() const
{
	return cust;
}
char Transaction::getMediaType()const
{
	return mediaType;
}

bool Transaction::doTransact(HashTable&, BinTree&)
{
	cout<< "No specific transaction claimed"<<endl;
	return false;
}