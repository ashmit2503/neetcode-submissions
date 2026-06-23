class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> indeg(26);
        for(int i = 1; i < n; i++){
            string s = words[i-1], t = words[i];
            bool ok = false;
            for(int j = 0; j < min(s.size(), t.size()); j++){
                if(s[j] != t[j]){
                    adj[s[j]-'a'].push_back(t[j]-'a');
                    indeg[t[j]-'a']++;
                    ok = true;
                    break;
                }
            }
            if(!ok && s.size() > t.size()) return "";
        }
        queue<int> q;
        for(int i = 0; i < 26; i++) if(!indeg[i])q.push(i);
        string ans;
        while(!q.empty()){
            auto x = q.front(); q.pop();
            ans += (x+'a');
            for(auto &v:adj[x]){
                indeg[v]--;
                if(!indeg[v]) q.push(v);
            }
        }
        if(ans.size() < 26) return "";
        return ans;
    }
};
