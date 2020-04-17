#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    
    int _max=0;

    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int a=solve(root->left);
        int b=solve(root->right);
        
        _max=max(_max, a+b);
        
        return max(a,b)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root){
        solve(root);
        
        return _max;
    }
};

int main(){


    return 0;
}
