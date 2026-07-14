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
    int rob(TreeNode* root) {
        function<pair<int,int>(TreeNode*)> rec = [&](TreeNode* node)->pair<int,int>{
            if(!node) return {0,0};
            auto left = rec(node->left);
            auto right = rec(node->right);
            int nottake = max(left.first, left.second) + max(right.first, right.second);
            int take = node->val + left.first + right.first;
            return {nottake, take};
        };
        auto res = rec(root);
        return max(res.first, res.second);
    }
};