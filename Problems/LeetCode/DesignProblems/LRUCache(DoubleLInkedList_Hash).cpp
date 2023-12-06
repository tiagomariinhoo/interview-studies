class LRUCache {
public:

    /**
        Great and explained solution: https://www.scaler.com/topics/lru-cache-implementation/
        Queue implemented by using a Double Linked List, to store Key-Value
        Most Recently Used at the FRONT
        Least Recently Used at the END

        We're using this data structure because we can add/remove elements from
        any position in O(1) time in the worst case

        ---

        HashMap
        -> Using a Hash Map to map the Keys with the corresponding nodes present in the cache
        will help us to access any node of cache in O(1)

        Idea: Store all the Key-Value pairs in the form of nodes of a doubly-linked list arranged

        PUT operation:
            - Add (key, value) pair in the cache
            - Check if the cache already has a Node with its Key 
            - If Node already exists
                - Update node's value
                - Move it to the head, since it becomes the most recently used
            - Else
                - Define a new node
                - Add it to the head
                - Add it to the Map
                - If after adding a newNode the size of the list exceeds the capacity:
                    - Remove node present at the tail (since it is the least recently used)
                    - Remove it from the map

        GET operation:
            - Check if the map contains any node with the key
            - If doesn't exist, return -1
            - Otherwise, move the node to the head

        
    */

    struct Node {
        int key;
        int val;
        Node *next;
        Node *prev;

        Node(int key, int val) : key(key), val(val) {}
    };

    // Head and tail are dummy nodes, never null, it's just to make the queue easier
    Node *head, *tail;

    // It will map the Keys to Nodes*
    unordered_map<int, Node*> m;

    // Add node into the head, since will be the most recently used
    void addNode(Node *node) {
        node->prev = head;
        node->next = head->next;
        head->next = node;
        // To make the next node point to the current node
        node->next->prev = node;
    }

    void removeNode(Node *node) {
        // Just changing the address
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }


    // In an implementation using List from STL library, for example, it will be similar to Splice function
    void moveToHead(Node *node) {
        // Will just remove the Node from queue
        removeNode(node);
        // Will add the node into the head
        addNode(node);
    }

    Node *popFromTail() {
        Node *ret = tail->prev;
        removeNode(ret);

        return ret;
    }

    int size;
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    // Check if the key is on the map
    // If it is, we just need to move the Node to the head, this takes O(1)
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        Node *aux = m[key];
        moveToHead(aux);
        return aux->val;
    }
    
    // we need to check if it exists and put it into the head
    // otherwise, just add the node directly on the head
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key]->val = value;
            moveToHead(m[key]);
            return ;
        }

        Node *aux = new Node(key, value);
        m[key] = aux;
        addNode(aux);
        size--;
        if (size < 0) {
            Node *aux = popFromTail();
            m.erase(aux->key);
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */