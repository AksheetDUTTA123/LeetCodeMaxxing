#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
struct Node{
    int key; //here we define a doubly linked list, needed for this problem
    int val;
    Node * prev;
    Node * next;
    Node(int _key, int _val){
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        head = new Node(-1, -1); //make a dummy head and tail node that point to each other, add real nodes in between them
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        //first use the map to access from cache
        if(cache.find(key) == cache.end()){
            return -1;
        }
        //need to now update that cache and move it to most recently used
        cache[key] -> prev -> next = cache[key] -> next; //first we have to remove the node from its current position in the linked list, so we have to connect the prev and next node together
        cache[key] -> next -> prev = cache[key] -> prev;

        //move it to end of the linked list
        cache[key] -> prev = head;
        cache[key] -> next = head-> next;
        head -> next -> prev = cache[key];
        head -> next = cache[key];
        return cache[key] -> val;
    }
    
    void put(int key, int value) {
    if(cache.find(key) != cache.end()){ //if the key already exists, we just need to update the value and move it to the most recently used position
    //similar to the get function and just update the value
            cache[key]-> val = value;
        cache[key] -> prev -> next = cache[key] -> next;  //first we have to remove the node from its current position in the linked list, so we have to connect the prev and next node together
        cache[key] -> next -> prev = cache[key] -> prev;

        cache[key] -> prev = head;
        cache[key] -> next = head-> next;
        head -> next -> prev = cache[key];
        head -> next = cache[key];
        }
    else{
        Node* newNode = new Node(key, value); //need to make a new node with that key and value
        cache[key] = newNode; //map the key to the node
        newNode -> prev = head; //place node right after the head dummy node, which is the most recently used position
        newNode -> next = head -> next;
        head -> next -> prev = newNode; //update the next nodes prev and head next ptr
        head -> next = newNode;        
        if(cache.size() > capacity){ //if the cache.size() is more than capacity, we need to evict the LRU node, which is the node right before the tail dummy node
            Node * tailPrev = tail -> prev; //tailPrev is what is getting evicted, so have to set tail prev to the prev of TailPrev
            tail -> prev = tailPrev -> prev;
            tailPrev -> prev -> next = tail; //and the next of the prev of tailPrev should point to tail, hence deleting tailPrev
            cache.erase(tailPrev -> key);
        }
    }

    }
private:
    int capacity;
    unordered_map<int, Node*> cache; //unordered map that points the key to the Node in the linked list, so we can access in O(1)
    Node* head; //head and tail of the linked list, head is most recently used, tail is least recently used
    Node* tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

