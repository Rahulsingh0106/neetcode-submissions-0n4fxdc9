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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

private:
bool dfs(TreeNode* root, long minValue, long maxValue){
    if(root == NULL){
        return true;
    }

    if(root->val <= minValue || root->val >= maxValue){
        return false;
    }

    bool leftValid = dfs(root->left, minValue, root->val);
    bool rightValid = dfs(root->right, root->val, maxValue);

    return leftValid && rightValid;
}
};
