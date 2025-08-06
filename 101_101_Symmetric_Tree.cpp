// https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true; // both are null
        if (!left || !right) return false; // one is null
        if (left->val != right->val) return false;

        // Check outer and inner mirror nodes
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};
