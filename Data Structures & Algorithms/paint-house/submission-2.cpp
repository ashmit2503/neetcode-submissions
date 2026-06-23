class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> nxt(3), cur(3);
        for (int col = 0; col < 3; ++col) nxt[col] = costs[n-1][col];
        for (int i = n-2; i >= 0; --i) {
            for (int col = 0; col < 3; ++col)
                cur[col] = costs[i][col] + min(nxt[(col+1)%3], nxt[(col+2)%3]);
            nxt = cur;
        }
        return min({nxt[0], nxt[1], nxt[2]});
    }
};
