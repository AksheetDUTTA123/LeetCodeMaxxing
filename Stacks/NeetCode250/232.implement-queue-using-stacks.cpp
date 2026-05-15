#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
    //solution 1, working but inefficient push
// public:
//     MyQueue() {
//         //dont need to do anything ehre
//     }
    
//     void push(int x) {
//         //say s1 is the main stack
//         while(!s1.empty()){
//             int val = s1.top();
//             s1.pop();
//             s2.push(val);
//         }
//         s1.push(x);
//         while(!s2.empty()){
//             int val = s2.top();
//             s2.pop();
//             s1.push(val);
//         }

//     }
    
//     int pop() {
//         int val = s1.top();
//         s1.pop();
//         return val;
//     }
    
//     int peek() {
//         return s1.top();
//     }
    
//     bool empty() {
//         return s1.empty();
//     }
// private:
// stack<int> s1;
// stack<int> s2;

public:
    MyQueue() {
        //dont need to do anything ehre
    }
    
    void push(int x) {
        input.push(x); //main stack for push, add to input

    }
    
    int pop() {
        if(output.empty()){ //if output empty, move everything from input into output, will be in reverse order
            while(!input.empty()){
                output.push(input.top()); //reverse order so front of stack will be front of the queue
                input.pop();
            }
        }
        int val = output.top(); //this is now the front of the queue, pop off and return
        output.pop(); //only time pop is called is when popping from output stack, so output size can decrease
        return val;
    }
    
    int peek() {
    if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return (output.empty() && input.empty());
    }
private:
stack<int> input; //push
stack<int> output; //pop and peek
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

