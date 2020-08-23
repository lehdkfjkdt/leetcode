#include "sstream"

#include <string>
#include <iostream>
#include <vector>

int main(){
    int n;
    while(std::cin>>n){
    
    for(int i=0;i<n;++i){
         std::string str;
        std::cin>>str;      
        if(str.size()<8){
            str.append(8-str.size(),'0');
            std::cout<<str<<std::endl;
        }else if(str.size()>8){
            std::vector<std::string> str_vec;
            while(str.size()>8){
                str_vec.push_back(str.substr(0,8));
                str=str.substr(8);
            }
            str.append(8-str.size(),'0');
            str_vec.push_back(str);
            for(const auto s:str_vec){
                std::cout<<s<<std::endl;
            }
        }else{
            std::cout<<str<<std::endl;
        } 
    }
    }
    return 0;
}