class Solution {
public:
    bool isMatch(string s, string p) {
        int spos=0;
        int ppos=0;
        int star=-1;
        int match=-1;
        while(spos<s.size()){
            if(ppos<p.size()&&(p[ppos]==s[spos]||p[ppos]=='?')){
                ++ppos;
                ++spos;
            }else if(ppos<p.size()&&p[ppos]=='*'){
                star=ppos;
                match=spos++;
            }else if(star>=0){
                ppos=star+1;
                spos=match++;
            }else{
                return false;
            }
        }
        while(ppos<p.size()&&p[ppos]=='*'){
            ++ppos;
        }
        return ppos==p.size();
    }
};