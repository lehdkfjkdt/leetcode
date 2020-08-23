class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ladder=1;
        if(s.find(endWord)==s.end())return 0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;++i){
                string temp=q.front();
                q.pop();
                s.erase(temp);
                if(temp==endWord){
                    return ladder;
                }
                for(int j=0;j<temp.size();++j){
                    char t=temp[j];
                    for(int k=0;k<26;++k){
                        temp[j]='a'+k;
                        if(s.find(temp)!=s.end()){
                            q.push(temp);
                        }
                    }
                    temp[j]=t;
                }
            }
            ladder++;
        }
        return 0;
    }
};
