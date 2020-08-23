class Solution {
private:
    int helper(vector<vector<vector<int>>>& mem,vector<int>& right, vector<int>& boxes,int presize,int l,int r){
        if(l>r){
            return presize*presize;
        }
        if(mem[presize][l][r]!=-1){
            return mem[presize][l][r];
        }
        int ret=presize*presize;
        int j=l;
        while(right[j]==j+1&&j+1<=r){
            j++;
        }
        ret=max(ret,(presize+j-l+1)*(presize+j-l+1)+helper(mem,right,boxes,0,j+1,r));
        int nextj=right[j];
        while(nextj<=r){
            ret=max(ret,helper(mem,right,boxes,0,j+1,nextj-1)+helper(mem,right,boxes,presize+j-l+1,nextj,r));
            nextj=right[nextj];
        }
        return mem[presize][l][r]=ret;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        map<int,int> m;
        vector<int> right(boxes.size(),boxes.size());
        for(int i=boxes.size()-1;i>=0;i--){
            if(m.find(boxes[i])!=m.end()){
                right[i]=m[boxes[i]];
            }
            m[boxes[i]]=i;
        }
        int n=boxes.size();
        vector<vector<vector<int>>> mem(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return helper(mem,right,boxes,0,0,n-1);
    }
};