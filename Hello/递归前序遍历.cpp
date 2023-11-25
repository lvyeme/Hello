#include <iostream>
#include <vector>

using namespace std;

//����������ڵ�ṹ
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    
public:
    //�����������ݹ�ر���������
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL)//����ǰ�ڵ�Ϊ�գ�ֱ�ӷ���
            return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);//�ݹ����������
        traversal(cur->right, vec);//������
    }
    //������������ǰ�����
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;//�洢�������������
        traversal(root, result);//ִ�еݹ������������洢��result��
        return result;
    }
};

int main() {
    Solution solu;

    // ����һ���򵥵Ķ�����
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // ִ��ǰ�������������
    vector<int> traversalResult = solu.preorderTraversal(root);
    cout << "ǰ����������" << endl;
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
//    // ����һ���򵥵Ķ�����
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//
//    // ������״�ṹ���ַ��������
//    string treeStructure = solu.printTree(root);
//    cout << "��״�ṹ��" << endl;
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
//    // ����һ���򵥵Ķ�����
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//
//    // ������״�ṹ���ַ��������
//    string treeStructure = solu.printTree(root);
//    cout << "��״�ṹ��" << endl;
//    cout << treeStructure;
//
//    return 0;
//}
