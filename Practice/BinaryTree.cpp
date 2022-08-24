#include <iostream>
#include <initializer_list>

struct Node
{
	int data;
	Node* right;
	Node* left;
};

void Show(const int & value)
{ 
	std::cout << value << ' ';
}

class MyBinaryTree
{
public:
	// const and dest
	MyBinaryTree();
	MyBinaryTree(const std::initializer_list<int>& inList);
	~MyBinaryTree();

	bool Insert(const int& value);

	void DoForAllElements(void(*)(const int &));
protected:
	void DoForNode(Node* node, void(*pShow)(const int&));
private:
	Node* root;
};

MyBinaryTree::MyBinaryTree() : root(nullptr)
{
}

MyBinaryTree::MyBinaryTree(const std::initializer_list<int>& inList) : root(nullptr)
{
	for (const int * value = inList.begin(); value != inList.end(); ++value)
	{	
		Insert(*value);
	}
}

MyBinaryTree::~MyBinaryTree()
{
}

void MyBinaryTree::DoForNode(Node* node, void(*pShow)(const int&))
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
		{
			DoForNode(node->left, pShow);
		}
		Show(node->data);
		if (node->right != nullptr)
		{
			DoForNode(node->right, pShow);
		}
	}
}

void MyBinaryTree::DoForAllElements(void(*)(const int&))
{
	DoForNode(root, Show);
}


bool MyBinaryTree::Insert(const int& value)
{
	if (root == nullptr)
	{
		root = new Node{ value, nullptr, nullptr };
		return true;
	}
}


int main()
{
	MyBinaryTree MyTree{ 19 };
	MyTree.DoForAllElements(Show);
	return 0;
}