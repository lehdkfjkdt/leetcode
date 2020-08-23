class Solution {
private:
    int distance(const string& word1, int i,const string& word2, int j,vector<vector<int>>* mem){
        if(i==-1)return j+1;
        if(j==-1)return i+1;
        if((*mem)[i][j]!=-1){
            return (*mem)[i][j];
        }
        
        if(word1[i]==word2[j]){
             (*mem)[i][j]=distance(word1,i-1,word2,j-1,mem);
        }else{
            (*mem)[i][j]=min(distance(word1,i-1,word2,j-1,mem)+1,min(distance(word1,i-1,word2,j,mem)+1,distance(word1,i,word2,j-1,mem)+1));
        }
        return (*mem)[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> mem(word1.size(),vector<int>(word2.size(),-1));
        return distance(word1,word1.size()-1,word2,word2.size()-1,&mem);
    }
};