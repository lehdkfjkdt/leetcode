class Solution {
public:
    string reverseWords(string s) {
        int start=0;
        int end=0;
        for(;end<=s.size();end++){
            if(end==s.size()||s[end]==' '){
                reverse(s.begin()+start,s.begin()+end);
                start=end+1;
            }
        }
        return s;
            }
};