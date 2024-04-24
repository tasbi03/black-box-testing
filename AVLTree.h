#ifndef AVLTREE_H
#define AVLTREE_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include "EmployeeInfo.h"

typedef struct node {
	EmployeeInfo empl;
	node* left;
	node* right;
	int height;
} node;

class AVL {
	node* root;

	void makeEmpty(node* t);
	node* insert(EmployeeInfo empl, node* t);
	node* singleRightRotate(node*& t);
	node* singleLeftRotate(node*& t);
	node* doubleLeftRotate(node*& t);
	node* doubleRightRotate(node*& t);
	node* findMin(node* t);
	node* findMax(node* t);
	node* remove(int sin, node* t);
	int height(node* t);
	int getSizeRecursive(node *t);
	int getBalance(node* t);
	void inorder(node* t);

public:
	AVL();
	void insert(EmployeeInfo empl);
	void remove(int sin);
	void display();
	node* GetRoot();
	node* Find(node* node, int sin);
	void clear();
	node* findMinPublic();
    node* findMaxPublic();
	int getSize();
	~AVL();
};

#endif // AVLTREE_H
