#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
//     MinStack() {
//         //dont have to do anything here
//     }
    
//     void push(int val) {
//         stk.push(val);
//         if(pastMin.empty() || pastMin.top() >= val){
//             pastMin.push(val);
//         }
//     }
    
//     void pop() {

//         int top = stk.top();
//         stk.pop();
//         if(pastMin.top() == top){
//             pastMin.pop();
//         }
//     }
    
//     int top() {
//         return stk.top();
//     }
    
//     int getMin() {
//         return pastMin.top();
//     }

// private:
// stack<int> stk;
// stack<int> pastMin;

    MinStack() {
        //dont have to do anything here
    }
    
    void push(int val) {
        if (val <= min || stk.empty()){
            min = val;
        }
        stk.push({val, min});
        // if(pastMin.empty() || pastMin.top() >= val){
        //     pastMin.push(val);
        // }
    }
    
    void pop() {
        stk.pop();
        if(!stk.empty()){
            min = stk.top().second;
        }
        else{
            min = INT_MAX;
        }
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }

private:
stack<pair<int, int>> stk;
int min = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

