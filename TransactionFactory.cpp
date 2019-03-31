#include "pch.h"
#include "TransactionFactory.h"


static void SplitStr(string s, vector<string>& v, char c, int stopAt)
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (v.size() == stopAt)
			break;
		if (s[i] == c)
		{
			v.push_back(s.substr(count, i - count));
			count = i + 1;
		}
	}
	v.push_back(s.substr(count, s.size()));
}



Transaction* TransactionFactory::createTransaction(string line, HashTable& custTable, BinTree& movieTree)
{


	vector<string> infos;
	char trType = line[0];
	if (trType != 'I'&& trType != 'H' && trType != 'R' && trType != 'B')
	{
		cout << "Error: Invalid Transaction Type" << endl;
		return NULL;
	}

	if (trType == 'I')
		return new Inventory();
	if (trType == 'H')
	{
		SplitStr(line, infos, ' ', -1);
		int cid = atoi(infos[1].c_str());
		Customer* retrievedCust = new Customer();
		if (custTable.find(cid, retrievedCust) == false)
		{
			cout << "Customer " << cid << " not exsit" << endl;
			delete retrievedCust;
			retrievedCust = NULL;
			return NULL;
		}
		return new History(*retrievedCust);
	}

	// borrow or return
	SplitStr(line, infos, ' ', 4);
	int cid = atoi(infos[1].c_str());
	char mediaType = infos[2][0];


	if (mediaType != 'D')
	{
		cout << "Error: " << "Invalid Media Type" << endl;
		return NULL;
	}

	char mType = infos[3][0];
	vector<string> mDatas;
	NodeData* retrievedMovie = new Movie;   //***
	bool movieFound = true;
	if (mType == 'F')
	{
		SplitStr(infos[4], mDatas, ',', -1);
		string title = mDatas[0];
		int releasedYear = atoi(mDatas[1].substr(1, 4).c_str());
		Comedy* comedy = new Comedy('F', 0, title, "", releasedYear);
		movieFound = movieTree.retrieve(*comedy, retrievedMovie);

		if (!movieFound)
		{
			cout << "Error: Movie <<" << comedy->getTitle() << ">> not Found" << endl;
			delete retrievedMovie;
			retrievedMovie = NULL;
			delete comedy;
			comedy = NULL;
			return NULL;
		}
		delete comedy;
		comedy = NULL;

	}
	else if (mType == 'D')
	{
		SplitStr(infos[4], mDatas, ',', -1);
		string director = mDatas[0];
		string title = mDatas[1].substr(1, mDatas[1].size() - 1).c_str();
		Drama* drama = new Drama('D', 0, title, director, 1900);
		movieFound = movieTree.retrieve(*drama, retrievedMovie);

		if (!movieFound)
		{
			cout << "Error: Movie <<" << drama->getTitle() << ">> not Found" << endl;
			delete retrievedMovie;
			retrievedMovie = NULL;
			delete drama;
			drama = NULL;
			return NULL;
		}
		delete drama;
		drama = NULL;

	}
	else if (mType == 'C')
	{
		SplitStr(infos[4], mDatas, ' ', -1);
		string month = mDatas[0];
		string year = mDatas[1];
		string fName = mDatas[2];
		string lName = mDatas[3];
		string year_Actor = fName + " " + lName + " " + month + " " + year;
		Classic* classic = new Classic('C', 0, "", "", year_Actor);
		movieFound = movieTree.retrieve(*classic, retrievedMovie);
		if (!movieFound)
		{
			cout << "Error: Movie with main actor and year: ***" << endl;
			cout << classic->getYear_Actor()[0] << " not Found" << endl;
			delete retrievedMovie;
			retrievedMovie = NULL;
			movieFound = movieTree.retrieve(*classic, retrievedMovie);
			delete classic;
			classic = NULL;
			return NULL;
		}

		delete classic;
		classic = NULL;
	}
	else
	{
		cout << "Error: Invalid Movie Type" << endl;
		return NULL;
	}

	if (!movieFound)
	{
		cout << "Error: Movie not Found" << endl;

		return NULL;
	}

	Customer* retrievedCust = new Customer();
	if (custTable.find(cid, retrievedCust) == false)
	{
		cout << "Customer " << cid << " not exsit" << endl;
		delete retrievedCust;
		retrievedCust = NULL;
		return NULL;
	}

	if (trType == 'R')
		return new Return(*retrievedCust, *dynamic_cast<Movie*>(retrievedMovie), mediaType, trType);
	if (trType == 'B')
		return new Borrow(*retrievedCust, *dynamic_cast<Movie*>(retrievedMovie), mediaType, trType);


	return NULL;
}
