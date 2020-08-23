class Solution {
public:
    int countBinarySubstrings(string s) {
      vector<int> count;
      int cur=0;
      while(cur<s.size()){
          char cur_char=s[cur];
          int cur_count=0;
          while(cur<s.size()&&s[cur]==cur_char){
              cur++;
              cur_count++;
          }
          count.push_back(cur_count);
      }
      int res=0;
      for(int i=0;i<count.size();++i){
          if(i+1<count.size()){
              res+=min(count[i],count[i+1]);
          }
      }
      return res;
    }
};