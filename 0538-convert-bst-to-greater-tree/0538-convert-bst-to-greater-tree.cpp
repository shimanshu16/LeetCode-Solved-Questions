class Solution {
public:
    void dfsIn(TreeNode *root, stack<TreeNode *> &st){
        if(root==NULL)
            return;
        dfsIn(root->left,st);
        st.push(root);
        dfsIn(root->right,st);
    }
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode *> st;
        dfsIn(root,st);
        int sum=0;
        while(!st.empty()){
            TreeNode* p=st.top();
            st.pop();
            sum+=p->val;
            p->val=sum;
        }
        return root;
    }
};