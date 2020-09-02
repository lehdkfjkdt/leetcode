class Solution {
    private:
    const vector<int> & nums_;
public:
    Solution(vector<int>& nums):nums_(nums) {

    }
    
    int pick(int target) {
        int i=1;
        int ret=-1;
        for(int index=0;index<nums_.size();++index){
            if(nums_[index]==target){
                if(rand()%i==0){
                    ret=index;
                }
                i++;
            }
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */