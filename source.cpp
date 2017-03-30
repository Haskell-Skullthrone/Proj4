#include<iostream>
#include<vector>
#include<cstdlib>
#include<stack>
#include "node.h"
#include "ArrayBT.h"
#include "ArrayBST.h"
using namespace std;
int main(){
	string input;
	cin>>input;
	ArrayBST<int>tree=*new ArrayBST<int>(atoi(input));
	while(!cin.eof()){
		char command;
		cin>>command;
		cin>>input;
		switch(command){
			case 'I':
			tree.insert(atoi(input));
			break;
			case 'R':
			tree.remove(atoi(input));
			break;
			case 'F';
			cout<<tree.search(atoi(input));
			break;
			case'O';
			cout<<tree;
			break;
			case 'A';
			tree.displayRaw();
			break;
			default:
			cout<<"ERROR: INPUT NOT RECOGNIZED"
			return 1;
			break;
		
		}
	}
	return 0;
}
			