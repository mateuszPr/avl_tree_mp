#include "AVLTree.h"
#include "NodeAVL.h"

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
		int balance = checkBalace(root);

		if (balance > 1 && value < root->left->data)  //img: https://www.tutorialspoint.com/data_structures_algorithms/images/avl_right_rotation.jpg
			return RR(root);
		if (balance > 1 && value > root->left->data)  //img: http://btechsmartclass.com/DS/images/LR%20Rotation.png
		{
			root->left = LR(root->left);
			return RR(root);
		}
	}


	else if (value >= root->data)
	{
		root->right = insert(root->right, value);
		int balance = checkBalace(root);

		if (balance < -1 && value > root->right->data)  //img: https://www.tutorialspoint.com/data_structures_algorithms/images/avl_right_rotation.jpg
			return LR(root);

		if (balance < -1 && value < root->right->data)  //img: http://btechsmartclass.com/DS/images/RL%20Rotation.png
		{
			root->right = RR(root->right);
			return LR(root);
		}
	}

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));


	return root;
}


template<class T>
NodeAVL<T>* AVLTree<T>::remove(NodeAVL<T> *root, T value)
{
	if (root == NULL)
	{
		return root;
	}
	else if (value < root->data)  //Try on the left side
	{
		root->left = remove(root->left, value);
	}
	else if (value > root->data)  //Try on the right side
	{
		root->right = remove(root->right, value);
	}
	else  //If the value passed is equal to the element that I want to remove  
	{
		//Zero or one child
		if (root->left == NULL)
		{
			NodeAVL<T>* temporary = root->right;
			delete root;
			return temporary; //Replacing a deleted item with his child
		}
		else if (root->right == NULL)
		{
			NodeAVL<T> *temporary = root->left;
			delete root;
			return temporary; //Replacing a deleted item with his child
		}
		//Two or more childs
		else
		{
			NodeAVL<T>* temp;
			temp = root->right;

			while (temp->left != NULL) // Finding the lowest element of the right child
			{
				temp = temp->left;
			}

			root->data = temp->data;

			remove(root->right, temp->data);  //Finding the old element, that we dont need anymore
		}
	}

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));  //Remember about 1, that represent first element of the tree

	int balance = checkBalace(root);

	if (balance > 1 && checkBalace(root->left) >= 0)
		return RR(root);

	else if (balance > 1 && checkBalace(root->left) < 0)
	{
		root->left = LR(root->left);
		return RR(root);
	}

	else if (balance < -1 && checkBalace(root->right) <= 0)
		return LR(root);

	else if (balance < -1 && checkBalace(root->right) > 0)
	{
		root->right = RR(root->right);
		return LR(root);
	}

	return root;
}




template<class T>
NodeAVL<T>* AVLTree<T>::RR(NodeAVL<T> *root)   //Left child of newParent is still the left child of the root, so we dont have to update this child
{

	NodeAVL<T> *newParent = root->left;
	root->left = newParent->right;
	newParent->right = root;

	//change heights
	newParent->height = max(getHeight(newParent->left), getHeight(newParent->right)) + 1;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	return newParent;
}




template<class T>
NodeAVL<T>* AVLTree<T>::LR(NodeAVL<T> *root)    //Right child of newParent is still the right child of the root, so we dont have to update this child
{
	NodeAVL<T> *newParent = root->right;
	root->right = newParent->left;
	newParent->left = root;

	//change heights
	newParent->height = max(getHeight(newParent->left), getHeight(newParent->right)) + 1;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	return newParent;
}


template<class T>
int AVLTree<T>::getHeight(NodeAVL<T>* root)
{
	if (!root)
		return 0;
	return root->height;
}


template<class T>
int AVLTree<T>::max(int first, int second)
{
	if (first > second)
		return first;
	return second;
}


template<class T>
int AVLTree<T>::checkBalace(NodeAVL<T>* root)
{
	if (!root)
		return 0;
	return (getHeight(root->left) - getHeight(root->right));
}


template<class T>
void AVLTree<T>::inorder(NodeAVL<T> *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << "  ";
	inorder(root->right);
}


template<class T>
void AVLTree<T>::display(NodeAVL<T> *root, int start)
{
	int i = 1;
	if (root)
	{
		display(root->right, start + 1);
		cout << "\n";
		for (i = 0; i < start; i++)
			cout << "        ";
		cout << root->data;
		display(root->left, start + 1);
	}
}