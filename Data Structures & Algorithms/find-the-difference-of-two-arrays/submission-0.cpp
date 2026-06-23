class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2);
        for(int i = 0; i < nums1.size(); i++){
            if(st2.find(nums1[i]) == st2.end()) {ans[0].push_back(nums1[i]); st2.insert(nums1[i]);}
        }
        for(int i = 0; i < nums2.size(); i++){
            if(st1.find(nums2[i]) == st1.end()) {ans[1].push_back(nums2[i]); st1.insert(nums2[i]);}
        }
        return ans;
    }
};