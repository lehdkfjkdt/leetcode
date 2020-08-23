class Solution {
private:
    // Return minimum counts to find not brokn floor using k eggs and total n floors.
    int MinEggDrop(int k,int n,vector<vector<int>>*mem){
        if(k==1){
            return n;
        }
        if(n==0){
            return 0;
        }
        if((*mem)[k][n]!=-1){
            return (*mem)[k][n];
        }
        int min_test_count=INT_MAX;
        int l=1;
        int r=n;
        while(l<=r){
            int mid=(l+r)/2;
            int not_brokn=MinEggDrop(k,n-mid,mem)+1;
            int brokn=MinEggDrop(k-1,mid-1,mem)+1;
            if(not_brokn>brokn){
                l=mid+1;
                min_test_count=min(min_test_count,not_brokn);
            }else{
               r=mid-1;
                min_test_count=min(min_test_count,brokn);
            }
        }   
        (*mem)[k][n]=min_test_count;
        return min_test_count;
    }
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> mem(K+1,vector<int>(N+1,-1));
        return MinEggDrop(K,N,&mem);
    }
};