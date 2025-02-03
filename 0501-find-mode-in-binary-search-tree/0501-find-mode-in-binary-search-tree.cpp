class Solution {
public:
    void solve(TreeNode* root, int &maxi, int &count, int &val, vector<int> &ans) {
        if(!root) return;
        solve(root->left, maxi, count, val, ans);
        if(root->val == val) count++;
        else {
            val = root->val;
            count = 1;
        }
        if(count > maxi) {
            maxi = count;
            ans = {root->val};
        }
        else if(count == maxi) ans.push_back(root->val);

        solve(root->right, maxi, count, val, ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int maxi = 0, count = 0, val = root->val;

        solve(root, maxi, count, val, ans);

        return ans;
    }
};