#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=359 lang=cpp
 *
 * [359] Logger Rate Limiter
 */

// @lc code=start
class Logger {
private:
    unordered_map<string, int> logCheck;
public:
    Logger() {
        //dont need to do anything here
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(logCheck.find(message) == logCheck.end()){
            logCheck[message] = timestamp + 10;
            return true;
        }
        else if(logCheck.find(message) != logCheck.end() && logCheck[message] <= timestamp){
            logCheck[message] = timestamp + 10;
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
// @lc code=end

