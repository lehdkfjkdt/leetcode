class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int zeors=0;
        while(n>m){
            zeors++;
            m=m>>1;
            n=n>>1;
        }
        return m<<zeors;

    }
};