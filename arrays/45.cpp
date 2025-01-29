
class Solution {
    int MAX = 1e5;
    int solve(int step,vector<int>&nums,vector<int>&dp){
        int n = nums.size();
        if(dp[step] != MAX)return dp[step];
        if(step == n - 1)return 0;
        int val = nums[step];
        for(int i = 1;i <= val;i++){
            if(step + i >= n)break;
            dp[step] = min(dp[step],1 + solve(step + i,nums,dp));
        }
        return dp[step];
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,MAX);
        return solve(0,nums,dp);
    }
};