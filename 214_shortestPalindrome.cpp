class Solution {
public:
    string shortestPalindrome(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int r_start_index=0;
        int r_end_index=r.size()-1;
        int s_start_index=0;
        int s_end_index=s.size()-1;
        if(s.empty()){
            return s;
        }
        while(r.substr(r_start_index,r_end_index-r_start_index+1)!=s.substr(s_start_index,s_end_index-s_start_index+1)){
            r_start_index++;
            s_end_index--;
        }
        return r.substr(0,r_start_index)+s;
    }
};