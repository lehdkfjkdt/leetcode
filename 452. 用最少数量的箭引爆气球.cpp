class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>& l, const vector<int>& r){
            return l[1]<r[1];
        });
        if(!points.size()){
            return points.size();
        }
        int end=points[0][1];
        int count=1;
        for(int i=1;i<points.size();++i){
            if(points[i][0]>end){
                count++;
                end=points[i][1];
            }
        }
        return count;
    }
};