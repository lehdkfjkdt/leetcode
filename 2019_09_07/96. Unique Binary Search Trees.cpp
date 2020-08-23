class Solution {
public:
    int numTrees(int n) {
        std::vector<int> nums(n+1,0);
        nums[0]=nums[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                nums[i]+=nums[j-1]*nums[i-j];
            }
        }
        return nums[n];                                                                                             
    }
};