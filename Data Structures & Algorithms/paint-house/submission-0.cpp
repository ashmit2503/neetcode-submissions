class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n,vector<int>(5,-1));
        function<int(int, int)> rec = [&](int i, int prev){
            if(i == n) return 0;
            if(dp[i][prev] != -1) return dp[i][prev];
            int ans = 1e9;
            for(int col = 0; col < 3; col++){
                if(col == prev) continue;
                ans = min(ans, rec(i+1,col)+costs[i][col]);
            }
            return dp[i][prev] = ans;
        };
        return rec(0,4);
    }
};