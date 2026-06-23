class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        for(auto &v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(auto &v:adj[u]){
                if(!vis[v]) dfs(v);
            }
        };
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};
