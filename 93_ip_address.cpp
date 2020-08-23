#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void helper(vector<string> cur, string s,vector<string>& res){
        if(cur.size()>4){
            return;
        }
        if(cur.size()==4&&s.empty()){
            string cur_ans;
            cur_ans=cur[0]+"."+cur[1]+"."+cur[2]+"."+cur[3];
            res.push_back(std::move(cur_ans));
            return;
        }
        if(!s.empty()){
            for(int i=0;i<3&&i<s.size();i++){
                if(i>0&&s[0]=='0'){
                    continue;
                }
                string cur_str=s.substr(0,i+1);
                if(cur_str=="5"){
                    std::cout<<"find";
                }
                int cur_int=std::stoi(cur_str);
                if(cur_int>=0&&cur_int<=255){
                    cur.push_back(cur_str);
                    helper(cur,s.substr(i+1),res);
                    cur.pop_back();
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> cur;
        vector<string> ans;
        helper(cur,s,ans);
        return ans;
    }
};

int main(){
    string s="172162541";
    Solution su;
    su.restoreIpAddresses(s);
    return -1;
}