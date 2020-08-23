class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> l_height(height.size(),0);
        vector<int> r_height(height.size(),0);
        int max_height=0;
        for(int i=0;i<height.size();++i){
            l_height[i]=max_height;
            max_height=max(max_height,height[i]);
        }
        max_height=0;
        for(int i=height.size()-1;i>=0;i--){
            r_height[i]=max_height;
            max_height=max(max_height,height[i]);
        }
        int trap=0;
        for(int i=0;i<height.size();i++){
            trap+=max(0,min(l_height[i],r_height[i])-height[i]);
        }
        return trap;
    }
};