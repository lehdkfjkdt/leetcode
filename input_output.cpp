#include "iostream"
#include "string"
#include "sstream"
#include "algorithm"

using namespace std;

int main(){
    string str;
    stringstream sstream;
    while(getline(cin,str)&&str!=""){
        int pos=str.find(',');
        while(pos!=string::npos){
            str.replace(pos,1," ");
            pos=str.find(',');
        }
        cout<<str<<endl;
        sstream.clear();
        sstream<<str;
        int val;
        while(sstream>>val){
           cout<<val<<endl; 
        }
    }
    return 0;
}