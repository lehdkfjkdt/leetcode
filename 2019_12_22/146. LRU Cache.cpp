#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) :capacity_(capacity){
    }
    
    int get(int key) {
        std::unordered_map<int,std::pair<int,std::list<int>::iterator>>::iterator iter=cache.find(key); 
        if(iter!=cache.end()){
            reorder(iter);
            return iter->second.first;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
       std::unordered_map<int,std::pair<int,std::list<int>::iterator>>::iterator iter=cache.find(key); 
       if(iter!=cache.end()){
           reorder(iter);
       }else{
           if(cache.size()==capacity_){
               cache.erase(used.back());
               used.pop_back();
           }
           used.push_front(key);
       } 
       cache[key]={value,used.begin()};
    }
private:
    std::list<int> used;
    // key ->(val, key iterator in used)
    std::unordered_map<int,std::pair<int,std::list<int>::iterator>> cache;
    int capacity_;
    void reorder(std::unordered_map<int,std::pair<int,std::list<int>::iterator>>::iterator iter){
        int key=iter->first;
        used.erase(iter->second.second);
        used.push_front(key);
        iter->second.second=used.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */