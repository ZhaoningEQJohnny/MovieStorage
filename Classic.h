#pragma once
#include  "Movie.h"


/*
Classic class (Inherit from Movie class):

-store classic type movie info into the object
-has a particular field year_Actor, represent Main actor and released year
	*Note: In my understand, I treat the classic movie with same title and director and different main actor
			as one movie object. Therefore, I store the main actor and released year info into a vector.
			In the display method, if the classic movie has multiple main actor and released year
			it would still show multiple lines with different main actor  and all the other infos.

-allows to compare with other movie
-allows to display the info
-allows to make deep copy

*/


class Classic : public Movie
{
public:
	Classic();																					//Default constructor				
	Classic(char mType, int stock, string title, string director, string year_Actor);			//Constructor with parameter
	~Classic();																					// Deconstructor
	bool operator<(const NodeData &) const;														//overwrite the compare operator
	bool operator==(const NodeData &) const;

	void display() const;																		//overwrite the display function
	vector<string> getYear_Actor() const;														//get main actor and released year
	void addYear_Actor(string);																	//add main actor and released year
	NodeData& operator=(const NodeData &);														//overwrite the deep copy assgin
private:
	vector<string> year_Actor;																	// main actor and released year

};