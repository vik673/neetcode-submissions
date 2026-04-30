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
    int maxPathSum(TreeNode* root) {
       int maxi = INT_MIN;
       solve(root, maxi);
       return maxi;
    }

    int solve(TreeNode* node, int &maxi)
    {
        if(!node) return 0;

        int left = max(0, solve(node->left, maxi));
        int right = max(0, solve(node->right, maxi));

        // Case 1: 
        maxi = max(maxi, left+ right+ node->val);

        // Case 2: return one side of parent
        return node->val + max(left, right);
    }
};
