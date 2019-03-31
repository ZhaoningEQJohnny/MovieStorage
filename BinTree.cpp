#include "pch.h"
#include "BinTree.h"


using namespace std;

// constructor
BinTree::BinTree()
{
	size = 0;
	root = NULL;
}

//copy constructer's recursive helper method
BinTree::Node* BinTree::copyConstrHelper(const Node* paraNode) const
{
	if (paraNode == NULL)
	{
		return NULL;
	}
	Node* newNode = new Node;
	NodeData* newData = new NodeData;
	*newData = *paraNode->data;
	newNode->data = newData;
	newNode->left = copyConstrHelper(paraNode->left);
	newNode->right = copyConstrHelper(paraNode->right);
	

	return newNode;

}

// copy constructor
BinTree::BinTree(const BinTree & refT)
{
	root = copyConstrHelper(refT.root);
	size = refT.getSize();
}


int BinTree::getSize()const
{
	return size;
}

// destructor, calls makeEmpty
BinTree::~BinTree()
{
	makeEmpty();
}



//check if tree is empty , true if tree is empty, otherwise false
bool BinTree::isEmpty() const
{
	if (root == NULL)
	{
		return true;
	}
	return false;
}

// make the tree empty so isEmpty returns true
void BinTree::makeEmpty()
{
	deleteNode(root);
}


//helper method for makeEmpty, recuisively delete nodes
void BinTree::deleteNode(Node *& n)
{
	if (n != NULL)
	{
		deleteNode(n->left);
		deleteNode(n->right);
		delete n->data;
		n->data = NULL;
		delete n;
		n = NULL;
	}
}


//operator assign overload
BinTree& BinTree::operator=(const BinTree & refT)
{
	if (*this == refT)
	{
		return *this;
	}
	else if (root != NULL)
	{
		makeEmpty();
	}
	root = copyConstrHelper(refT.root);
	return *this;
}

//helper method for operator=, recursively check if equal 
bool BinTree::equalHelper(Node* curNode, Node* paraNode) const
{
	if (curNode == NULL && paraNode == NULL)
	{
		return true;
	}
	if (curNode == NULL && paraNode != NULL || curNode != NULL && paraNode == NULL)
	{
		return false;
	}

	if (*curNode->data != *paraNode->data)
	{
		return false;
	}
	if (curNode != NULL && paraNode != NULL)
	{
		return equalHelper(curNode->left, paraNode->left) && equalHelper(curNode->right, paraNode->right);
	}

	return true;

}

//operator equal overload
bool BinTree::operator==(const BinTree & tree) const
{
	if (this->isEmpty() && tree.isEmpty())
	{
		return true;
	}
	if (!this->isEmpty() && tree.isEmpty() || this->isEmpty() && !tree.isEmpty())
	{
		return false;
	}
	return equalHelper(root, tree.root);

}

//operator not equal overload
bool BinTree::operator!=(const BinTree & tree) const
{
	return 	!(*this == tree);
}


//insert node into the tree
bool BinTree::insert(NodeData* paraRoot)
{
	Node *newNode = new Node;
	newNode->data = paraRoot;
	newNode->left = NULL;
	newNode->right = NULL;
	//if no node in this tree
	if (root == NULL)
	{
		root = newNode;
	}
	//compare with data
	else
	{
		Node * curNode = root;

		//loop switch
		bool notAssigned = true;

		while (notAssigned)
		{
			//if repeated, return false
			if (*paraRoot == *curNode->data)
			{
				delete newNode;
				newNode = NULL;
				return false;
			}
			//if paraRoot < currentNode 
			if (*paraRoot < *curNode->data)
			{
				//check currentNode's left child == NULL

				//if is NULL, assign into the left child
				if (curNode->left == NULL)
				{
					curNode->left = newNode;
					notAssigned = false;
				}
				//if not , go into the left child node
				else
				{
					curNode = curNode->left;
				}
			}
			//otherwise go right
			else
			{
				if (curNode->right == NULL)
				{
					curNode->right = newNode;
					notAssigned = false;
				}
				else
				{
					curNode = curNode->right;
				}
			}
		}


	}
	//delete the pointer which passed in, or it will cause memory leak 
	//since in the buildTree method it doesn't delete the pointer if success

	size++;
	return true;
}

