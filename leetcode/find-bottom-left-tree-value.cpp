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
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int ans=0;
        
        q.push(root);
        ans=root->val;
        while(!q.empty()){
            TreeNode* node=q.front();
            
            q.pop();
            if(node->right){
                q.push(node->right);
                ans=node->right->val;
            }
            if(node->left){
                q.push(node->left);
                ans=node->left->val;
            }
        }
        
        return ans;
    }
};