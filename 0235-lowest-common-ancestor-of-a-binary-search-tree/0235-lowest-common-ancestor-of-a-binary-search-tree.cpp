/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool rootToNodePath(TreeNode* root, TreeNode* n, vector<TreeNode*> &path) {
        if (root == NULL) {
            return false;
        }
        path.push_back(root);
        if (root == n) {
            return true;
        }
        if (rootToNodePath(root->left, n, path) || rootToNodePath(root->right, n, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        rootToNodePath(root, p, path1);
        rootToNodePath(root, q, path2);

        TreeNode* lca = nullptr;
        for (int i = 0; i < path1.size() && i < path2.size(); i++) {
            if (path1[i] != path2[i]) {
                break;
            }
            lca = path1[i];
        }
        return lca;
    }
};