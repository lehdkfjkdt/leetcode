class Solution {
public:
 vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()){
            swap(nums1,nums2);
        }
        unordered_set<int> s;
        for(int i : nums1){
            s.insert(i);
        }
        vector<int> ret;
        for(int i : nums2){
            if(s.find(i)!=s.end()){
                ret.push_back(i);
            }
        }
        return ret;
    }
};