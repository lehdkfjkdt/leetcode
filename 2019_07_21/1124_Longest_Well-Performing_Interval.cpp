class Solution {
public:
    int longestWPI(vector<int>& hours) {
        std::map<int,int> score_index_map;
        int score=0;
        int ret;
        for(int index=0;index<hours.size();index++){
            if(hours[index]>8)++score;
            else --score;
            if(score>0){
                ret=std::max(ret,i+1);
            }else{
                if(score_index_map.find(score)==score_index_map.end()){
                    score_index_map[score]=i;
                }
                if(score_index_map.find(score-1)!=score_index_map.end()){
                    ret=std::max(ret,i-score_index_map[score-1]);
                }
            }
        }
        return ret;
    }
};