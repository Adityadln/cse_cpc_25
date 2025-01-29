class Solution {
    bool solve(int step,vector<int>&nums,vector<int>&dp){
        int n = nums.size();
        if(dp[step] != -1)return dp[step];
        if(step == n - 1)return true;
        int val = nums[step];
        for(int i = 1;i <= val;i++){
            if(step + i >= n)continue;
            if(solve(step + i,nums,dp) == 1)return dp[step] = 1;
        }
        return dp[step] = 0;

    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return (solve(0,nums,dp) == 1);
    }
};