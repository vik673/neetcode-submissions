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
    bool BstHelper(TreeNode* root, int min, int max)
    {
        if(!root) return true;
        if(root->val < min || root->val > max) return false;
        return (root->val > min && root->val < max)
        && BstHelper(root->left, min, root->val) 
        && BstHelper(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        int min = INT_MIN, max = INT_MAX;
        return BstHelper(root, min, max);
    }
};
