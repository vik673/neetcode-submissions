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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> qt;
        qt.push(root);
        vector<int> vec;
        vector<vector<int>> result;
        while(!qt.empty())
        {
           
            int size = qt.size();
            for(int i=0;i<size;i++)
            { 
                TreeNode* curr = qt.front();
                
                qt.pop();
                if(i==size-1) vec.push_back(curr->val);

                if(curr->left) qt.push(curr->left);
                if(curr->right) qt.push(curr->right);

            }
           
        }
        return vec;
    }
};
