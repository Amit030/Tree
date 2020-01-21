//
//  Tree.hpp
//  DataStructureC++
//
//  Created by Amit Sharma on 22/12/19.
//  Copyright © 2019 McGreen Lts. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp
#include <vector>
#include <queue>
#include<map>
#include<iostream>
using namespace std;

class Tree {
private:
    struct _node{
        int data;
        _node *left;
        _node *right;
    }*head,*root;
    vector<int >ans;
    void insertIntoTree(_node* val,_node* nd);
    void inOrderTYraversal(_node* root);
    void postOrderTYraversal(_node* root);
    void preOrderTYraversal(_node* root);
	void verticalOrderTraversal(_node* root, map<int, vector<int>>&m, int val);
	void leftViewTraversla(_node* root, int &max_lvl, int lvl);
	void rightViewTraversla(_node* root, int &max_lvl, int lvl);
    
public:
    
    bool Insert(int data);
    bool find(int data);
    vector<int> inOrder();
    vector<int> postOrder();
    vector<int> preOrder();
    vector<int> lvlOrder();
	map<int, vector<int>> verticalOrder();
    vector<int> topView();
    vector<int> leftView();
    vector<int> rightView();
    vector<int> MirrorView();
};

#endif /* Tree_hpp */
