//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    // Default constructor
    Node() {
        key = 0;
        value = 0;
        next = nullptr;
        prev = nullptr;
    }

    // Parameterized Constructor
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    void insertAtHead(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        if (temp != nullptr) {
            temp->prev = node;
        }
    }

    void deleteNode(Node* node) {
        Node* prevv = node->prev;
        Node* nextt = node->next;
        if (prevv != nullptr) {
            prevv->next = nextt;
        }
        if (nextt != nullptr) {
            nextt->prev = prevv;
        }
    }

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        mp.clear();
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            deleteNode(node);
            insertAtHead(node);
        } else {
            if (mp.size() == capacity) {
                Node* nodeToDelete = tail->prev;
                mp.erase(nodeToDelete->key);
                deleteNode(nodeToDelete);
                delete nodeToDelete;
            }
            Node* node = new Node(key, value);
            insertAtHead(node);
            mp[key] = node;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends