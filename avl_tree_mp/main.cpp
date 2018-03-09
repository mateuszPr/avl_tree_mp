#include <iostream>
using namespace std;



template<typename T>
struct NodeAVL
{
	NodeAVL<T>* left;
	NodeAVL<T>* right;
	T data;

};


template<class T>
class AVLTree
{
public:
	NodeAVL<T> *insert(NodeAVL<T> *root, T value);
	NodeAVL<T> *remove(NodeAVL<T> *root, T value);
	void display(NodeAVL<T> *root, int start);
	void inorder(NodeAVL<T> *tree);

};



template<class T>
NodeAVL<T>* AVLTree<T>::insert(NodeAVL<T> *root, T value)
{
	if (root == NULL) //Now insert this element here
	{
		root = new NodeAVL<T>; //creating new node
		root->data = value;
		root->left = NULL;
		root->right = NULL;
	}
	else if (value < root->data)
	{
		root->left = insert(root->left, value);
	}
	else if (value >= root->data)
	{
		root->right = insert(root->right, value);
	}
	return root;
}



template<class T>
NodeAVL<T>* AVLTree<T>::remove(NodeAVL<T> *root, T value)
{
	if (root == NULL)
	{
		return root;
	}
	else if (value < root->data)
	{
		root->left = remove(root->left, value);
	}
	else if (value > root->data)
	{
		root->right = remove(root->right, value);
	}
	else
	{
		//Zero or one child
		if (root->left == NULL)
		{
			NodeAVL<T>* temporary = root->right;
			delete root;
			return temporary;
		}
		else if (root->right == NULL)
		{
			NodeAVL<T> *temporary = root->left;
			delete root;
			return temporary;
		}
		//Two or more childs

		NodeAVL<T>* temp;
		temp = root->right;

		while (temp->left != NULL)
		{								//Finding the lowest element of the right child
			temp = temp->left;
		}

		root->data = temp->data;
		root->right = remove(root->right, temp->data);
	}
	return root;
}


template<class T>
void AVLTree<T>::inorder(NodeAVL<T> *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << tree->data << "  ";
	inorder(tree->right);
}


template<class T>
void AVLTree<T>::display(NodeAVL<T> *root, int start)
{
	int i = 1;
	if (root)
	{
		display(root->right, start + 1);
		cout << "\n";
		for (i = 0; i < start ; i++)
			cout << "        ";
		cout << root->data;
		display(root->left, start + 1);
	}
}



int main()
{
	NodeAVL<int> *root = NULL;
	AVLTree<int> start;
	root = start.insert(root, 50);
	root = start.insert(root, 30);
	root = start.insert(root, 12);
	root = start.insert(root, 20);
	root = start.insert(root, 10);


	root = start.remove(root, 30);

	start.display(root, 0);


	getchar();
	return 0;
}