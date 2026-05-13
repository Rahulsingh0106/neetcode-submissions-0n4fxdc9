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

    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int maxDepth = 0;

        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);

        maxDepth = 1 + max(leftDepth, rightDepth);
        return maxDepth;
    }
    int maxDepth(TreeNode* root) {
        int result = dfs(root);
        return result;
    }
};
