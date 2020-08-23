class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>* p1=&nums1;
        vector<int>* p2=&nums2;
        if(nums1.size()>nums2.size()){
            p1=&nums2;
            p2=&nums1;
        }
        int i,j;
        int min_i=0;
        int max_i=p1->size();
        int half=(p1->size()+p2->size()+1)/2;
        while(min_i<=max_i){
            i=(min_i+max_i)/2;
            j=half-i;
            if(i>0&&j<p2->size()&&p1->at(i-1)>p2->at(j)){
                max_i=i-1;
            }
            else if(j>0&&i<p1->size()&&p2->at(j-1)>p1->at(i)){
                min_i=i+1;
            }else{
                double left_max;
                if(i==0)left_max=p2->at(j-1);
                else if(j==0)left_max=p1->at(i-1);
                else{
                    left_max=max(p1->at(i-1),p2->at(j-1));
                }
                if((p1->size()+p2->size())%2){
                    return left_max;
                }
                double right_min;
                if(i==p1->size()){
                    right_min=p2->at(j);
                }else if(j==p2->size()){
                    right_min=p1->at(i);
                }else{
                    right_min=min(p1->at(i),p2->at(j));
                }
                return (left_max+right_min)/2;
            }
           
        }
         return -1.0;
    }
};