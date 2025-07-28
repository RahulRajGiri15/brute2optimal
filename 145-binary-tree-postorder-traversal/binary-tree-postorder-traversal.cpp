/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// class Solution {
// public:
//     void postorder(TreeNode* root,vector<int>& result){
//         if(root == NULL) return ;
//         postorder(root->left, result);
//         postorder(root->right,result);
//         result.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//        vector<int>result;
//        postorder(root,result);
//        return result;
//     }
// };


///////////////iterativeapproach

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int>result;
       if(root == NULL)return result;
       stack<TreeNode*>st;
       st.push(root);
       while(!st.empty()){
        TreeNode* node = st.top();
        result.push_back(node->val);
        st.pop();
        if(node->left != NULL) st.push(node->left);
        if(node->right != NULL) st.push(node->right);
       }
       reverse(begin(result),end(result));
       return result;
    }
};
