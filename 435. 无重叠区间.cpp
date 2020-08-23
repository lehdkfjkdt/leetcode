class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& l,const vector<int>& r){
            return l[1]<r[1];
        });
        int end=INT_MIN;
        int count=0;
        for(int i=0;i<intervals.size();++i){
            if(intervals[i][0]>=end){
                count++;
                end=intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
};