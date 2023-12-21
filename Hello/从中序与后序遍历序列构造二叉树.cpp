#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
