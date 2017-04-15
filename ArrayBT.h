
#pragma once
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include "node.h"
using namespace std;
template<class T>class ArrayBT{
	public:
	vector<Node<T>*>myBinaryTree;
	int _root;
	int _numNodes;
	int size;
	void insertLeft(T data,int pos);
	void insertRight(T data,int pos);
	stack<int>freeLocations;
	const void inOrder();
	const void postOrder();
	const void preOrder();
};
template<class T> void ArrayBT<T>::insertLeft(T data,int pos){
	if(myBinaryTree[pos]->left!=-1){
		if(freeLocations.empty()){	
			myBinaryTree[pos]->left=myBinaryTree.size();
			myBinaryTree.push_back(new Node<T>(new T(data),-1,-1));
		}else{
			myBinaryTree[pos]->left=freeLocations.top();
			myBinaryTree[freeLocations.top()]=new Node<T>(new T(data),-1,-1);
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
			myBinaryTree.push_back(new Node<T>(new T(data),-1,-1));
		}else{
			myBinaryTree[pos]->right=freeLocations.top();
			myBinaryTree[freeLocations.top()]=new Node<T>(new T(data),-1,-1);
			freeLocations.pop();
		}
	}else{
		*(myBinaryTree[myBinaryTree[pos]->right]->info)=data;
	}
}
template<class T>const void ArrayBT<T>::inOrder(){
	int pos = _root;
	stack<int>traversedNodes;
	
	while(!traversedNodes.empty()||myBinaryTree[pos]->info!=NULL){
		if(myBinaryTree[pos]->info!=NULL){
			traversedNodes.push(pos);
			pos=myBinaryTree[pos]->left;
		}else{
			pos = traversedNodes.top();
			traversedNodes.pop();
			
			cout<<*myBinaryTree[pos];
			pos = myBinaryTree[pos]->right;
		}
	}
}

template<class T>const void ArrayBT<T>::postOrder(){
	int pos = _root;
	stack<int>traversedNodes;
	
	while(!traversedNodes.empty()||myBinaryTree[pos]->info!=NULL){
		if(myBinaryTree[pos]->info!=NULL){
			traversedNodes.push(pos);
			pos=myBinaryTree[pos]->left;
		}
		else if(myBinaryTree[traversedNodes.top()]->right!=-1&&
					pos!=myBinaryTree[pos]->right){
			
			pos=myBinaryTree[pos]->right;
		}
		else{
			cout<<*myBinaryTree[pos];
			pos = traversedNodes.top();
			traversedNodes.pop();
		}
	}
}

template<class T>const void ArrayBT<T>::preOrder(){
	int pos = _root;
	stack<int>traversedNodes;
	
	while(!traversedNodes.empty()||myBinaryTree[pos]->info!=NULL){
		if(myBinaryTree[pos]->info!=NULL){
			traversedNodes.push(pos);
			pos=myBinaryTree[pos]->left;
		}else{
			pos = traversedNodes.top();
			traversedNodes.pop();
			cout<<*myBinaryTree[pos];
			pos = myBinaryTree[pos]->right;
		}
	}
}
