#include <vector>
using namespace std;

class Solution {
    vector<int> ans;
    void inorderTraversalHelp(TreeNode* node) {
        if (node==nullptr) return;
        inorderTraversalHelp(node->left);
        ans.push_back(node->val);
        inorderTraversalHelp(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversalHelp(root);
        return ans;
    }
};
