#pragma once
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "node.h"
using namespace std;
template<class T>class ArrayBT{
	public:
	vector<Node<T*>*>myBinaryTree;
	int _root;
	int _numNodes;
	int size;
	void insert(T data);
	stack<int>freeLocations;
	void remove(T data);
	int search(T data);
	
	private:
};
	