class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(nums[i]>nums[j] && dp[j]+1 >dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        for (int i = 0; i < dp.size(); i++)
        {
            if(dp[i]>ans){
                ans = dp[i];
            }
        }
        return ans;
        
    }
};