#pragma once
#include<vector>
#include<cstdlib>
#include<iostream>
#include<stack>
using namespace std;
template<class T>class Node{
	public:
	

	//empty constructor
	Node(){
		left = right = -1;
		info = NULL;
	}

	//initializer constructor
	Node(T *newinfo,int newleft, int newright){
		info = newinfo;
		left = newleft;
		right = newright;
	}

	//copy constructor
	Node(Node<T>const&n){
		info= n.info;
		left = n.left;
		right = n.right;
	}	
	//data fields
	int left,right;
	T*info;
	
	//oustput operators
	void displayRaw();
	friend ostream& operator<<(ostream&s,Node<T> const&n);
	
	//overloaded comparison operators for searching
	bool operator < (Node<T>n);
	bool operator > (Node<T>n);
	bool operator == (Node<T>n);
	bool operator <=(Node<T>n);
	bool operator >= (Node<T>n);
	bool operator != (Node<T>n);
};

//outputs a nicely formatted version of the data
template<class T>ostream&operator<<(ostream&s,Node<T>const&n){
	s<<n.info<<'\n';
	return s;
}

//outputs a raw version of the data, along with child locations
template<class T>void Node<T>::displayRaw(){
	cout<<*info<<left<<right;
}







