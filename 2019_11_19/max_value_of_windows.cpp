#include <deque>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;
        if(num.size()<size){
            return  ret;
        }
        deque<int> indexs;
        for(int i=0;i<num.size();i++){
            while(!indexs.empty()&&num[i]>num[indexs.back()]){
                indexs.pop_back();
            }
            indexs.push_back(i);
            if(i-indexs.front()>=size){
                indexs.pop_front();
            }
            if(i>=size-1&&!indexs.empty()){
                ret.push_back(num[indexs.front()]);
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    auto ret=s.maxInWindows({2,3,4,2,6,2,5,1},3);
    for(int a : ret){
        cout<<a<<endl;
    }
    while(1);
}