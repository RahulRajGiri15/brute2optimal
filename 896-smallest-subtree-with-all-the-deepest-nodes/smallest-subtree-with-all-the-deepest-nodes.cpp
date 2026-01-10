class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If left subtree is deeper
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }
        // If right subtree is deeper
        if (right.first > left.first) {
            return {right.first + 1, right.second};
        }
        // Both sides have the same depth → current node is LCA
        return {left.first + 1, root};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
