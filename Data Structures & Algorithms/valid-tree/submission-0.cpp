class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n);
        function<bool(int, int)> dfs = [&](int node, int parent) -> bool {
            vis[node] = 1;
            for (int v : adj[node]) {
                if (v == parent) continue;
                if (vis[v]) return true;
                if (dfs(v, node)) return true;
            }
            return false;
        };
        if (dfs(0, -1)) return false;
        for (int i = 0; i < n; ++i) if (!vis[i]) return false;
        return true;
    }
};
