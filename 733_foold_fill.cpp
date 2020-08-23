class Solution {
        vector<int> dirs{1,-1};
        private:
        void helper(vector<vector<int>>& image,vector<vector<bool>>& mem,int r,int c,int newColor,int Color,int n,int m){
            if(mem[r][c]){
                return;
            }
            if(image[r][c]==Color){
                mem[r][c]=true;
                image[r][c]=newColor;
            }else
            {
                mem[r][c]=true;
                return;
            }
            for(auto dir:dirs){
                int new_r=r+dir;
                int new_c=c;
                if(new_r>=0&&new_r<n&&new_c>=0&&new_c<m){
                    helper(image,mem,new_r,new_c,newColor,Color,n,m);
                }
                new_r=r;
                new_c=c+dir;
                if(new_r>=0&&new_r<n&&new_c>=0&&new_c<m){
                    helper(image,mem,new_r,new_c,newColor,Color,n,m);
                }
            }
        }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> mem(n,vector<bool>(m,false));
        helper(image,mem,sr,sc,newColor,image[sr][sc],n,m);
        return image;
    }
};