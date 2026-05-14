class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;

        if(root == NULL){
            return levels;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size  = q.size();
            vector<int> currentLevel;
            for(int i = 0 ; i < size; i++){
                TreeNode* current = q.front();
                q.pop();
                currentLevel.push_back(current->val);

                if(current->left != NULL){
                    q.push(current->left);
                }
                
                if(current->right != NULL){
                    q.push(current->right);
                }
            }
            levels.push_back(currentLevel);
        }
        return levels;
    }
};
