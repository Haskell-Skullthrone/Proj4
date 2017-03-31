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
	void inOrder();
	void postOrder();
	
	private:
};
template<class T> void ArrayBT<T>::inOrder(){
	int pos = _root;
	stack<int>traversedNodes;

	do{
		traversedNodes.push(pos);
		pos=myBinaryTree[pos]->left;
	}while(myBinaryTree[myBinaryTree[pos]->left]->info!=NULL);
	cout<<*myBinaryTree[pos];
	cout<<*myBinaryTree[traversedNodes.pop()];
	do{
		traversedNodes.push(pos);
		pos=myBinaryTree[pos]->right;
	}while(myBinaryTree[myBinaryTree[pos]->left]->info!=NULL);
	cout<<*myBinaryTree[pos];
	traversedNodes.pop();
}

	