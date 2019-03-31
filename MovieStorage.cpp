#pragma once
#include "pch.h"
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include "BusinessLogic.h"
#include <fstream>

using namespace std;

void SplitStr(string s, vector<string>& v, char c)
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

int main()
{
	BusinessLogic bl;
	BinTree* movieTree = new BinTree;
	HashTable* custTable = new HashTable;
	ifstream data4commands("data4commands.txt");
	ifstream data4customers("data4customers.txt");
	ifstream data4movies("data4movies.txt");

	bl.initialCustomers(data4customers, *custTable);
	bl.initialMovies(data4movies, *movieTree);
	bl.commandExecution(data4commands,*movieTree,*custTable);
	delete movieTree;
	delete custTable;
	//cout<<getTime();
}

