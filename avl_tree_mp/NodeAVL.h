#pragma once

#ifndef NODEAVL_H_
#define NODEAVL_H_


template<class T>
struct NodeAVL
{
	NodeAVL<T>* left;
	NodeAVL<T>* right;
	T data;
	int height;
	NodeAVL();
};


#endif // !