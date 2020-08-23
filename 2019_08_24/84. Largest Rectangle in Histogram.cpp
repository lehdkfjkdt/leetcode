class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        vector<int> left(heights.size(),-1);
        vector<int> right(heights.size(),heights.size());
        for(int i=1;i<heights.size();i++){
            int p=i-1;
            while(p>=0&&heights[p]>=heights[i]){
                p=left[p];
            }
            left[i]=p;
        }
        for(int i=heights.size()-2;i>=0;i--){
            int p=i+1;
            while(p<heights.size()&&heights[p]>=heights[i]){
                p=right[p];
            }
            right[i]=p;
        }
        int max_area=0;
        for(int i=0;i<heights.size();i++){
            max_area=max(max_area,heights[i]*(right[i]-left[i]-1));
        }
        return max_area;
    }
};