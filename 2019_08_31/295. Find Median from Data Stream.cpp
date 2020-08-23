#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

class MedianFinder {
private:
      std::priority_queue<int> max_heap;
      //std::priority_queue<int,std::vector<int>,std::greater<int>> min_heap;
      std::priority_queue<int, std::vector<int>, std::greater<int> >min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if(min_heap.size()>max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
       return max_heap.size()>min_heap.size()?(double)max_heap.top():(max_heap.top()+min_heap.top())*0.5; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */