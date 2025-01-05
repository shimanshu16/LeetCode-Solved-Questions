class Solution {
public:

    int solve(TreeNode *curr, bool canBePicked, unordered_map<TreeNode*, unordered_map<bool,int>> &dp) {
        if(!curr) return 0;
        if(dp[curr][canBePicked]) return dp[curr][canBePicked];

        dp[curr][canBePicked] = solve(curr->left, true, dp) + solve(curr->right, true, dp);
        if(canBePicked) dp[curr][canBePicked] = max({ dp[curr][canBePicked],
                                                      curr->val + solve(curr->left, false, dp) + solve(curr->right, false, dp)});
        
        return dp[curr][canBePicked];
    }

    int rob(TreeNode* root) {
       if(!root) return 0; 
       unordered_map<TreeNode*, unordered_map<bool,int>> dp;
       return solve(root, true, dp);
    }
};