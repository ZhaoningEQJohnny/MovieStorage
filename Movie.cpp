#include "pch.h"
#include "Movie.h"

Movie::Movie()
{
	stock = 0;
	title = "";
	mType = 'X';
	director = "";
	total = 0;

}

Movie::Movie(char mType, int stock, string title, string director)
{
	this->total = stock;
	this->stock = stock;
	this->title = title;
	this->mType = mType;
	this->director = director;
}
Movie::~Movie()
{

}
int Movie::getStock() const
{
	return stock;
}
void Movie::setStock(int stock)
{
	this->stock = stock;
}
string Movie::getTitle() const
{
	return title;
}
void Movie::setTitle(string title)
{
	this->title = title;
}
char Movie::getMType() const
{
	return mType;
}
void Movie::setMType(char mType)
{
	this->mType = mType;
}
string Movie::getDirector() const
{
	return director;
}
void Movie::setDirector(string director)
{
	this->director = director;
}




bool Movie::borrowMovie()
{
	stock--;
	return true;
}
bool Movie::returnMovie()
{
	stock++;
	return true;
}

int Movie::getTotal() const
{
	return total;
}

bool Movie::operator<(const NodeData & paraMovie) const
{

	if (*this == paraMovie)
		return false;
	vector<string> tVec1, tVec2;
	string title1 = getTitle();
	string title2 = dynamic_cast<const Movie&>(paraMovie).getTitle();
	SplitStr(title1, tVec1, ' ');
	SplitStr(title2, tVec2, ' ');


	//compare title

	for (int i = 0; i < tVec1.size(); i++)
	{
		if (i + 1 > tVec2.size())
			return false;
		for (int j = 0; j < tVec1[i].length(); j++)
		{
			if (i + 1 > tVec2[i].length())
				return false;
			if (tVec1[i][j] < tVec2[i][j])
				return true;
			if (tVec1[i][j] > tVec2[i][j])
				return false;
		}
	}

	return false;

}
bool Movie:: operator==(const NodeData & paraMovie) const
{
	if (getMType() != dynamic_cast<const Movie&>(paraMovie).getMType())
		return false;
	if (getStock() != dynamic_cast<const Movie&>(paraMovie).getStock())
		return false;
	if (getTitle() != dynamic_cast<const Movie&>(paraMovie).getTitle())
		return false;
	if (getDirector() != dynamic_cast<const Movie&>(paraMovie).getDirector())
		return false;
	return true;
}
void Movie::display() const
{
	cout << "Movie Type: Classic" << ", Stock: " << getStock() << ", Director: " << getDirector() <<
		", Title: " << getTitle();
}


//split helper
 void Movie::SplitStr(string s, vector<string>& v, char c) const
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

 NodeData& Movie::operator= (const NodeData& movie)
 {
	 this->stock = dynamic_cast<const Movie&>(movie).getStock();
	 this->title = dynamic_cast<const Movie&>(movie).getTitle();
	 this->mType = dynamic_cast<const Movie&>(movie).getMType();
	 this->director = dynamic_cast<const Movie&>(movie).getDirector();

	 return *this;
 }