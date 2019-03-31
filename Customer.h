#pragma once
#include <iostream>
#include "Movie.h"
#include <vector>
#include "Record.h"

/*
Customer class:  

-store customer info which contain: customer ID, customer first name, and customer last name

-allows to set and get the fields
-allows to add and get transaction record
-allows to make deep copy
-allows to compare with customer id

*/



using namespace std;
class Customer
{
public:
	Customer();
	Customer(int cusID, string fName, string lName);
	~Customer();
	int getCusID() const;
	void setCusID(int id);
	string getFName() const;
	void setFName(string fName);
	string getLName() const;
	void setLName(string lName);
	vector<Record* > getRecords() const;
	void addRecord( Movie&, const char , const string year_or_actor, const char);
	Customer operator= (const Customer& cust);
	bool operator== (const Customer& cust);


private:
	int cusID;
	string fName;
	string lName;
	vector<Record*> records;
};