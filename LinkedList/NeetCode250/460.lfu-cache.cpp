#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start

struct Node {
    int key;
    int val;
    int freq;
    Node * prev;
    Node * next;
    Node(int _key, int _val){
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
        freq = 1;
    }
};


class LFUCache {
public:
    LFUCache(int capacity) {
        this -> capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        int oldFreq = cache[key]-> freq;
        freqMap[oldFreq].erase(iterMap[key]);
        if(freqMap[oldFreq].empty()){
            freqMap.erase(oldFreq);
            if(minFreq == oldFreq){
                minFreq++;
            }
        }
        //need to update the frequency of the node and move it to the correct position in the linked list
        cache[key] -> freq++;

        //move it to the correct position in the linked list based on its frequency
        freqMap[cache[key]->freq].push_back(cache[key]);
        iterMap[key] = prev(freqMap[cache[key]->freq].end());
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0){
            return;
        }
        if(cache.find(key) != cache.end()){
        cache[key]->val = value; 
        int oldFreq = cache[key] -> freq;
        freqMap[oldFreq].erase(iterMap[key]);
        if(freqMap[oldFreq].empty()){
            freqMap.erase(oldFreq);
            if(minFreq == oldFreq){
                minFreq++;
            }
        }
        cache[key] -> freq++;

        //move it to the correct position in the linked list based on its frequency
        freqMap[cache[key]->freq].push_back(cache[key]);
        iterMap[key] = prev(freqMap[cache[key]->freq].end());
    }
    else{
        if(cache.size() == capacity){
            //evict the least frequently used node, which is the node with the lowest frequency in the linked list
            Node * nodeToEvict = freqMap[minFreq].front();
            freqMap[minFreq].pop_front();
            cache.erase(nodeToEvict->key);
            iterMap.erase(nodeToEvict->key);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        freqMap[1].push_back(cache[key]);
        iterMap[key] = prev(freqMap[1].end());
        minFreq = 1;
    }
    }
private:
 unordered_map<int, Node*> cache;
  unordered_map<int, list<Node*>> freqMap;
  unordered_map<int, list<Node*>::iterator> iterMap;
  int minFreq = 0;
  int capacity;
  Node* head;
  Node *tail;

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

