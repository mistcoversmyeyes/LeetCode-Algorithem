/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <list>
#include <map>
#include <unordered_map>
#include <utility>


using namespace std;
class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {
    }
    
    int get(int key) {
        if (key2locate.find(key) == key2locate.end()) {
            return -1;
        }
        int ret = key2locate.find(key)->second->second;
        lru_.erase(key2locate.find(key)->second);
        lru_.push_front(make_pair(key, ret));
        key2locate[key] = lru_.begin();
        return ret;
    }
    
    void put(int key, int value) {
        if (key2locate.find(key) != key2locate.end()) {
            lru_.erase(key2locate.find(key)->second);
            lru_.push_front(make_pair(key, value));
            key2locate[key] = lru_.begin();
            return;
        }
        else {
            if (size_ == capacity_) {
                evict();
            }
            lru_.push_front(make_pair(key, value));
            key2locate[key] = lru_.begin();
            size_++;
        }
    }

    void evict() {
        int to_be_evict = lru_.back().first;
        
        key2locate.erase(key2locate.find(to_be_evict));
        lru_.pop_back();
        size_--;
    }


private:
    int capacity_{0};
    int size_{0};
    list<pair<int, int>> lru_;
    unordered_map<int, list<pair<int, int>>::iterator> key2locate;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

