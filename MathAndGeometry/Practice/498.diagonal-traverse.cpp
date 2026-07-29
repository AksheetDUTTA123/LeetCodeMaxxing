#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int diagCtr = 0; //if even, reverse and 
        int r = 0; 
        int c = 0;
        while(r <= mat.size() - 1 && c <= mat[0].size() - 1){
            res.push_back(mat[r][c]);
            if((r + c) % 2 == 0){
                if(c == mat[0].size() - 1){
                    r++;
                }
                else if(r == 0){
                    c++;
                }
                else{
                    r--;
                    c++;
                }
            }
            else{
                if(r == mat.size() - 1){
                    c++;
                }
                else if (c == 0){
                    r++;
                }
                else{
                    r++;
                    c--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

