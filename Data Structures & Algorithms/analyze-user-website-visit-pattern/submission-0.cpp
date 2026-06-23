class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        vector<tuple<int,string,string>> v;
        for(int i = 0; i < n; i++){
            v.push_back({timestamp[i], username[i], website[i]});
        }
        sort(v.begin(), v.end());
        map<string,vector<string>> mp;
        for(auto &x:v){
            mp[get<1>(x)].push_back(get<2>(x));
        }
        map<vector<string>,int> mp2;
        for(auto &x:mp){
            vector<string> websites = x.second;
            int m = websites.size();
            if(m < 3) continue;
            for(int i = 0; i < m; i++){
                for(int j = i+1; j < m; j++){
                    for(int k = j+1; k < m; k++){
                        mp2[{websites[i], websites[j], websites[k]}]++;
                    }
                }
            }
        }
        set<vector<string>> st;
        int maxf = 0;
        for(auto &x:mp2){
            maxf = max(maxf, x.second);
        }
        for(auto &x:mp2){
            if(x.second == maxf) st.insert(x.first);
        }
        return *(st.begin());
    }
};