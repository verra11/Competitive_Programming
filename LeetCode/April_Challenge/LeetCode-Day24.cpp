class LRUCache {
    
    unordered_map <int,int> m;
    unordered_map <int,list <int>::iterator> l;
    list <int> q;
    int mx=0,curr=0;
    
public:
    LRUCache(int capacity) {
        
        mx=capacity;        
    }
    
    int get(int key) {
        
        auto it=m.find(key);
        if(it==m.end()) return -1;
        q.erase(l[key]);
        q.push_front(key);
        l[key]=q.begin();
        return it->second;
        
    }
    
    void put(int key, int value) {
        
        auto it=m.find(key);
        if(it!=m.end())
        {
            q.erase(l[key]);
            m[key]=value;
            q.push_front(key);
            l[key]=q.begin();
            return;
        }
        if(curr<mx)
        {
            m[key]=value;
            q.push_front(key);
            l[key]=q.begin();
            curr++;
        }
        else
        {
            auto it=q.rbegin();
            int old_key = *it;
            m.erase(old_key);
            l.erase(old_key);
            q.pop_back();
            m[key]=value;
            q.push_front(key);
            l[key]=q.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */