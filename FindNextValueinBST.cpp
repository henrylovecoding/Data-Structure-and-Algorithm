// FindNextValueinBST.cpp                                        //
// ver 1.1                                                       //
// Language: standard C++                                        //
// Platform: Thinkpad E530, Windows 7, SP #1                     //
// Application: Method to find the next value of the node in a   //
//              BST, using a traditional way and a in-order      //
//              traversal way                                    //
// Author: Henry He      henrysyr03@gmail.com                    //
///////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool flag = false;

// version 1 : the normal way illustrate the way as it is, but a little complex
void findnextvalue(TreeNode* root, int value, int &answer, TreeNode* &prev, TreeNode* truenode)
{
	if (answer != INT_MIN)
	{
		return ;
	}
	if (root == NULL)
		return; 
	findnextvalue(root->left, value, answer, prev, truenode);
	if (prev != NULL)
	{
		if (root->right == prev)
		{
			prev = root;
			return;
		}
		else if (root->left == prev)
		{
			answer = root->val;
			return;
		}
	}
	if (root->val == value)
	{
		if (root->right != NULL)  // it has right child, then find the leftmost node of the right child
		{
			root = root->right;
			while (root->left != NULL)
				root = root->left;
			answer = root->val;
			return;
		}
		else  //if, it doesn't have right child, it means need back tracking
		{
			if (prev == NULL)
			prev = root;
			return;
		}
	}
	findnextvalue(root->right, value, answer, prev, truenode);
	if (prev != NULL)
	{
		if (root->right == prev)
		{
			prev = root;
			if (prev == truenode)
			{
				answer = INT_MAX;
			}
			return;
		}
		else if (root->left == prev)
		{
			answer = root->val;
			return;
		}
	}
}
//version 2: in-order traversal
void helper(TreeNode* root, int target, int &prev, int &next)
{
	if (next != INT_MIN)
		return;
	if (root == NULL)
	{
		return;
	}
	if (root->left)
		helper(root->left, target, prev, next);
	if (flag == true)
	{
		next = root->val;
		flag = false;
		return;
	}
	prev = root->val;
	if (prev == target)
		flag = true;
	if (root->right)
		helper(root->right, target, prev, next);


}

