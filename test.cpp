#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> v{0,1,2,3,4};
    v.erase(v.begin());
    for(auto it=v.begin();it!=v.end();it++){
        cout<<" "<<*it;
    }
    auto it=v.end()-1;
    v.erase(it);
    for(auto val:v){
        cout<<" "<<val;
    }
    return 0;
}