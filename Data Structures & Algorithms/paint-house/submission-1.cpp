class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n+1,vector<int>(5,1e9));
        dp[n][0] = dp[n][1] = dp[n][2] = 0;
        for(int i = n-1; i >= 0; i--){
            for(int prev = 0; prev < 3; prev++){
                for(int col = 0; col < 3; col++){
                    if(col == prev) continue;
                    dp[i][prev] = min(dp[i][prev], dp[i+1][col]+costs[i][col]);
                }
            }
        }
        return min({dp[0][0], dp[0][1], dp[0][2]});
    }
};