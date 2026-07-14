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
        map<pair<TreeNode*,int>, int> dp;
        function<int(TreeNode*, int)> rec = [&](TreeNode* node, int prev){
            if(!node) return 0;
            if(dp.find({node, prev}) != dp.end()) return dp[{node,prev}];
            int ans = rec(node->left, 0) + rec(node->right, 0);
            if(prev == 0) ans = max(ans, rec(node->left, 1)+rec(node->right, 1)+node->val);
            return dp[{node, prev}] = ans;
        };
        return rec(root,0);
    }
};