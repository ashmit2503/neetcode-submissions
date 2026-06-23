class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto &x:mp){
            if(x.second == 1) return -1;
            ans += x.second/3;
            x.second %= 3;
            if(x.second) ans++;
        }
        return ans;
    }
};