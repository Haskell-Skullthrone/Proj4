#pragma once
#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include "node.h"
#include "ArrayBT.h"
template<class T>class ArrayBST:virtual public ArrayBT<T>{
	public:
	void insert(Node<T>data);
	void remove(Node<T>data);
	void inOrder(ostream&s);
	void postOrder(ostream&s);
	void remove(Node<t>data);
	int search(Node&t t);
	void displayRaw(ostream&s);
	friend ostream&operator<<(ostream&s,ArrayBST<T>&a);
}