class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int min_l=INT_MAX;
        int cur_l=1;
        vector<vector<string>> ans;
        queue<vector<string>> paths;
        paths.push({beginWord});
        set<string> visted;
        while(!paths.empty()){
            vector<string> path=paths.front();
            paths.pop();
            if(path.size()>cur_l){
                for(const string& s: visted){
                    auto iter=find(wordList.begin(),wordList.end(),s);
                    if(iter!=wordList.end()){
                        wordList.erase(iter);
                    }
                }
                if(path.size()>min_l){
                    break;
                }else{
                    cur_l=path.size();
                }
            }
            string last=path.back();
            for(int index=0;index<last.size();++index){
                string news=last;
                for(char c='a';c<='z';++c){
                    news[index]=c;
                    if(find(wordList.begin(),wordList.end(),news)!=wordList.end()){
                        vector<string> new_path=path;
                        new_path.push_back(news);
                        visted.insert(news);
                        if(news==endWord){
                            min_l=cur_l;
                            ans.push_back(new_path);
                        }
                        paths.push(new_path);
                    }
                }
            }
        }
        return ans;
    }
};