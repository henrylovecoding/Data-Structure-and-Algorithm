// BSTtoList.cpp                                                    //
// ver 1.1                                                          //
// Language: standard C++                                           //
// Platform: Thinkpad E530, Windows 7, SP #1                        //
// Application: In-Order Traversal, Recursion, convert a BST into a //
//              Single-Linked list and double-linked list           //
// Author: Henry He       henrysyr03@gmail.com                      //
//////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



// covert BST to a single-linked list (in-order)
void BST2SingleLinkedList(TreeNode* &newhead, TreeNode* root, TreeNode* &prev)
{
	if (root == NULL)
		return;
	BST2SingleLinkedList(newhead, root->left, prev);
	if (newhead == NULL)
	{
		newhead = root;
		prev = root;
		return;
	}
	else
	{
		prev->right = root;
		prev->left = NULL; 
		prev = root;
	}
	
	BST2SingleLinkedList(newhead, root->right, prev);
	prev->left = NULL;

}


//convert BST to a double-linked list
void BST2DoubleLinkedList(TreeNode* &newhead, TreeNode* root, TreeNode* &prev)
{
	if (root == NULL)
		return;
	BST2DoubleLinkedList(newhead, root->left, prev);
	if (newhead == NULL)
	{
		newhead = root;
		prev = root;
		return;
	}
	else
	{
		prev->right = root;
		root->left = prev;
		prev = root;
	}
	BST2DoubleLinkedList(newhead, root->right, prev);

}




