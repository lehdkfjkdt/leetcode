class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        std::unordered_set<int> search_set;
        for(int num: nums){
            search_set.insert(num);
        }
        int max_length =0;
        for(int num: search_set){
            if(search_set.find(num-1)==search_set.end()){
                int current_length=1;
                while(search_set.find(++num)!=search_set.end()){
                    ++current_length;
                }
                max_length=std::max(max_length,current_length);
            }
        }
        return max_length;
    }
};