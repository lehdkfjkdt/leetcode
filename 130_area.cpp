#include <vector>
#include <utility>

using namespace std;


class Solution {
private:
    vector<int> directions{1,-1};
    void dfs(const vector<vector<char>>& board,const int r_limit,const int c_limit,int r,int c,vector<std::pair<int,int>>& zero_pos,vector<vector<bool>>& mem){
        if(mem[r][c]){
            return;
        }else{
            mem[r][c]=true;
        }
        zero_pos.push_back(std::make_pair(r,c));
        for(auto direction: directions){
                int r_cur=r+direction;
                int c_cur=c;
                if(r_cur>=0&&r_cur<r_limit&&c_cur>=0&&c_cur<c_limit&&board[r_cur][c_cur]=='O'){
                    dfs(board,r_limit,c_limit,r_cur,c_cur,zero_pos,mem);
                }
                r_cur=r;
                c_cur=c+direction;
                if(r_cur>=0&&r_cur<r_limit&&c_cur>=0&&c_cur<c_limit&&board[r_cur][c_cur]=='O'){
                    dfs(board,r_limit,c_limit,r_cur,c_cur,zero_pos,mem);
                }
            }
        }
public:
    void solve(vector<vector<char>>& board) {
        int r_limit=board.size();
        int c_limit=0;
        if(r_limit!=0){
            c_limit=board[0].size();
        }
        vector<std::pair<int,int>> zero_pos;
        vector<vector<bool>> mem(r_limit,vector<bool>(c_limit,false));
        for(int i=0;i<board.size();++i){
            if(board[i][0]=='O'){
                dfs(board,r_limit,c_limit,i,0,zero_pos,mem);
            }
            if(c_limit!=0&&board[i][c_limit-1]=='O'){
                dfs(board,r_limit,c_limit,i,c_limit-1,zero_pos,mem);
            }
        }
        for(int i=0;i<c_limit;++i){
            if(board[0][i]=='O'){
                dfs(board,r_limit,c_limit,0,i,zero_pos,mem);
            }
            if(r_limit!=0&&board[r_limit-1][i]=='O'){
                dfs(board,r_limit,c_limit,r_limit-1,i,zero_pos,mem);
            }
        }
        for(int i=0;i<r_limit;++i){
            for(int j=0;j<c_limit;++j){
                board[i][j]='X';
            }
        }
        for(auto zero_p:zero_pos){
            board[zero_p.first][zero_p.second]='O';
        }
    }
};
int main(){
    vector<vector<char>> board{{'O','O'},{'O','O'}};
    Solution s;
    s.solve(board);
}