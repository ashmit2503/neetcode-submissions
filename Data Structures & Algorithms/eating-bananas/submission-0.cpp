class Solution {
private:
    bool check(vector<int> &arr, int n, long long k, int h){
        int temp = 0;
        for(int i = 0; i < n; i++){
            temp += arr[i]/k;
            if(arr[i]%k != 0) temp++;
        }
        return temp <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long lo = 1;
        long long hi = 1e18;
        long long ans = -1;
        while(lo <= hi){
            long long mid = lo + (hi-lo)/2;
            if(check(piles, n, mid, h)){
                hi = mid-1;
                ans = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
