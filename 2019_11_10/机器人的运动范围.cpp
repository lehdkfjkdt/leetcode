class Solution {
    private:
    int count=0;
    vector<vector<int>> direction{{1,0},{0,1},{-1,0},{0,-1}};
    bool judge(int threshold,int row,int col){
        int t_count=0;
        while(row>0){
            t_count+=(row%10);
            row/=10;
        }
        while(col>0){
            t_count+=(col%10);
            col/=10;
        }
        return t_count<=threshold;
    }
    void Helper(int threshold,int rows,int cols,int cur_row,int cur_col,vector<vector<bool>>& visited){
        if(!judge(threshold,cur_row,cur_col)){
            return;
        }
        visited[cur_row][cur_col]=true;
        count++;
        for(int i=0;i<4;i++){
            int new_row=cur_row+direction[i][0];
            int new_col=cur_col+direction[i][1];
            if(new_row>=0&&new_row<rows&&new_col>=0&&new_col<cols&&!visited[new_row][new_col]){
                Helper(threshold,rows,cols,new_row,new_col,visited);
            }
        }
    }
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>>  visited(rows,vector<bool>(cols,false));
        Helper(threshold,rows,cols,0,0,visited);
        return count;    
    }
};