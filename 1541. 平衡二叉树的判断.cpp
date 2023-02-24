// 1541. 平衡二叉树的判断.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}	
};

string prepare(string in)
// clearify the input, trasfer to a 01 combination
{
	if (in.size() == 0) return"";

	string c = "";
	for (int i = 0;i < in.size();i++)
	{
		if (in[i] != '#' and in[i] != ',')
		{
			c += "1";
			while (i + 1 < in.size() and in[i + 1] != ',') i++;
		}
		if (in[i] == '#')
		{
			c += '0';
			i++;
		}
	}
	return c;
}


int pos = -1;
TreeNode* create(string preOrder)
{
	pos++;
	char ch = preOrder[pos];
	TreeNode* T = nullptr;
	if (ch == '0') T = NULL;
	else
	{
		T = new TreeNode;
		T->val = ch;
		T->left = create(preOrder);
		T->right = create(preOrder);
	}
	return T;
}

int height(TreeNode* root) 
{
	if (root == NULL) 
	{
		return 0;
	}
	else
	{
		return max(height(root->left), height(root->right)) + 1;
	}
}

bool isBalanced(TreeNode* root) 
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
	}
}



int main()
{
	string in;
	cin >> in;
	string pre = prepare(in);
	TreeNode* root = create(pre);
	cout << isBalanced(root);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
