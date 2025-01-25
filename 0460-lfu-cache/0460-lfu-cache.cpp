class LFUCache {
public:
    class node {
    public:
        int key;
        int val;
        int freq;
        node * next;
        node * prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
            freq = 1; 
        }
    };

    unordered_map<int, node*> keyNode; 
    unordered_map<int, pair<node*, node*>> freqList; 
    int minFreq;
    int cap; 

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void addNode(node* newnode, int freq) {
        if (freqList.find(freq) == freqList.end()) {
            node* head = new node(-1, -1);
            node* tail = new node(-1, -1);
            head->next = tail;
            tail->prev = head;
            freqList[freq] = {head, tail};
        }
        node* head = freqList[freq].first;
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_) {
        if (keyNode.find(key_) == keyNode.end()) {
            return -1;
        }
        
        node* resNode = keyNode[key_];
        int res = resNode->val;
        updateFrequency(resNode);
        return res;
    }

    void put(int key_, int value) {
        if (cap == 0) return;
        
        if (keyNode.find(key_) != keyNode.end()) {
            node* existingNode = keyNode[key_];
            existingNode->val = value;
            updateFrequency(existingNode);
        } else {
            if (keyNode.size() == cap) {
                node* lfuNode = freqList[minFreq].second->prev;
                keyNode.erase(lfuNode->key);
                deleteNode(lfuNode);
                if (freqList[minFreq].first->next == freqList[minFreq].second) {
                    freqList.erase(minFreq);
                }
                delete lfuNode;
            }
            
            node* newNode = new node(key_, value);
            keyNode[key_] = newNode;
            minFreq = 1; 
            addNode(newNode, 1);
        }
    }

    void updateFrequency(node* currNode) {
        int oldFreq = currNode->freq;
        currNode->freq++;
        
        deleteNode(currNode);
        if (freqList[oldFreq].first->next == freqList[oldFreq].second) {
            freqList.erase(oldFreq);
            if (minFreq == oldFreq) {
                minFreq++;
            }
        }
        
        addNode(currNode, currNode->freq);
    }
};