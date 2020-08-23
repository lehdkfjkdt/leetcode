/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
private:
    map<string, vector<string>> map_ans_;
    vector<string> Combine(const string s,  vector<string> vec){
        for(int i = 0;i<vec.size();++i){
            vec[i] = vec[i]+" "+s;
        }
        return vec;
    }
    vector<string> Search(const string s, const set<string>& wordDict){
        if(map_ans_.count(s)){
            return map_ans_[s];
        }
        vector<string> ret;
        if(wordDict.count(s)){
            ret.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string r_sub = s.substr(i);
            if(wordDict.count(r_sub)){
                string l_sub = s.substr(0,i);
                vector<string> cur = Combine(r_sub,Search(l_sub,wordDict));
                ret.insert(ret.end(),cur.begin(),cur.end());
            }
        }
        map_ans_[s]=ret;
        return ret;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        return Search(s,set<string>(wordDict.begin(),wordDict.end()));
    }
};
// @lc code=end

