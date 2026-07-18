#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs) {
        //to optimize, dont even need a stack, just an int tracker works
        stack<string> s;
        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "../" && s.size() == 0) continue;
            else if(logs[i] == "./") continue;
            else if(logs[i] == "../"){
                s.pop();
            }
            else{
                s.push(logs[i]);
            }

        }
        return s.size();
    }
};
// @lc code=end

