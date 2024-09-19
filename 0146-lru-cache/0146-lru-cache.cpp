class LRUCache {
public:
    LRUCache(int capacity) : m_capacity (capacity) { 
    }
    
    int get(int key) {
        auto it = data.find (key);
        if (it == data. end ())
            return -1;
        ls.splice (ls.begin (), ls, data[key]);
        return data[key]->second;
    }
    
    void put(int key, int value) {
        auto it = data.find (key);
        if (it != data.end ()) {
            ls.splice (ls.begin (), ls, data[key]);
            data[key]->second = value;
            return;
        }
        if (ls.size () == m_capacity) {
            auto d_key = ls.back ().first;
            ls.pop_back ();
            data.erase (d_key);
        }
        ls.push_front ({key, value});
        data[key] = ls.begin ();
    }

private:
    int m_capacity{};
    unordered_map<int, list<pair<int,int>>::iterator> data;
    list<pair<int,int>> ls;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */