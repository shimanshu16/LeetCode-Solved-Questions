class Solution {
public:
    int cnt = 0;
    
    int solve(TreeNode* root, long long targetSum) {
        return !root ? 0 : root->val == targetSum ? 1 + solve(root->left, targetSum - root->val) + solve(root->right, targetSum - root->val) : solve(root->left, targetSum - root->val) + solve(root->right, targetSum - root->val); 
    }

    int pathSum(TreeNode* root, int targetSum) {
        return !root ? 0 : (cnt += solve(root, targetSum), pathSum(root->left, targetSum), pathSum(root->right, targetSum), cnt);
    }
};