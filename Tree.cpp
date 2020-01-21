//
//  Tree.cpp
//  DataStructureC++
//
//  Created by Amit Sharma on 22/12/19.
//  Copyright © 2019 McGreen Lts. All rights reserved.
//

#include "Tree.h"
bool  Tree :: Insert(int _data){
    //create a node firsr
    
    _node *node = new _node();
    node->data=_data;
    node->left= nullptr;
    node->right= nullptr;
    
    //check if tree is empty
    if(root == nullptr){
        root= node;
        head = node;
        return true;
    }
    else{//traverse for the poisition
       insertIntoTree(node, root);
    }
    root= head;
    return true;
}
bool Tree :: find(int data){
    return  true;
    
}

void Tree:: insertIntoTree(_node* newNode, _node *root){
    
    //equal case
    if(root->data == newNode->data) return;
    
    
    if(root->data > newNode->data){
        if(root->left != nullptr)
        insertIntoTree(newNode,root->left);
        else
        root->left = newNode;
        
    }
       
    else{
        if(root->right != nullptr)
         insertIntoTree(newNode,root->right);
        else
            root->right = newNode;
    }
    
}
vector<int> Tree :: inOrder(){
    ans.clear();
    inOrderTYraversal(root);
    return ans;
    
}

vector<int> Tree :: postOrder(){
    ans.clear();
      postOrderTYraversal(root);
      return ans;
}
vector<int>  Tree ::preOrder(){
    ans.clear();
      preOrderTYraversal(root);
      return ans;
}

void Tree :: inOrderTYraversal(_node* root){
    if(root==nullptr)
        return;
    inOrderTYraversal(root->left);
    ans.push_back(root->data);
    inOrderTYraversal(root->right);
    return;
}

void Tree :: postOrderTYraversal(_node* root){
    if(root==nullptr)
        return;
    inOrderTYraversal(root->left);
    inOrderTYraversal(root->right);
    ans.push_back(root->data);
    return;
}


void Tree :: preOrderTYraversal(_node* root){
    if(root==nullptr)
        return;
    ans.push_back(root->data);
    inOrderTYraversal(root->left);
    inOrderTYraversal(root->right);
    return;
}

void Tree::verticalOrderTraversal(_node * root, map<int, vector<int>>& m, int val)
{
	if (root == nullptr) return;

	m[val].push_back(root->data);
	verticalOrderTraversal(root->left, m, val - 1);
	verticalOrderTraversal(root->right, m, val + 1);

}

void Tree::leftViewTraversla(_node * root, int & max_lvl, int lvl)
{
	if (root == nullptr) return;

	if (max_lvl < lvl) {
		ans.push_back(root->data);
		cout << root->data << " ";
		max_lvl = lvl;
	}
	leftViewTraversla(root->left, max_lvl, lvl + 1);
	leftViewTraversla(root->right, max_lvl, lvl + 1);
}

void Tree::rightViewTraversla(_node * root, int & max_lvl, int lvl)
{
	if (root == nullptr) return;

	if (max_lvl < lvl) {
		ans.push_back(root->data);
		cout << root->data << " ";
		max_lvl = lvl;
	}
	leftViewTraversla(root->right, max_lvl, lvl + 1);
	leftViewTraversla(root->left, max_lvl, lvl + 1);

}

vector<int>  Tree ::  lvlOrder(){
    ans.clear();
    if(root == nullptr)return ans;
    queue<_node *>q;
    q.push(root);
    while (!q.empty()) {
        _node* temp = q.front();
        ans.push_back(temp->data);
        if(temp->left != nullptr)
            q.push(temp->left);
        if(temp->right != nullptr)
            q.push(temp->right);
        q.pop();
    }
    return ans;
}

map<int, vector<int>> Tree::verticalOrder()
{
	map<int, vector<int>>vmap;
	verticalOrderTraversal(root,vmap, 0);
	return vmap;
}

vector<int> Tree ::leftView(){ 
	ans.clear();
	int max = 0;
	leftViewTraversla(root, max, 1);
	return ans;
}

vector<int> Tree ::rightView(){
	ans.clear();
	int max = 0;
	rightViewTraversla(root, max, 1);
	return ans;

}
vector<int> Tree ::MirrorView(){ return ans;}
vector<int> Tree::topView() { return ans; }

