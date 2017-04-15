#pragma once
#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include "node.h"
#include "ArrayBT.h"
template<class T>class ArrayBST:public ArrayBT<T>{
	public:
	void insert(T data);
	void remove(T data);
	void displayRaw();
	int search(T data);
	
	ArrayBST<T>(int size):ArrayBT<T>(){
		this->myBinaryTree.reserve(size);
	}
	template<class t>friend ostream&operator<<(ostream&s,ArrayBST<t> const&a);
};
template<class T>void ArrayBST<T>::insert(T data){
	if(data>*(this->myBinaryTree[this->_root]->info))
		this->insertLeft(data,this->_root);
	else
		this->insertRight(data,this->_root);
}
template<class T>int ArrayBST<T>::search(T data){
	Node<T>*key=new Node<T>(new T(data),-1,-1); 
	int pos = this->_root;
	while(pos!=-1){
		if(this->myBinaryTree[pos]>key)
			pos=this->myBinaryTree[pos]->right;
		else if(this->myBinaryTree[pos]<key)
			pos=this->myBinaryTree[pos]->right;
		else if(this->myBinaryTree[pos]==key)
			break;
	}
	delete(key);
	return pos;
}

template<class T>void ArrayBST<T>::remove(T data){
	cout<<"remove function not implemented";
}

template<class T>ostream&operator<<(ostream&s,ArrayBST<T> &a){
	a.preOrder();
	a.postOrder();
	return s;
}

template<class T>void ArrayBST<T>::displayRaw(){
	cout<<"Displaying raw data";
	int pos = 0;
	for(vector<Node<int>*>::iterator it = this->myBinaryTree.begin();
					it!=this->myBinaryTree.end();++it){
		cout<<"Position "<<pos++<<"\t Data: "<<(*it)->info<<"\t Left child:"
			<<(*it)->left<<"\t Right child:"<<(*it)->right<<'\n';
	}
}