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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
        vector<vector<int>> zigzagList;
        if (root == NULL) return zigzagList;

        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);

        bool leftToRight = true;

        while (!pendingNodes.empty()) {
            int levelSize = pendingNodes.size();
            
            vector<int> levelNodeData(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* frontNode = pendingNodes.front();
                pendingNodes.pop();

                if (leftToRight) {
                    levelNodeData[i] = frontNode->val;
                } 
                else {
                    levelNodeData[levelSize - i - 1] = frontNode->val;
                }

                if (frontNode->left != NULL) pendingNodes.push(frontNode->left);
                if (frontNode->right != NULL) pendingNodes.push(frontNode->right);
            }

            zigzagList.push_back(levelNodeData);

            leftToRight = !leftToRight;
        }

        return zigzagList;
    }
};