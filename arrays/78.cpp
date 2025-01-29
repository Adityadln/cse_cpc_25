class Solution {
    vector<int> solve(int num,vector<int>&nums){
        vector<int>res;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(((1 << i) & num) != 0)res.push_back(nums[i]);
        }
        return res;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i = 0;i < pow(2,n);i++){
            ans.push_back(solve(i,nums));
        }
        return ans;
    }
};