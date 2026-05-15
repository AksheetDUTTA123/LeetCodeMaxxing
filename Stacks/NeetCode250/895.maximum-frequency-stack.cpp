#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
    int freqNum = ++freq[val];
    maxFreq = max(freqNum, maxFreq);
    stkVal[freqNum].push(val);
    }
    
    int pop() {
    int val = stkVal[maxFreq].top();
    stkVal[maxFreq].pop();
    if(stkVal[maxFreq].empty()){
        maxFreq--;
    }
    freq[val]--;
    return val;
    }
private:
int maxFreq = 0;
unordered_map<int, int> freq;
unordered_map<int, stack<int>> stkVal;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

