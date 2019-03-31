#pragma once
#include  "Movie.h"

/*
Drama class (Inherit from Movie class):   Object of drama type movie

-store drama type movie info into the object
-has a particular field yearReleased, represent movie released year
-allows to compare with other movie
-allows to display the info
-allows to make deep copy

*/


class Drama : public Movie
{
public:
	Drama();																							//Default constructor					
	Drama(char mType, int stock, string title, string director, int yearRelease);						//Constructor with parameter
	~Drama();																							// Deconstructor
	bool operator<(const NodeData &) const;																//overwrite the compare operator
	bool operator==(const NodeData &) const;

	void display() const;																				//overwrite the display function
	int getYearRelease() const;																			//get released year
	void setYearRelease(int);																			//set released year
	NodeData& operator=(const NodeData &);																//overwrite the deep copy assgin
private:
	int yearRelease;																					// released year
};