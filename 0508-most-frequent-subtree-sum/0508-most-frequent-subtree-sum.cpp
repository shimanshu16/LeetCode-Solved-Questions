class Solution {
public:

    int postorder(TreeNode* root, unordered_map<int, int>& m) {
        
        if(root == NULL) return 0;

        int cnt1 = postorder(root -> left, m);
        int cnt2 = postorder(root -> right, m);
  
        int sum = root -> val + cnt1 + cnt2;
        m[sum]++;
 
       return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
      
       vector<int> ans;
       unordered_map<int, int> m;
      
       int sum = postorder(root, m);
 
       int maxi = 0;
       for(auto itr : m) {
        maxi = max(maxi, itr.second);
       }      

       for(auto itr : m) {
          if(itr.second == maxi) ans.push_back(itr.first);
       }
 
       return ans;
     }
};