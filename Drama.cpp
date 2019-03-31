#include "pch.h"
#include "Drama.h"
#include <vector>

Drama::Drama()
{

}

Drama::Drama(char mType, int stock, string title, string director, int yearRelease) : Movie(mType, stock, title, director)
{
	setYearRelease(yearRelease);
}

Drama::~Drama()
{

}


bool Drama::operator<(const NodeData & paraMovie) const
{

	char paraMType = dynamic_cast<const Movie&>(paraMovie).getMType();
	//CASE1: compare  movies with differ movie type 
	//f<d<c
	if (paraMType=='F')
		return false;
	if (paraMType == 'C')
		return true;

	//CASE2: compare  movies with same movie type 


	if (*this == paraMovie)
		return false;
	vector<string> dVec1, dVec2, tVec1, tVec2;
	string direcot1 = getDirector();
	string direcot2 = dynamic_cast<const Drama&>(paraMovie).getDirector();
	SplitStr(direcot1, dVec1, ' ');
	SplitStr(direcot2, dVec2, ' ');

	string title1 = getTitle();
	string title2 = dynamic_cast<const Drama&>(paraMovie).getTitle();
	SplitStr(title1, tVec1, ' ');
	SplitStr(title2, tVec2, ' ');

	string fName1 = dVec1[0];
	string fName2 = dVec2[0];
	string lName1 = dVec1[1];
	string lName2 = dVec2[1];
	// compare director

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
bool Drama::operator==(const NodeData & paraMovie) const
{
	if (getMType() != dynamic_cast<const Movie&>(paraMovie).getMType())
		return false;
	if (getTitle() != dynamic_cast<const Drama&>(paraMovie).getTitle())
		return false;
	if (getDirector() != dynamic_cast<const Drama&>(paraMovie).getDirector())
		return false;
	
	return true;
}
void Drama::display()  const
{
	cout << "Drama" << setw(6) << getStock() << setw(20) << getDirector() << setw(40)
		<< getTitle() << setw(30) << getYearRelease() << endl;
}


int Drama::getYearRelease() const
{
	return yearRelease;
}
void Drama::setYearRelease(int yearRelease)
{
	this->yearRelease = yearRelease;
}

NodeData& Drama::operator= (const NodeData& movie)
{
	setStock(dynamic_cast<const Drama&>(movie).getStock());
	setTitle(dynamic_cast<const Drama&>(movie).getTitle());
	setMType(getMType());
	setDirector(dynamic_cast<const Drama&>(movie).getDirector());
	this->yearRelease = dynamic_cast<const Drama&>(movie).getYearRelease();

	return *this;
}