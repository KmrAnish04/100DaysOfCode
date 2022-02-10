#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct BSTNode{
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};


void insertNode(BSTNode *root, int value){
    
    if(value<root->data){
        if(root->left==NULL){
            root->left = new BSTNode(value);
        }
        else insertNode(root->left, value);
    }
    else if(value>root->data){
        if(root->right==NULL){
            root->right=new BSTNode(value);
        }
        else insertNode(root->right, value);
    }
}

// void printTree(BSTNode *root){
//     int level=0;
//     cout<<"Root: "<<root->data<<endl;
    
//     if(root->left!=NULL){
//         cout<<\t"Left Child: "<<root->left->data<<endl;
//     }
//     else{
//         cout<<\t"Left Child: NULL"<<endl;
//     }

//     if(root->right!=NULL){
//         cout<<\t"right Child: "<<root->right->data<<endl;
//     }
//     else{
//         cout<<\t"Right Child: NULL"<<endl;
//     }

// }

int main(){

    BSTNode *root = new BSTNode(20);
    insertNode(root, 50);
    insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 60);
    insertNode(root, 11);
    cout<<"root: "<<root->data<<endl;
    cout<<"root's left child: "<<root->left->data<<endl;
    cout<<"root's left child: "<<root->left->left->data<<endl;
    cout<<"root's left child: "<<root->left->right->data<<endl;
    cout<<"root's right child: "<<root->right->data<<endl;
    cout<<"root's right child: "<<root->right->right->data<<endl;
    return 0;
}