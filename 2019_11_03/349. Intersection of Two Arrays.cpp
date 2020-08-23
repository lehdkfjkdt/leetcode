class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(int i : nums1){
            s.insert(i);
        }
        set<int> ret;
        for(int i : nums2){
            if(s.find(i)!=s.end()){
                ret.insert(i);
            }
        }
        return vector<int>(ret.begin(),ret.end());
    }
};