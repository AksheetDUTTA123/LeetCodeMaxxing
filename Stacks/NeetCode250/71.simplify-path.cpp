#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir;
        std::stringstream ss(path);
        std::string token;
        while(getline(ss, token, '/')){
            // dir.push(token);            
            if(token.empty() || token == "."){
                continue; // . means we are in current directory, dont add to stack
            }
            else if(token == ".."){
                if(!dir.empty()){
                    dir.pop(); //pop because go back to parent.
                }
            }
            else{
                dir.push(token); //normal dir, add to dir stack
            }
        }
        vector<string> parts;
        while(!dir.empty()) {
            parts.push_back(dir.top());
            dir.pop();
        }
        
        string result = "";
        for(int i = parts.size() - 1; i >= 0; i--) {
            result += "/" + parts[i];
        }
    return result.empty() ? "/" : result; 
    }
};
// @lc code=end

