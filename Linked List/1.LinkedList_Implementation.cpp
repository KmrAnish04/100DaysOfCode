#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

int main(){

	Node* headNode = NULL;
	Node* firstNode = NULL;
	Node* secondNode = NULL;
	Node* thirdNode = NULL;

	headNode = new Node();
	firstNode = new Node();
	secondNode = new Node();
	thirdNode = new Node();

	headNode->link=firstNode;
	
	firstNode->data = 4;
	firstNode->link = secondNode;

	secondNode->data = 9;
	secondNode->link = thirdNode;

	thirdNode->data = 34;
	thirdNode->link = NULL;


	Node* tempNode = headNode->link;
	cout<<"tmp = "<<tempNode->link<<" "<<tempNode<<" "<<firstNode;
	while(tempNode != NULL){
		cout<<"The value: "<<tempNode->data<<endl;
		tempNode = tempNode->link;
	}

	return 0;
}