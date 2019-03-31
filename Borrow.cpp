#include "pch.h"
#include "Borrow.h"


Borrow::Borrow()
{

}
Borrow::Borrow(Customer& cust, Movie& movie, char mediaType, char trType) : Transaction(cust, movie, mediaType, trType)
{
}
Borrow::~Borrow()
{

}



bool Borrow::doTransact(HashTable& custTable, BinTree& movieTree)
{
	Customer* c =new Customer;
	bool ifExist = custTable.find(getCust()->getCusID(), c);
	if (!ifExist)
	{
		cout << "Customer not exsit" << endl;
		return false;
	}
	//add record
	string year_or_actor;
	char mType = getMovie()->getMType();
	if (mType == 'F')
	{
		year_or_actor = to_string(dynamic_cast<Comedy*>(getMovie())->getYearRelease());
	}
	else if (mType == 'D')
	{
		year_or_actor = to_string(dynamic_cast<Drama*>(getMovie())->getYearRelease());
	}
	else if (mType == 'C')
	{
		year_or_actor = dynamic_cast<Classic*>(getMovie())->getYear_Actor()[0];
	}

	getCust()->addRecord(*getMovie(), getMediaType(), year_or_actor,getTrType());
	if (getMovie()->getStock() == 0)
	{
		cout << "Error: Movie <<" << getMovie()->getTitle() << ">> out of stock" << endl;
		return false;
	}
	getMovie()->borrowMovie();
	return true;
}