// https://leetcode.com/problems/binary-tree-right-side-view/submissions/1724518506/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* rightMostNode = nullptr;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Keep updating the rightMostNode
                rightMostNode = node;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // After the level, add the rightmost node's value
            if (rightMostNode) result.push_back(rightMostNode->val);
        }

        return result;
    }
};
