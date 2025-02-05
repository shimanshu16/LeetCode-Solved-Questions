class Solution {
public:
    void tt(TreeNode* root, int level, vector<vector<int>>&nums){
        if(root==NULL){
            return;
        }
        if(nums.size()<=level){
            nums.push_back({});
        }

        nums[level].push_back(root->val);

        tt(root->right,level+1,nums);
        tt(root->left,level+1,nums);

    }
    int findBottomLeftValue(TreeNode* root) {
       vector<vector<int>>nums;
        tt(root,0,nums);
        return nums.back().back();
    }
};