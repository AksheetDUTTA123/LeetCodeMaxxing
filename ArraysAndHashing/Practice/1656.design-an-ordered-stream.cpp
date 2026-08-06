#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1656 lang=cpp
 *
 * [1656] Design an Ordered Stream
 */

// @lc code=start
class OrderedStream {
private:
    vector<string> res;
    int ptr;
public:
    OrderedStream(int n) {
        res.resize(n);
        ptr = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        res[idKey - 1] = value;
        if(res[ptr].empty()) return ans;
        else{
            while(ptr <= res.size() - 1 && !res[ptr].empty()){
                ans.push_back(res[ptr]);
                ptr++;
            }
            return ans;
        }
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end

