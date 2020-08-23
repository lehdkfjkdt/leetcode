class Solution {
    int dp(int start, int end, const vector<int>& nums){
        int dp_0=0;
        int dp_1=nums[start];
        for(int i= start+1;i<=end;++i){
            int temp=dp_0;
            dp_0=max(dp_0,dp_1);
            dp_1=temp+nums[i];
        }
        return max(dp_0,dp_1);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }else if(nums.size()==1){
            return nums[0];
        }
        return max(dp(0,nums.size()-2,nums),dp(1,nums.size()-1,nums));
    }
};