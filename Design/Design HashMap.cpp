// https://leetcode.com/problems/design-hashmap/

class MyHashMap {
public: 
    int v[1000000];

    MyHashMap() {
        memset(v,-1,sizeof v);
    }

    void put(int key, int value) {
        v[key] = value;
    }

    int get(int key) {
        return v[key];
    }

    void remove(int key) {
        v[key] = -1;
    }
};
