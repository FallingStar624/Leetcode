#include <vector>
using namespace std;


 /* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    vector<vector<int>> ans;
    void levelOrderHelp(TreeNode* node, int level) {
        if (node == nullptr) return;
        if (ans.size() >= level) {
            ans[level-1].push_back(node->val);
            if (node->left != nullptr) levelOrderHelp(node->left, level+1);
            if (node->right != nullptr) levelOrderHelp(node->right, level+1);
        } else {
            vector<int> newLevel = {node->val};
            ans.push_back(newLevel);
            if (node->left != nullptr) levelOrderHelp(node->left, level+1);
            if (node->right != nullptr) levelOrderHelp(node->right, level+1);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrderHelp(root, 1);
        return ans;
    }
};
