#pragma once
#include<vector>
#include<cstdlib>
#include<iostream>
#include<stack>
using namespace std;
template<class T>class Node{
	public:
	Node();
	Node(T*info,int left, int right);
	Node(Node&n);
	private:
	int left,right;
	T*info;
	friend ostream& operator<<(ostream&s,Node<T>&n);
};
	