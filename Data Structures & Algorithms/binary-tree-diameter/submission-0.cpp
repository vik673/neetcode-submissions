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
    int res =0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res =0;
        diameterHelper(root, res);
        return res-1;
    }

    int diameterHelper(TreeNode* root, int &res)
    {
        if(!root) return 0;
        int lh = diameterHelper(root->left, res);
        int rh = diameterHelper(root->right, res);
        res = max(res, lh+rh+1);
        return 1+max(diameterHelper(root->left, res), 
        diameterHelper(root->right, res));
    }
};
