// f[k][j]表示到j天总共进行了k次交易 f[k][j]=max(f[k][j-1],price[j]-price[i]+f[k-1][i]) j>i>=0 
//                                  f[k][j]=max(f[k][j-1],price[j]+max(f[k-1][i]-price[i])) j>i>=0
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
            return 0;
        }
        int max_k=2;
        vector<vector<int>> f(max_k+1,vector<int>(prices.size()+1,0));
        for(int i=1;i<=max_k;i++){
            int temp_max=f[i-1][0]-prices[0];
            for(int j=1;j<prices.size();j++){
                f[i][j]=max(f[i][j-1],prices[j]+temp_max);
                temp_max=max(temp_max,f[i-1][j]-prices[j]);
            }
        }
        return  f[max_k][prices.size()-1];
    }
};