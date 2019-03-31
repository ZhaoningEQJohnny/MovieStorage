#include "pch.h"
#include "BusinessLogic.h"

using namespace std;

static void SplitStr(string s, vector<string>& v, char c)
{
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
		{
			v.push_back(s.substr(count, i - count));
			count = i + 1;
		}
	}
		v.push_back(s.substr(count, s.size()));
}


bool BusinessLogic::initialCustomers(ifstream& infile, HashTable& custTable)
{

	if (infile.eof())
	{
		return false;
	}
	string line = "";
	string singleLine = "";
	while (!infile.eof())
	{
		getline(infile, singleLine);
		line += singleLine;
	}

	vector<string> infos;
	int startAt = -1;
	int length;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] < 58)
		{
			
			if (startAt != -1)
			{
				length = i - startAt;
				infos.push_back(line.substr(startAt, length));
			}
			startAt = i;
			i += 3;
		}
	}
	infos.push_back(line.substr(startAt, line.size() - startAt + 1));







	
	for (int i = 0; i < infos.size(); i+=3)
	{

		int cid = atoi(infos[i].c_str());
		string fName = infos[i+1];
		string lName = infos[i+2];

		Customer* cust = new Customer(cid,fName,lName);
		custTable.insertItem(*cust);
	}



	return true;
}
bool BusinessLogic::initialMovies(ifstream& infile,BinTree& movieTree)
{
	if (infile.eof())
	{
		return false;
	}
	string line = "";
	while (!infile.eof())
	{
		getline(infile, line);
		MovieFactory mFactory;
		if (line != "")
		{
			Movie* m = mFactory.createMovie(line);
			if (m != NULL)
			{
				if (!movieTree.insert(m))
				{
					//if duplicate, only save the first movie, and assign the stock as total of those two same movie
					NodeData * dupMovie = new Movie;
					movieTree.retrieve(*m, dupMovie);
					dynamic_cast<Movie*>(dupMovie)->setStock(dynamic_cast<Movie*>(dupMovie)->getStock() + m->getStock());
					if (dynamic_cast<Movie*>(dupMovie)->getMType() == 'C'&& m->getMType()=='C')
					{
						dynamic_cast<Classic *> (dupMovie)->addYear_Actor(dynamic_cast<Classic *>(m)->getYear_Actor()[0]);
					}
					delete m;
					m = NULL;
				}

			}
		}
	}
	return true;
}
bool BusinessLogic::commandExecution(ifstream& infile, BinTree& movieTree, HashTable& custTable)
{
	if (infile.eof())
	{
		return false;
	}
	string line = "";
			int count = 0;
	while (!infile.eof())
	{
		getline(infile, line);
		if (line != "")
		{
			TransactionFactory tFactory;
			Transaction * transaction;
			transaction = tFactory.createTransaction(line, custTable, movieTree);
			count++;
			if (transaction != NULL)
			{
				transaction->doTransact(custTable, movieTree);
				delete transaction;
				transaction = NULL;
			}
		}
	}


	return true;
}