//helper method for get height, recursively count the level height for each node
int BinTree::retrieveLevel(Node *n) const
{
	if (n == NULL)
	{
		return 0;
	}
	int leftLevel = 1 + retrieveLevel(n->left);
	int	rightLevel = 1 + retrieveLevel(n->right);
	int localLevel = (leftLevel > rightLevel) ? leftLevel : rightLevel;
	return localLevel;
}

//helper method for get height, get the node with the given nodedata
BinTree::Node* BinTree::retrieveNode(const NodeData & data, Node * node) const
{
	Node * newNode = NULL;
	if (node != NULL)
	{
		if (*node->data == data)
		{
			newNode = node;
		}
		else
		{
			if (newNode == NULL)
			{

				newNode = retrieveNode(data, node->left);
			}

			if (newNode == NULL)
			{
				newNode = retrieveNode(data, node->right);
			}
		}
	}
	return newNode;
}

// get the height of current node
int BinTree::getHeight(const NodeData & data) const
{
	Node * newNode = retrieveNode(data, root);
	return retrieveLevel(newNode);
}



//retrieve the node from the tree, return true if found, false if not
bool BinTree::retrieve(const NodeData & serData, NodeData* & retData) const
{

	if (isEmpty())
	{
		return false;
	}
	Node* curNode = root;
	while (curNode != NULL)
	{
		if (*curNode->data == serData)
		{
			delete retData;
			retData = curNode->data;
			return true;
		}
		else if (*curNode->data < serData)
		{
			curNode = curNode->right;
		}
		else
		{
			curNode = curNode->left;
		}
	}
	delete curNode;
	curNode = NULL;
	return false;
}
//helper method for arraytotree, 
//recursively insert the node to have a balanced tree
BinTree::Node* BinTree::inorderToTreeHelper(NodeData* ndArr[], int low, int high)
{
	//stop when low bigger than high num
	if (low > high)
	{
		return NULL;
	}
	Node* newNode = new Node;
	NodeData* newData = new NodeData;
	// get the index by the function low+hight / 2
	int index = (low + high) / 2;
	*newData = *ndArr[index];
	delete ndArr[index];
	ndArr[index] = NULL;
	newNode->data = newData;
	int leftIndex = 0;
	int rightIndex = 0;
	//recursively call
	newNode->left = inorderToTreeHelper(ndArr, low, index - 1);
	newNode->right = inorderToTreeHelper(ndArr, index + 1, high);

	return newNode;

}

//transfer array elements to the tree
void BinTree::arrayToBSTree(NodeData* ndArr[])
{
	int count = 0;
	// count how many elements in the array
	while (ndArr[count] != NULL)
	{
		count++;
	}

	int index = count - 1;
	root = inorderToTreeHelper(ndArr, 0, index);


}

//to array helper
void BinTree::inorderToArrayHelper(NodeData* ndArr[], Node* node, int& count) const
{
	if (node == NULL)
	{
		return;
	}
	NodeData* newData = node->data;
	inorderToArrayHelper(ndArr, node->left, count);
	ndArr[count] = newData;
	count++;
	inorderToArrayHelper(ndArr, node->right, count);
}

// transfer tree to array
void BinTree::bstreeToArray(NodeData* ndArr[])
{
	int count = 0;
	inorderToArrayHelper(ndArr, root, count);
}




//cout overload
ostream& operator<<(ostream& output, const BinTree& tree)
{
	tree.inorderOutputHelper(output, tree.root);
	output << endl;
	return output;
}

// output helper
void BinTree::inorderOutputHelper(ostream& oput, Node* paraNode) const
{
	if (paraNode == NULL)
	{
		return;
	}
	inorderOutputHelper(oput, paraNode->left);
	oput << *paraNode->data << " ";
	inorderOutputHelper(oput, paraNode->right);
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}