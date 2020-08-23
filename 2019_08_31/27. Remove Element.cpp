class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last_index=0;
        for(int index=0;index<nums.size();++index){
            if(nums[index]==val)continue;
            nums[last_index++]=nums[index];
        }
        return last_index;
    }
};