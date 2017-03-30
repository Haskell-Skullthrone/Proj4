#pragma once
#include<vector>
#include<cstdlib>
#include<iostream>
#include<stack>
using namespace std;
template<class T>class Node{
	public:
	node();
	node(dt*info,int left, int right);
	node(node&n);
	private:
	int left,right;
	dt*info;
	friend ostream& operator<<(ostream&s,Node&n);
}
	