class Solution {
private:
    int coinHelper(vector<int>& coins, int amount, vector<int>* dp){
        if(amount==0){
            (*dp)[0]=0;
            return 0;
        }else if(amount<0){
            return -1;
        }else{
            if((*dp)[amount]!=INT_MAX){
                return (*dp)[amount];
            }
            for(int coin: coins){
                int res=coinHelper(coins,amount-coin,dp);
                if(res!=-1){
                    (*dp)[amount]=min((*dp)[amount],res+1);
                }
            }
            if((*dp)[amount]==INT_MAX){
                (*dp)[amount]=-1;
            }
            return (*dp)[amount];
            
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        return coinHelper(coins,amount,&dp);
    }
};