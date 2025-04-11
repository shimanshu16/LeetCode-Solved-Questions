class Solution {
public:
int total=0;
    int findTilt(TreeNode* root) {
      int x= solve(root);
       return total;
    }    
    int solve(TreeNode* root)
    {   
        if(!root)
        {   
         return 0;
        }
        int lt=solve(root->left);
        int rt=solve(root->right);
     
        int tilt;
        tilt=abs(lt-rt);
        total+=tilt;
        return root->val+lt+rt;
    }
};