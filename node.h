#pragma once
#include<vector>
#include<cstdlib>
#include<iostream>
#include<stack>
using namespace std;
template<class T>class Node{
	public:
	Node();
	Node(T info,int left, int right);
	Node(Node&n);
	int left,right;
	T info;
	friend ostream& operator<<(ostream&s,Node<T> const&n);
};

template<class T>ostream&operator<<(ostream&s,Node<T>const&n){
	s<<n.info<<'\n';
	return s;
}