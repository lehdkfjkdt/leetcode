#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    std::pair<int,int> FindAndSort(std::vector<int>& nums,int start,int end){
        int temp=nums[start];
        while(start<end){
            while(end>start&&nums[end]>=temp){
                --end;
            }
            if(end>start&&start<nums.size()){
            nums[start]=nums[end];
            }
            while(end>start&&nums[start]<=temp){
                ++start;
            }
            if(end>start&&start<nums.size()){
             nums[end]=nums[start];
            }
        }
        nums[start]=temp;
        return std::make_pair(start,temp);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start=0;
        int end=nums.size()-1;
        std::pair<int,int> ret;
        while(end>=start){
            ret=FindAndSort(nums,start,end);
            if(ret.first==nums.size()-k){
                break;
            }else if(ret.first<nums.size()-k){
                start=ret.first+1;
            }else{
                end=ret.first-1;
            }
        }
        return ret.second;
    }
};
int main(){
    vector<int> input{7,6,5,4,3,2,1};
    Solution s;
    cout<<s.findKthLargest(input,5);
    while(1);
}