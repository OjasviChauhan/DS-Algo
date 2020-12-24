/*

Storing values in a Hashmap whose key is a given KEY and value is an iterator to 
the corresponding nodes of Linkedlist.
Each node of Linkedlist is a pair of KEY and VALUE.

KEY  --->  (KEY,VALUE)
----------------------
a    ---->    a-1
               |
b    ---->    b-2
               |
c    ---->    c-3
               |
d    ---->    d-4

*/

typedef pair<int,int> pi;
#define ff first
#define ss second

class LRUCache {
public:
    int d;
    list<pi> dq;
    unordered_map<int,list<pi>::iterator> mp;
    
    LRUCache(int capacity) {
        d = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;  
        else{
            pi ans = *mp[key];
            dq.erase(mp[key]);
            dq.push_front(ans);
            mp[key] = dq.begin();
            return ans.ss;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(dq.size() == d){
                // firstly we need to erase the least used key from hashmap
                // and then also from its corresponding entry in list.
                pi LRUKey = dq.back();
                mp.erase(LRUKey.ff);
                dq.pop_back();
                
                // then push the new value in list
                // and connect this value to its key in hashmap.
                dq.push_front({key,value});
                mp[key] = dq.begin();
            }
            else{
                // if size is less than capacity then simply
                // push value in list and perform the mapping.
                dq.push_front({key,value});
                mp[key] = dq.begin();
            } 
        }
        else{
            // Update the entry, no need to erase the key from map
            dq.erase(mp[key]);
            dq.push_front({key,value});
            mp[key] = dq.begin();
        }  
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
