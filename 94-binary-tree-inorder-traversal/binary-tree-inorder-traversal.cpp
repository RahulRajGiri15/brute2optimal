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
//     void inorder(TreeNode* root,vector<int>& result){
//         if(root == NULL) return ;
//         inorder(root->left, result);
//         result.push_back(root->val);
//         inorder(root->right,result);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//        vector<int>result;
//        inorder(root,result);
//        return result;
//     }
// };

///t-o(n)--it visits every element once
///s- best--balnced tree --height-- log(n) recursive call stack + o(n)--vector
///s-worst--balanced tree -- o(n)+o(n)=o(n)///height is n;

////////////Morris Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int>result;
       TreeNode* curr = root;
       while(curr != NULL){
        if(curr->left == NULL){ ///L V R
            result.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* leftchild = curr->left;

            while(leftchild->right != NULL){
                leftchild = leftchild->right;
            }
            leftchild->right = curr;
            ////now set your curr left to NULL
            TreeNode* temp = curr;
            curr = curr->left;
            temp->left= NULL;
        }
       }
       return result;
    }
};

