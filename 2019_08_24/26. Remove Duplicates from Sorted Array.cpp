class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1) {
            return nums.size();
        }
        int last_index=1;
        int prevalue=nums[0];
        for(int index=1;index<nums.size();index++){
            if(nums[index]!=prevalue){
                prevalue=nums[index];
                nums[last_index++]=nums[index];
            }
        }
        nums.erase(nums.begin()+last_index,nums.end());
        return last_index;
    }
};