class Solution {
public:
    string minWindow(string s, string t) {
        std::vector<int> map(128,0);
        int count=0,begin=0,end=0;
        int min_d=INT_MAX;
        int head=0;
        for(const auto c : t){
            map[c]++;
            count++;
        }
        while(end<s.size()){
            if(map[s[end++]]-->0)count--;
            while(count==0){
                if(end-begin<min_d){
                    min_d=end-begin;
                    head=begin;
                }
                if(map[s[begin++]]++==0)count++;
            }
        }
        return min_d==INT_MAX?"":s.substr(head,min_d); 
    }
};