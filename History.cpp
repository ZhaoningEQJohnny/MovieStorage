#include "pch.h"
#include "History.h"
#include "Customer.h"



History::History()
{

}
History::History(Customer& cust): Transaction(cust)
{

}
History::~History()
{

}



bool History::doTransact(HashTable& custTable, BinTree& movieTree)
{
	int custID = getCust()->getCusID();
	string custFName = getCust()->getFName();
	string custLName = getCust()->getLName();
	cout << "ID: " << custID << " Name:" << custFName << " " << custLName<<endl;
	vector<Record*> transactions = getCust()->getRecords();
	if (transactions.size() == 0)
	{
		cout << "Error: No transaction history" << endl;
		return false;
	}


	for (int i = 0; i < transactions.size(); i++)
	{
		//trType  cid  videoType(D)  movieType(C)  year||year_Actor 
		if (transactions[i]->getTrType()!= 'B' && transactions[i]->getTrType() != 'R')
		{
			cout << "Error: Disrupted record" << endl;
			continue;
		}
		//output transaction type
		if (transactions[i]->getTrType() == 'B')
			cout << "Borrowed ";
		if (transactions[i]->getTrType() == 'R')
			cout << "Returned ";

		//output mediaType
		if (transactions[i]->getMediaType() == 'D')
			cout<< setw(10) << "DVD "<< setw(10);

		//output movieType
		string year_or_withActor;
		if (transactions[i]->getMType() == 'C')
		{
			cout << "Classic ";
		}
		else if (transactions[i]->getMType() == 'F')
		{
			cout << "Comedy ";

		}
		else if (transactions[i]->getMType() == 'D')
		{
			cout << "Drama ";

		}
		//output movie data
		cout<< setw(20) << transactions[i]->getDirector() << setw(25) << transactions[i]->getTitle() << setw(25) <<transactions[i]->getYear_or_actor()<<setw(25)
		 << transactions[i]->getDate() <<endl;


	}
	return true;

}