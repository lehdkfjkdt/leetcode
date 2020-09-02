class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> count;
        for(int number:nums1){
            if(count.find(number)!=count.end()){
                count[number]++;
            }else{
                count[number]=1;
            }
        }
        vector<int> ret;
        for(int number:nums2){
            if(count.find(number)!=count.end()&&count[number]>0){
                ret.push_back(number);
                count[number]--;
            }
        }
        return ret;
    }
};