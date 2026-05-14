#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
// public:
//     MyStack() {
//         //not necessary to do anything here
//     }
    
//     void push(int x) {
//         q2.push(x);
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1,q2);
//     }
    
//     int pop() {
//         int val =  q1.front();
//         q1.pop();
//         return val;
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         return (q1.empty() && q2.empty());
//     }
// private:
// std::queue<int> q1;
// std::queue<int> q2; //maybe treat this as the top

public:
    MyStack() {
        //not necessary to do anything here
    }
    
    void push(int x) {
        q1.push(x);
        for(int i = 0; i < q1.size()-1; i++){
            int val = q1.front();
            q1.pop();
            q1.push(val);
        }
    }
    
    int pop() {
        int val =  q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return (q1.empty());
    }
private:
std::queue<int> q1; //only one queue
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

