#pragma once
#include <iostream>
#include <time.h>
using namespace std;

/*
Record class:

-Store the transaction history.
-The history contain the customer id, movie info and transaction date&time
-allows to get/set the field


*/

class Record
{
public:
	Record();																			//default constructor												
	Record(int cid, char mType, string title, string director,  char mediaType
		, string year_or_actor,char trType);											//Constructor with info parameter
	Record(int cid, char mType, string title, string director,  char mediaType
		, string year_or_actor, char trType, string date);								//Constructor with info parameter and date(Used when make deep copy)
	~Record();																			//destructor

	int getCId();																		// Getter/Setter
	char getTrType() const;
	char getMType() const;
	string getTitle() const;
	string getDirector() const;
	string getDate() const;
	char getMediaType() const;
	string getYear_or_actor() const;

private:
	int cId;																			//Customer ID
	char trType;																		//Transaction type
	char mType;																			//Movie Type
	string title;																		// Movie title
	string director;																	//Movie director
	char mediaType;																		//Media Type (DVD£©
	string date;																		//Transaction date
	string year_or_actor;																//Released year or Released year and main actor
};

