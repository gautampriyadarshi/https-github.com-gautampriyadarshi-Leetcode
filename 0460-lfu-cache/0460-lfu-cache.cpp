// TC: O(1) for both get and put.
// Hash map lookups are O(1).
// Linked list push_front, back, and erase (with iterator) are O(1).

// SC: O(C), where C is the capacity.
// We store each item in the key_map and one of the lists in freq_map.

// Structure to store cached data
struct Node {
    int key, value, freq;
    Node(int k, int v, int f) : key(k), value(v), freq(f) {}
};

class LFUCache {
    int cap;
    int min_freq;

    // Maps key to the iterator pointing to the Node in the specific frequency list
    unordered_map<int, list<Node>::iterator> key_map;

    // Maps frequency to a doubly linked list of Nodes with that frequency
    unordered_map<int, list<Node>> freq_map;

    // Helper function to promote a node to a higher frequency list
    void updateFreq(int key) 
    {
        auto it = key_map[key];
        int f = it->freq;
        int v = it->value;
        
        // 1. Remove from current frequency list
        freq_map[f].erase(it);
        if (freq_map[f].empty()) {
            freq_map.erase(f);

            // If the empty list was the min_freq, increment min_freq
            if (f == min_freq) 
                min_freq++;
        }
        
        // 2. Insert into frequency list f + 1
        freq_map[f + 1].push_front(Node(key, v, f + 1));
        key_map[key] = freq_map[f + 1].begin();
    }

public:
    LFUCache(int capacity) 
    {
        cap = capacity;
        min_freq = 0;
    }

    int get(int key) 
    {
        if (key_map.find(key) == key_map.end()) 
            return -1;
        
        int val = key_map[key]->value;
        updateFreq(key);
        return val;
    }

    void put(int key, int value) 
    {
        if (cap <= 0) 
            return;

        // If key exists, update value and frequency
        if (key_map.find(key) != key_map.end()) {
            key_map[key]->value = value;
            updateFreq(key);
            return;
        }

        // If capacity is reached, evict the LFU (and LRU if tie)
        if (key_map.size() >= cap) {
            // The back of the min_freq list is the Least Recently Used
            int key_to_evict = freq_map[min_freq].back().key;
            freq_map[min_freq].pop_back();
            key_map.erase(key_to_evict);
            
            if (freq_map[min_freq].empty()) {
                freq_map.erase(min_freq);
            }
        }

        // Add new key with frequency 1
        min_freq = 1;
        freq_map[1].push_front(Node(key, value, 1));
        key_map[key] = freq_map[1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */