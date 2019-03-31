#pragma once
#include  "Movie.h"

/*
Comedy class (Inherit from Movie class): 

-store comedy type movie info into the object
-has a particular field yearReleased, represent movie released year
-allows to compare with other movie
-allows to display the info
-allows to make deep copy

*/


class Comedy : public Movie
{
public:
	Comedy();																						//Default constructor								
	Comedy(char mType, int stock, string title, string director, int yearRelease);					//Constructor with parameter
	~Comedy();																						// Deconstructor
	bool operator<(const NodeData &) const;															//overwrite the compare operator
	bool operator==(const NodeData &) const;

	void display() const;																			//overwrite the display function
	int getYearRelease() const;																		//get released year
	void setYearRelease(int);																		//set released year
	NodeData& operator=(const NodeData &);															//overwrite the deep copy assgin
private:
	int yearRelease;																				// released year
};