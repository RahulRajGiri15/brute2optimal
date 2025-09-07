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
//     vector<int> rightSideView(TreeNode* root) {
//         if(root == NULL) return {};
//         queue<TreeNode*>que;
//         vector<int>ans;
//         que.push(root);
//         while(!que.empty()){
//             int n = que.size();
//             TreeNode* node = NULL;

//             while(n--){
//                 node = que.front();
//                 que.pop();

//                 if(node->left != NULL){
//                     que.push(node->left);
//                 }
//                 if(node->right != NULL){
//                     que.push(node->right);
//                 } 
//             }
//             ans.push_back(node->val); ///last node at each level is right node only
//         }
//         return ans;
//     }
// };

///////////////////////

class Solution {
public:
    void preorder(TreeNode* root , int level , vector<int>&res){
        if(root == NULL){
            return ;
        }
        if(res.size() < level){
            res.push_back(root->val);
        }
        preorder(root->right,level+1,res);
        preorder(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        preorder(root,1,res);
        return res;
    }
};