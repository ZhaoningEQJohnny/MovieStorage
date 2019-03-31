#include "pch.h"
#include "Comedy.h"


Comedy::Comedy()
{

}

Comedy::Comedy(char mType, int stock, string title, string director, int yearRelease) : Movie(mType, stock, title, director)
{
	setYearRelease(yearRelease);
}

Comedy::~Comedy()
{

}




bool Comedy::operator<(const NodeData & paraMovie) const
{


	char paraMType = dynamic_cast<const Movie&>(paraMovie).getMType();
	//CASE1: compare  movies with differ movie type 
	//f<d<c
	if (paraMType == 'D'|| paraMType == 'C')
		return true;

	//CASE2: compare  movies with same movie type 




	if (*this == paraMovie)
		return false;
	vector<string> tVec1, tVec2;
	string title1 = getTitle();
	string title2 = dynamic_cast<const Comedy&>(paraMovie).getTitle();
	SplitStr(title1, tVec1, ' ');
	SplitStr(title2, tVec2, ' ');

	int yearR1 = getYearRelease();
	int yearR2 = dynamic_cast<const Comedy&>(paraMovie).getYearRelease();

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

	// compare released year 
	if (yearR1 < yearR2)
		return true;

	return false;

}
bool Comedy::operator==(const NodeData & paraMovie) const
{
	if (getMType() != dynamic_cast<const Movie&>(paraMovie).getMType())
		return false;
	if (getTitle() != dynamic_cast<const Comedy&>(paraMovie).getTitle())
		return false;
	if (getYearRelease() != dynamic_cast<const Comedy&>(paraMovie).getYearRelease())
		return false;
	return true;
}
void Comedy::display()  const
{
	cout << "Comedy" << setw(5) << getStock() << setw(20) << getDirector() << setw(40)
		<< getTitle() << setw(30) << getYearRelease() << endl;
}


int Comedy::getYearRelease() const
{
	return yearRelease;
}
void Comedy::setYearRelease(int yearRelease)
{
	this->yearRelease = yearRelease;
}

NodeData& Comedy::operator= (const NodeData& movie)
{
	setStock(dynamic_cast<const Comedy&>(movie).getStock());
	setTitle(dynamic_cast<const Comedy&>(movie).getTitle());
	setMType(getMType());
	setDirector(dynamic_cast<const Comedy&>(movie).getDirector());
	this->yearRelease = dynamic_cast<const Comedy&>(movie).getYearRelease();
	return *this;
}