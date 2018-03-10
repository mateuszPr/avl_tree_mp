#include <iostream>
using namespace std;



template<class T>
struct NodeAVL
{
	NodeAVL<T>* left;
	NodeAVL<T>* right;
	T data;
	int height;
	NodeAVL();
};


template<class T>
NodeAVL<T>::NodeAVL()
{
	height = 1;   //always start node with height = 1
}


template<class T>
class AVLTree
{
public:
	NodeAVL<T> *insert(NodeAVL<T> *root, T value);
	NodeAVL<T> *remove(NodeAVL<T> *root, T value);
	NodeAVL<T> *RR(NodeAVL<T> *root);
	NodeAVL<T> *LR(NodeAVL<T> *root);
	int getHeight(NodeAVL<T> *root);
	int max(int first, int second);
	int checkBalace(NodeAVL<T> *root);
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

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	int balance = checkBalace(root);

	if (balance > 1 && value < root->left->data)
		return RR(root);

	if (balance < -1 && value > root->right->data)
		return LR(root);

	if (balance > 1 && value > root->left->data)
	{
		root->left = LR(root->left);
		return RR(root);
	}

	if (balance < -1 && value < root->right->data)
	{
		root->right = RR(root->right);
		return LR(root);
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
			root->right = remove(root->right, temp->data);  //Finding the old element, that we dont need anymore
		}
	}
	return root;
}

template<class T>
NodeAVL<T>* AVLTree<T>::RR(NodeAVL<T> *root)
{
	NodeAVL<T> *firstChild = root->left;
	NodeAVL<T> *nextChild = firstChild->right;

	firstChild->right = root;
	root->left = nextChild;

	//change heights
	firstChild->height = max(getHeight(firstChild->left), getHeight(firstChild->right)) + 1;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	return firstChild;
}




template<class T>
NodeAVL<T>* AVLTree<T>::LR(NodeAVL<T> *root)
{
	NodeAVL<T> *firstChild = root->right;
	NodeAVL<T> *nextChild = firstChild->left;

	firstChild->left = root;
	root->right = nextChild;

	//change heights
	firstChild->height = max(getHeight(firstChild->left), getHeight(firstChild->right)) + 1;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

	return firstChild;
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
	if (first >= second)
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
	root = start.insert(root, 49);
	root = start.insert(root, 48);
	root = start.insert(root, 47);
	root = start.insert(root, 45);
	root = start.insert(root, 44);
	root = start.insert(root, 43);
	root = start.insert(root, 42);
	root = start.insert(root, 41);
	root = start.insert(root, 40);
	root = start.remove(root, 50);




	start.display(root, 0);



	getchar();
	return 0;
}