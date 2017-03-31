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
	void displayRaw(ostream&s);
	int search(T data);
	
	ArrayBST<T>(int size);
	friend ostream&operator<<(ostream&s,ArrayBST<T> const&a);
};