class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        std::vector<std::vector<std::pair<int,int>>> dp(n,vector<std::pair<int,int>>(n,{0,0}));
        for(int i=0;i<n;i++){
            dp[i][i].first=piles[i];
            dp[i][j].second=0;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                int left=piles[i]+dp[i+1][j].second;
                int right=piles[j]+dp[i][j-1].second;
                if(left>right){
                    dp[i][j].first=left;
                    dp[i][j].second=dp[i+1][j].first;
                }else{
                    dp[i][j].first=right;
                    dp[i][j].second=dp[i][j-1].first;
                }
            }
        }
        return dp[0][n-1].first>dp[0][n-1].second;
    }
};