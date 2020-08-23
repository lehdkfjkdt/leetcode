class Solution {
private: 
    bool helper(const vector<double>& nums){
        if(nums.empty()){
            return false;
        }
        if(nums.size()==1){
            return std::abs(nums[0]-24.0)<1e-6;
        }
        bool valid =false;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                vector<double> copy;
                for(int k=0;k<nums.size();k++){
                    if(k!=i&&k!=j){
                        copy.push_back(nums[k]);
                    }
                }
                double a=nums[i];
                double b=nums[j];
                // *
                copy.push_back(a*b);
                valid = valid||helper(copy);
                copy.pop_back();

                // /
                if(std::abs(a)>1e-6){
                    copy.push_back(b/a);
                    valid = valid||helper(copy);
                    copy.pop_back();
                }
                if(std::abs(b)>1e-6){
                    copy.push_back(a/b);
                    valid = valid||helper(copy);
                    copy.pop_back();
                }

                // -
                copy.push_back(a-b);
                valid = valid||helper(copy);
                copy.pop_back();

                copy.push_back(b-a);
                valid = valid||helper(copy);
                copy.pop_back();

                // +
                copy.push_back(a+b);
                valid = valid||helper(copy);
                copy.pop_back();
                
                if(valid){
                    return true;
                }
            }
          
        }
        return valid;
    }
public:
    bool judgePoint24(vector<int>& nums) {
       return  helper({nums.begin(),nums.end()});
    }
};