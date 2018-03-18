#pragma once
#include "NodeAVL.h"
#ifndef AVLTREE_H_
#define AVLTREE_H_


using namespace std;

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


#endif // !