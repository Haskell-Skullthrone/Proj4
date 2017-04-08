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
	void insertLeft(T data,int pos);
	void insertRight(T data,int pos);
	stack<int>freeLocations;
	void inOrder();
	void postOrder();
};
template<class T> void ArrayBT<T>::insertLeft(T data,int pos){
	if(myBinaryTree[pos]->left!=-1){
		if(freeLocations.empty()){	
			myBinaryTree[pos]->left=myBinaryTree.size();
			myBinaryTree.push_back(new Node<T*>(new T(data),-1,-1));
		}else{
			myBinaryTree[pos]->left=freeLocations.top();
			myBinaryTree[freeLocations.top()]=new Node<T*>(new T(data),-1,-1);
			freeLocations.pop();
		}
	}else{
		*(myBinaryTree[myBinaryTree[pos]->left]->info)=data;
	}
}
template<class T> void ArrayBT<T>::insertRight(T data,int pos){
	if(myBinaryTree[pos]->right!=-1){
		if(freeLocations.empty()){	
			myBinaryTree[pos]->right=myBinaryTree.size();
			myBinaryTree.push_back(new Node<T*>(new T(data),-1,-1));
		}else{
			myBinaryTree[pos]->right=freeLocations.top();
			myBinaryTree[freeLocations.top()]=new Node<T*>(new T(data),-1,-1);
			freeLocations.pop()
		}
	}else{
		*(myBinaryTree[myBinaryTree[pos]->right]->info)=data;
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
	cout<<*myBinaryTree[traversedNodes.top()];
	traversedNodes.pop();
	do{
		traversedNodes.push(pos);
		pos=myBinaryTree[pos]->right;
	}while(myBinaryTree[myBinaryTree[pos]->left]->info!=NULL);
	cout<<*myBinaryTree[pos];
	traversedNodes.pop();
}

	