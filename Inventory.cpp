#include "pch.h"
#include "Inventory.h"


Inventory::Inventory()
{

}
Inventory::~Inventory()
{

}


bool Inventory::doTransact(HashTable& custTable, BinTree& movieTree)
{
	
	int* i = new int[2];
	NodeData* movies [100];
	movieTree.bstreeToArray(movies);
	for (size_t i = 0; i < movieTree.getSize(); i++)
	{
		//output movieType
		string year_or_withActor;
		if (dynamic_cast<Movie*>(movies[i])->getMType() == 'C')
		{
			dynamic_cast<Classic*>(movies[i])->display();
		}
		else if (dynamic_cast<Movie*>(movies[i])->getMType() == 'F')
		{
			dynamic_cast<Comedy*>(movies[i])->display();
		}
		else if (dynamic_cast<Movie*>(movies[i])->getMType() == 'D')
		{
			dynamic_cast<Drama*>(movies[i])->display();
		}
		//output movie data
		
	}
	return true;
}
