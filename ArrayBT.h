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
	void setLeft(T data,int pos);
	void setRight(T data,int pos);
	stack<int>freeLocations;
	void inOrder();
	void postOrder();
};
template<class T> void insertLeft(T *data,int pos){
	if(myBinaryTree[pos]->left!=-1){
		if(freeLocations.empty()){	
			myBinaryTree[pos]->left=myBinaryTree.size();
			myBinaryTree[myBinaryTree.size]=new Node(data,-1,-1);
		}else{
			myBinaryTree[pos]->left=freeLocations.peek());
			myBinaryTree[freeLocations.pop()]=new Node(data,-1,-1);
		}
	}else{
		myBinaryTree[myBinaryTree[pos]-left]->info=data;
	}
}
template<class T> void insertRight(T *data,int pos){
	if(myBinaryTree[pos]->right!=-1){
		if(freeLocations.empty()){	
			myBinaryTree[pos]->right=myBinaryTree.size();
			myBinaryTree[myBinaryTree.size]=new Node(data,-1,-1);
		}else{
			myBinaryTree[pos]->right=freeLocations.peek());
			myBinaryTree[freeLocations.pop()]=new Node(data,-1,-1);
		}
	}else{
		myBinaryTree[myBinaryTree[pos]-right]->info=data;
	}
}
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

	