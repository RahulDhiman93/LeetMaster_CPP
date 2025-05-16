class AllOne {
private:
    unordered_map<string, int> umap;
    set<pair<int,string>> smap;

public:
    AllOne() {
        umap.clear();
        smap.clear();
    }
    
    void inc(string key) {
        int old = umap[key];
        umap[key]++;
        smap.erase({old, key});
        smap.insert({old+1, key});
    }
    
    void dec(string key) {
        int old = umap[key];
        umap[key]--;
        smap.erase({old, key});
        if (umap[key] > 0) {
            smap.insert({old-1, key});
        } else {
            umap.erase(key);
        }
    }
    
    string getMaxKey() {
        if (smap.empty()) return "";
        return smap.rbegin()->second;
    }
    
    string getMinKey() {
        if (smap.empty()) return "";
        return smap.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */