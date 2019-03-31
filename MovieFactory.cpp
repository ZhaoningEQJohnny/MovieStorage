#include "pch.h"
#include "MovieFactory.h"



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




Movie* MovieFactory::createMovie(string line)
{
	vector<string>  infos;
	SplitStr(line, infos, ',');
	char mType = infos[0][0];
	int stock = atoi(infos[1].substr(1, infos[1].size()-1).c_str());
	string director = infos[2].substr(1, infos[2].size() - 1);
	string title = infos[3].substr(1, infos[3].size() - 1);
	

	switch (mType)
	{
	case 'C':
	{
		string year_Actor = infos[4].substr(1, infos[4].size() - 1);
		return new Classic(mType, stock, title, director, year_Actor);
		break;
	}
	case 'D':
	{
		int releasedYear = atoi(infos[4].substr(1, infos[4].size() - 1).c_str());
		return new Drama(mType, stock, title, director, releasedYear);
		break;
	}
	case 'F':
	{
		int releasedYear = atoi(infos[4].substr(1, infos[4].size() - 1).c_str());
		return new Comedy(mType, stock, title, director, releasedYear);
		break;
	}
	default:
		cout <<"Error: Movie <<"<<title <<">>  has an invalid movie type, fail to initialize" << endl;
		break;
	}
	return NULL;
}