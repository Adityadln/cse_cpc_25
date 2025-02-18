using ll = long long;
class Solution {    
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        ll ans = 0;
        for(int i = 0;i < n;i++){
            mpp[nums[i] - i]++;
        }
        for(auto it : mpp){
            int val = it.second;
            ans += 1LL*val*(val-1)/2;
        }
        return 1LL*(n - 1)*(n)/2 - ans;
    }
};