#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=281 lang=cpp
 *
 * [281] Zigzag Iterator
 */

// @lc code=start
class ZigzagIterator {
vector<int> res;
int currIdx = 0;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        res.resize(v1.size() + v2.size(), 0);
        int currPtrV1 =0;
        int currPtrV2 = 0;
        int resIdx = 0;
        while(currPtrV1 < v1.size() && currPtrV2 < v2.size()){
            if(resIdx % 2 == 0){
                res[resIdx] = v1[currPtrV1];
                resIdx++;
                currPtrV1++;
            }
            else{
                res[resIdx] = v2[currPtrV2];
                resIdx++;
                currPtrV2++;
            }
        }
        if(currPtrV1 < v1.size()){
            while(currPtrV1 < v1.size()){
                res[resIdx] = v1[currPtrV1];
                resIdx++;
                currPtrV1++;
            }
        }
        else{
            while(currPtrV2 < v2.size()){
            res[resIdx] = v2[currPtrV2];
            resIdx++;
            currPtrV2++;
            }
        }
    }

    int next() {
        return res[currIdx++];
    }

    bool hasNext() {
        if(currIdx >= res.size()) return false;
        else return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

