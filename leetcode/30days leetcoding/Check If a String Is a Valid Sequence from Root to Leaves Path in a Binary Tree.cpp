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
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        queue<pair<TreeNode*, int>> q;
        int ind=0, count=1, n=arr.size();
        
        if(!n || arr[ind]!=root->val){
            return false;
        }
        
        q.push({root, 1});
        while(!q.empty()){
            pair<TreeNode*, int> curr=q.front();
            
            if(curr.second==n){
                if(!curr.first->left && !curr.first->right) return true;
                else return false;
            }
            
            q.pop();
            
            if(curr.first->left && curr.first->left->val==arr[curr.second]){
                q.push({curr.first->left, curr.second+1});
            }
            if(curr.first->right && curr.first->right->val==arr[curr.second]){
                q.push({curr.first->right, curr.second+1});
            }
        }
        
        return false;
    }
};