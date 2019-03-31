#include "pch.h"
#include "Customer.h"


Customer::Customer()
{
	this->cusID = 0;
	this->fName = "";
	this->lName = "";
}
Customer::Customer(int cusID, string fName, string lName)
{
	this->cusID = cusID;
	this->fName = fName;
	this->lName = lName;
}
Customer::~Customer()
{
	for (int i = 0; i < records.size(); i++)
	{
		delete records[i];
	}
}
int Customer::getCusID() const
{
	return cusID;
}
void Customer::setCusID(int id)
{
	cusID = id;
}
string Customer::getFName() const
{
	return fName;
}
void Customer::setFName(string fName)
{
	this->fName = fName;
}
string Customer::getLName() const
{
	return lName;
}
void Customer::setLName(string lName)
{
	this->lName = lName;
}

void Customer::addRecord( Movie& movie, const char mediaType, const string year_or_actor,const char trType)
{
		Record* curRec = new Record(cusID, movie.getMType(), movie.getTitle(), movie.getDirector(), mediaType, year_or_actor,trType);
		records.push_back(curRec);
		}

vector<Record*> Customer::getRecords() const
{
	return records;
}

Customer Customer::operator=(const Customer& cust)
{
	this->cusID = cust.getCusID();
	this->fName = cust.getFName();
	this->lName = cust.getLName();
	vector<Record*> paraRecords = cust.getRecords();
	for (int i = 0; i < paraRecords.size(); i++)
	{
		Record* curRec = new Record(paraRecords[i]->getCId()
			, paraRecords[i]->getMType(), paraRecords[i]->getTitle(), paraRecords[i]->getDirector(),
			paraRecords[i]->getMediaType(), paraRecords[i]->getYear_or_actor(),paraRecords[i]->getTrType(), paraRecords[i]->getDate());
		records.push_back(curRec);
	}
	return *this;
}


bool  Customer::operator== (const Customer& cust)
{
	return cusID == cust.getCusID();
}