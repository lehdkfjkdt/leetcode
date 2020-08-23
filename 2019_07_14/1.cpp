class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ret=arr1;
        map<int,int> index_map;
        for(int index=0;index<arr2.size();index++){
            index_map[arr2[index]]=index;
        }
        sort(ret.begin(),ret.end(),[&index_map](int first,int second){
            const auto first_iter=index_map.find(first);
            const auto second_iter=index_map.find(second);
            if(first_iter!=index_map.end()&&second_iter!=index_map.end()){
                // The first and second both in arr2.
                return first_iter->second<second_iter->second;
            }else if(first_iter!=index_map.end()){
                // The second not in arr2.
                return true;
            }else if(second_iter!=index_map.end()){
                // The first not in arr2.
                return false;
            }else{
                // The first and second both not in arr2.
                return first<second;
            }
        });
       return ret;
    }
};