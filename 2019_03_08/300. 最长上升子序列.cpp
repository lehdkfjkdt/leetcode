class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        std::vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]){
                    dp[i]=std::max(dp[i],dp[j]+1);
                }
            }
        }
        int length=1;
        for(int i=0;i<dp.size();++i){
            length=std::max(length,dp[i]);
        }
        return length;
    }
};