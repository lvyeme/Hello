#include <iostream>
#include <vector>

using namespace std;

//定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    
public:
    //辅助函数，递归地遍历二叉树
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL)//若当前节点为空，直接返回
            return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);//递归遍历左子树
        traversal(cur->right, vec);//右子树
    }
    //主函数，进行前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;//存储遍历结果的向量
        traversal(root, result);//执行递归遍历，将结果存储在result中
        return result;
    }
};

int main() {
    Solution solu;

    // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 执行前序遍历并输出结果
    vector<int> traversalResult = solu.preorderTraversal(root);
    cout << "前序遍历结果：" << endl;
    for (int val : traversalResult) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//class Solution {
//public:
//    string printTree(TreeNode* root) {
//        if (root == nullptr) return "";
//
//        string res = "";
//        printTreeHelper(root, 0, res);
//        return res;
//    }
//
//private:
//    void printTreeHelper(TreeNode* node, int depth, string& res) {
//        if (node == nullptr) return;
//
//        res += string(depth * 4, ' ') + to_string(node->val) + "\n";
//        printTreeHelper(node->left, depth + 1, res);
//        printTreeHelper(node->right, depth + 1, res);
//    }
//};
//
//int main() {
//    Solution solu;
//
//    // 创建一个简单的二叉树
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//
//    // 生成树状结构的字符串并输出
//    string treeStructure = solu.printTree(root);
//    cout << "树状结构：" << endl;
//    cout << treeStructure;
//
//    return 0;
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};
//
//class Solution {
//public:
//    string printTree(TreeNode* root) {
//        if (root == nullptr) return "";
//
//        string res = "";
//        printTreeHelper(root, 0, res);
//        return res;
//    }
//
//private:
//    void printTreeHelper(TreeNode* node, int depth, string& res) {
//        if (node == nullptr) return;
//
//        res += string(depth * 4, ' ') + to_string(node->val) + "\n";
//        printTreeHelper(node->left, depth + 1, res);
//        printTreeHelper(node->right, depth + 1, res);
//    }
//};
//
//int main() {
//    Solution solu;
//
//    // 创建一个简单的二叉树
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//
//    // 生成树状结构的字符串并输出
//    string treeStructure = solu.printTree(root);
//    cout << "树状结构：" << endl;
//    cout << treeStructure;
//
//    return 0;
//}
