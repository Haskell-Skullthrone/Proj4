#pragma once
#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include "node.h"
#include "ArrayBT.h"
template<class T>class ArrayBST:virtual public ArrayBT<T>{
	public:
	void insert(T data);
	void remove(T data);
	void inOrder(ostream&s);
	void postOrder(ostream&s);
	int search(T t);
	void displayRaw(ostream&s);
	
	ArrayBST<T>(int size);
	friend ostream&operator<<(ostream&s,ArrayBST<T>&a);
};