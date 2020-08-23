#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[s]<nums[e]){
                if(nums[mid]==target){
                    return mid;
                }
                if(nums[mid]<target){
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }
           else{
                if(nums[mid]>nums[e]){
                    if(target==nums[s]){
                        return s;
                    }else if(target<nums[s]){
                        s=mid+1;
                    }else{
                        s++;
                    }
                }else{
                    if(target==nums[s]){
                        return s;
                    }else if(target<nums[s]){
                        s++;
                    }else{
                        e=mid-1;
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> v={4,5,6,7,0,1,2};
    cout<<s.search(v,0);
    return 0;
}