#pragma once
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

/*
MovieFactory class: 

-A factory which can produce the different types of movie object
-allows to retrieve  and analyze the info line to get the movie info.

*/

class MovieFactory
{
public:
	Movie* createMovie(string line);							//generate movie object
};