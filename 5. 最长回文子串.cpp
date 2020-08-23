class Solution {
    string minString(string s, int start,int end){
        while(start>=0&&end<s.size()&&s[start]==s[end]){
            start--;
            end++;
        }
        return s.substr(start+1,end-start-1);
    }
public:
    string longestPalindrome(string s) {
        string res;
        for(int i=0;i<s.size();++i){
            string s1=minString(s,i,i);
            string s2="";
            if(i<s.size()-1){
                s2=minString(s,i,i+1);
            }
            res=res.size()<s1.size()?s1:res;
            res=res.size()<s2.size()?s2:res;
        }
        return res;
    }
};