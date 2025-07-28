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
//     void preorder(TreeNode* root, vector<int>& result){
//         if(root == NULL) return ;
//         result.push_back(root->val);
//         preorder(root->left,result);
//         preorder(root->right,result);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>result;
//         preorder(root,result);
//         return result;
//     }
// };

////t-o(n)---we visit every element once
////s-o(n)+o(n) -- o(n)--for vector | o(n)--recursive call stack --for best case o(logn)
///

/////////////////

class Solution {
public:
     vector<int> preorderTraversal(TreeNode* root) {
       vector<int>result;
       if(root == NULL)return result;
       stack<TreeNode*>st;
       st.push(root);
       while(!st.empty()){
        TreeNode* node = st.top();
        result.push_back(node->val);
        st.pop();
        if(node->right != NULL) st.push(node->right);
        if(node->left != NULL) st.push(node->left);
       
       }
       return result;
    }
};
