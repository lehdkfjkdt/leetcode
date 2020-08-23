class Solution {
public:
    int minSteps(int n) {
        if(n==1||n==0){
            return 0;
        }
        if(n==2){
            return 2;
        }
        vector<int> dp(n+1,1);
        for(int i=2;i<=n;++i){
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],dp[i]+dp[j-1]*(i-j+1));
            }
            if(dp[i]==n){
                return i;
            }
        }
        return -1;
    }
};