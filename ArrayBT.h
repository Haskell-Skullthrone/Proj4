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
	stack<int>freeLocations;
	
	private:
}
	