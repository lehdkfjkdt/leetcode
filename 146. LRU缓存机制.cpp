class LRUCache {
    private:
    // The capacity of lru cache.
    int capacity_=0;
    // The iterator map.
    map<int, list<pair<int,int>>::iterator> map_;
    // The cacahe.
    list<pair<int,int>> cache_;
public:
    LRUCache(int capacity) {
        capacity_=capacity;
    }
    
    int get(int key) {
        if(map_.find(key)==map_.end()){
            return -1;
        }else{
            put(key,map_[key]->second);
            return map_[key]->second;
        }
    }
    
    void put(int key, int value) {
        pair<int,int> temp{key,value};
        if(map_.find(key)!=map_.end()){
            cache_.erase(map_[key]);
            cache_.push_front(temp);
            map_[key]=cache_.begin();
        }else{
           if(capacity_==cache_.size()){
               map_.erase(cache_.back().first);
               cache_.pop_back();
           } 
           cache_.push_front(temp);
           map_[key]=cache_.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */