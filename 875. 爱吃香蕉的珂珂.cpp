class Solution {
    bool canEat(vector<int>& piles, int H, int k){
        int count=0;
        for(int i=0;i<piles.size();++i){
            count+=(piles[i]/k);
            count+=(piles[i]%k==0?0:1);
        }
        return count<=H;
    }
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int max_pile=0;
        for(int i=0;i<piles.size();++i){
            max_pile=max(max_pile,piles[i]);
        }
        int left=0;
        int right=max_pile;
        while(left<right){
            int mid=(left+right)/2;
            if(minEatingSpeed(piles,H,mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return right;
    }
};