
/*

Movie class (Inherit from NodeData type, can be saved in Binary Search Tree):

-store movie information which contains movie stock, title, director, movie type and total amount(full stock number)

-allows to get/set the data
-allows to make deep copy 
-allows to compare with other movie
-allows to modify the movie stock(+1 or -1) when movie is borrowed or returned.


Assumption:

-Assume all the data is in correct format (i.e. Director, Main actor both have first name & last name,
and split with white space )

-Assume all the data of string are expected to be sorted  alphabetically. Name was sorted with first name first,
last name next. 

*/

#pragma once
#include <iostream>
#include "NodeData.h"
#include <vector>
#include <iomanip>

using namespace std;
class Movie : public NodeData
{
public:
	Movie();														//Default consturctor
	virtual ~Movie();												//Destructor
	Movie(char, int, string, string);								//Constructor with info parameter
	int getStock() const;											// Getter/Setter
	void setStock(int);
	string getTitle() const;
	void setTitle(string);
	char getMType() const;
	void setMType(char);
	string getDirector() const;
	void setDirector(string);
	int getTotal() const;

	bool borrowMovie();												//modify movie stock when movie was borrowed
	bool returnMovie();												//modify movie stock when movie was returned

	virtual NodeData& operator=(const NodeData &);					//overwrite the deep copy assign 
	virtual bool operator<(const NodeData &) const;					//overwrite the compare operator
	virtual  bool operator==(const NodeData &) const;
	virtual void display() const;									// display the movie info

	void SplitStr(string s, vector<string>& v, char c) const;			//string split helper

private:
	char mType;										//movie type
	int stock;										//movie stock
	string title;									//movie title
	string director;								//movie director
	int total;										//total number of video amount
};