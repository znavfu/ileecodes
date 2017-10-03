#include <iostream>
// code stuff 2
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int _data)
	{
		data = _data;
		left = NULL;
		right = NULL;
	}
};

class Tree
{
	Node* root;

public:

	Tree()
	{
		root = NULL;
	}

	void insert(int _data, string where = "")
	{
		Node* temp = new Node(_data);

		if (root == NULL)
		{
			if (where == "")
			{
				root = temp;
			}
			else
			{
				cout << "Can not insert there." << endl;
			}
			return;
		}

		Node* cur = root;

		for (int i=0 ; i<where.length()-1; i++)
		{
			if (cur == NULL)
			{
				cout << "Can not insert there." << endl;
				return;
			}

			if (where[i] == 'L')
			{
				cur = cur->left;
			}
			else if (where[i] == 'R')
			{
				cur = cur->right;
			}
		}

		if (where[where.length()-1] == 'L')
		{
			cur->left = temp;
		}
		else
		{
			cur->right = temp;
		}
	}

	void remove(string where)
	{
		Node* cur = root;

		for (int i=0 ; i<where.length()-1; i++)
		{
			if (where[i] == 'L')
			{
				cur = cur->left;
			}
			else if (where[i] == 'R')
			{
				cur = cur->right;
			}
		}

		if (where[where.length()-1] == 'L')
		{
			delete_subtree(cur->left);
			cur->left = NULL;
		}
		else
		{
			delete_subtree(cur->right);
			cur->right = NULL;
		}
	}

	void delete_subtree(Node* sroot)
	{
		if(sroot->left != NULL)
		{
			delete_subtree(sroot->left);
		}

		if(sroot->right != NULL)
		{
			delete_subtree(sroot->right);
		}

		delete sroot;
	}

	void inorder(Node* cur = NULL)
	{
		if (cur == NULL)
		{
			cur = root;
		}

		if (cur->left != NULL)
		{
			inorder(cur->left);
		}
		
		cout << cur->data << " ";
		
		if (cur->right != NULL)
		{
			inorder(cur->right);
		}
	}

	void search(int key, Node* cur = NULL)
	{
		if (cur == NULL)
		{
			cur = root;
		}

		if (cur->left != NULL)
		{
			search(key, cur->left);
		}
		
		if (cur->data == key)
		{
			cout<<"Found"<<endl;
		}
		
		if (cur->right != NULL)
		{
			search(key, cur->right);
		}
	}

};

int main()
{
	Tree mine;

	mine.insert(1, "");
	mine.insert(2, "L");
	mine.insert(3, "R");
	mine.insert(4, "LL");
	mine.insert(5, "LR");
	mine.insert(6, "RR");
	mine.insert(6, "RRR");
	mine.insert(6, "RRRR");

	mine.inorder();

	//mine.search(23);

	cout<<endl;

	mine.remove("RR");

	mine.inorder();

	return 0;
}


