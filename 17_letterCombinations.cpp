#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
private:
void helper(const string& digits,const map<char,vector<char>>& m,int start,string cur,vector<string>& ret){
    if(start==digits.size()){
        ret.push_back(cur);
        return;
    }
    char c=digits[start];
    const vector<char> v=m.at(c);
    for(char c:v){
        cur+=c;
        helper(digits,m,start+1,cur,ret);
        cur.pop_back();
    }
}

public:
    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> m;
        m['2']={'a','b','c'};
        m['3']={'d','e','f'};
        m['4']={'g','h','i'};
        m['5']={'j','k','l'};
        m['6']={'m','n','o'};
        m['7']={'p','q','r','s'};
        m['8']={'t','u','v'};
        m['9']={'w','x','y','z'};
        vector<string> ret;
        helper(digits,m,0,"",ret);
        return ret;

    }
};
int main(){
    Solution s;
    s.letterCombinations("23");
    return -1;
}