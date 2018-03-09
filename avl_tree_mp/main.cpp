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

int main()
{
	NodeAVL<int> *root = NULL;
	AVLTree<int> start;
	root = start.insert(root, 8);
	root = start.insert(root, 11);
	root = start.insert(root, 121);



	start.inorder(root);
	root = start.remove(root, 8);

	getchar();
	return 0;
}