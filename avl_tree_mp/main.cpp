#include <iostream>
#include "AVLTree.cpp"
#include "NodeAVL.cpp"

using namespace std;


int main()
{
	NodeAVL<int> *root = NULL;
	AVLTree<int> start;

	root = start.insert(root, 10);
	root = start.insert(root, 9);
	root = start.insert(root, 8);

	root = start.insert(root, 7);
	root = start.insert(root, 6);
	root = start.insert(root, 5);

	start.display(root, 0);

	cout << endl;
	cout << endl;
	cout << endl;
	root = start.remove(root, 7);

	start.display(root, 0);

	cout << endl;
	cout << endl;
	cout << endl;

	cout << root->height << endl;

	getchar();
	return 0;
}


