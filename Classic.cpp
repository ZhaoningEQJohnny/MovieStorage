#include "pch.h"
#include "Classic.h"


Classic::Classic()
{
}

Classic::Classic(char mType, int stock, string title, string director, string yActor) : Movie(mType, stock, title, director)
{
	this->year_Actor.push_back(yActor);
}

Classic::~Classic()
{
}
bool Classic::operator<(const NodeData & paraMovie) const
{

	char paraMType = dynamic_cast<const Movie&>(paraMovie).getMType();
	//CASE1: compare  movies with differ movie type 
	//f<d<c
	if (paraMType == 'F' || paraMType == 'D')
		return false;

	if (*this == paraMovie)
		return false;
	vector<string> yaVec1, yaVec2;
	string year_Ac1 = getYear_Actor()[0];
	string year_Ac2 = dynamic_cast<const Classic&>(paraMovie).getYear_Actor()[0];
	SplitStr(year_Ac1, yaVec1, ' ');
	SplitStr(year_Ac2, yaVec2, ' ');

	string fName1 = yaVec1[0];
	string lName1 = yaVec1[1];
	int mon1 = atoi(yaVec1[2].c_str());
	int y1 = atoi(yaVec1[3].c_str());
	string fName2 = yaVec2[0];
	string lName2 = yaVec2[1];
	int mon2 = atoi(yaVec2[2].c_str());
	int y2 = atoi(yaVec2[3].c_str());

	// compare released year 
	if (y1 < y2)
		return true;
	if (y1 > y2)
		return false;

	//compare month
	if (mon1 < mon2)
		return true;
	if (mon1 > mon2)
		return false;


	//compare main actor
			// compare firstname
	if (fName1 != fName2)
	{
		for (int i = 0; i < fName1.length(); i++)
		{
			if ((i + 1) > fName2.length())
				return false;
			if (fName1[i] < fName2[i])
				return true;
			if (fName1[i] > fName2[i])
				return false;
		}
	}
	// compare lastname
	if (lName1 != lName2)
	{
		for (int i = 0; i < lName1.length(); i++)
		{
			if (i + 1 > lName2.length())
				return false;
			if (lName1[i] < lName2[i])
				return true;
			if (lName1[i] > lName2[i])
				return false;
		}
	}

	return false;

}
bool Classic::operator==(const NodeData & paraMovie) const
{
	if (getMType() != dynamic_cast<const Movie&>(paraMovie).getMType())
		return false;

	vector<string> paraVec = dynamic_cast<const Classic&>(paraMovie).getYear_Actor();
	vector<string> localVec = getYear_Actor();
	for (int i = 0; i < paraVec.size(); i++)
	{
		for (int j = 0; j < localVec.size(); j++)
		{
			if (paraVec[i] == localVec[j])
				return true;
		}
	}

	if (getTitle() != dynamic_cast<const Classic&>(paraMovie).getTitle())
		return false;
	if (getDirector() != dynamic_cast<const Classic&>(paraMovie).getDirector())
		return false;


	return true;
}
void Classic::display()  const
{
	for (int i = 0; i < year_Actor.size(); i++)
	{

		cout << "Classic" << setw(4) << getStock() << setw(20) << getDirector() << setw(40)
			<< getTitle() << setw(30) << (getYear_Actor())[i] << endl;

	}
}
vector<string> Classic::getYear_Actor() const
{
	return year_Actor;
}

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


static bool compareYA(string s1, string s2)
{
	vector<string> yaVec1, yaVec2;
	string year_Ac1 = s1;
	string year_Ac2 = s2;
	SplitStr(year_Ac1, yaVec1, ' ');
	SplitStr(year_Ac2, yaVec2, ' ');

	string fName1 = yaVec1[0];
	string lName1 = yaVec1[1];
	int mon1 = atoi(yaVec1[2].c_str());
	int y1 = atoi(yaVec1[3].c_str());
	string fName2 = yaVec2[0];
	string lName2 = yaVec2[1];
	int mon2 = atoi(yaVec2[2].c_str());
	int y2 = atoi(yaVec2[3].c_str());

	// compare released year 
	if (y1 < y2)
		return true;
	if (y1 > y2)
		return false;

	//compare month
	if (mon1 < mon2)
		return true;
	if (mon1 > mon2)
		return false;


	//compare main actor
			// compare firstname
	if (fName1 != fName2)
	{
		for (int i = 0; i < fName1.length(); i++)
		{
			if ((i + 1) > fName2.length())
				return false;
			if (fName1[i] < fName2[i])
				return true;
			if (fName1[i] > fName2[i])
				return false;
		}
	}
	// compare lastname
	if (lName1 != lName2)
	{
		for (int i = 0; i < lName1.length(); i++)
		{
			if (i + 1 > lName2.length())
				return false;
			if (lName1[i] < lName2[i])
				return true;
			if (lName1[i] > lName2[i])
				return false;
		}
	}

}


void Classic::addYear_Actor(string yActor)
{
	year_Actor.push_back(yActor);

	int counts = year_Actor.size() - 1;
	for (int i = 0; i < counts; i++)
	{
		for (int j = 0; j < counts - i; j++)
		{
			if (!compareYA((year_Actor)[j], (year_Actor)[j + 1]))
			{
				string tmp = year_Actor[j + 1];
				year_Actor[j + 1] = year_Actor[j];
				year_Actor[j] = tmp;
			}
		}
	}

}

NodeData& Classic::operator= (const NodeData& movie)
{
	setStock(dynamic_cast<const Classic&>(movie).getStock());
	setTitle(dynamic_cast<const Classic&>(movie).getTitle());
	setMType(getMType());
	setDirector(dynamic_cast<const Classic&>(movie).getDirector());
	this->year_Actor = dynamic_cast<const Classic&>(movie).getYear_Actor();

	return *this;
}