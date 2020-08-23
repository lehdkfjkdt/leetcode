class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> num_to_count;
        for(int num : nums){
            num_to_count[num]++;
        }
        priority_queue<pair<int,int>> heap;
        vector<int> ret;
        for(auto& val: num_to_count){
            heap.push(make_pair(val.second,val.first));
            if(heap.size()>num_to_count.size()-k){
                ret.push_back(heap.top().second);
                heap.pop();
            }
        }
        return ret;
    }
};