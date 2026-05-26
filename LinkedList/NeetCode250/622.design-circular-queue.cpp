#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        arr.resize(k);
        start = 0;
        end = 0;
        count = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(count == capacity){
            return false;
        }
        arr[end] = value;
        end = (end + 1) % capacity;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (count == 0) return false;
        start = (start + 1) % capacity; //move the start pointer up, and if it goes past the end of the array, it wraps around to the beginning
        //we modify start because queue is fifo, so beginning of the queue is what is popped out.
        count --;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[start];
    }
    
    int Rear() {
    if(isEmpty()){
            return -1;
        }
        return arr[(end - 1 + capacity) % capacity]; //why this works, if end is at the beginning of the array, end - 1 will be -1, but we can add capacity to it, and then mod by capacity, it will wrap around to the end of the array, which is the rear of the queue.
    }
    
    bool isEmpty() {
        return (count == 0);
    }
    
    bool isFull() {
        return (count == capacity);
    }
    private:
    vector<int> arr;
    int start;
    int end;
    int count;
    int capacity;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

