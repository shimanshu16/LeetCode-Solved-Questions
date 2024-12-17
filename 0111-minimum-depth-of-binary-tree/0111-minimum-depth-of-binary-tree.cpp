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
class Solution {
public:
   int reverse(TreeNode* root){
        if(!root) return INT_MAX-1;
        int leftHeight = reverse(root->left);
        int rightHeight = reverse(root->right);
        int result = 1+min(leftHeight,rightHeight);
        return (result==INT_MAX)? 1 : result;
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        else{
            int result = reverse(root);
            return result;
        } 
    }
};