#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    void backtracking(vector<vector<int>>& image, int sr, int sc, int color, int origColor){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;

        if(image[sr][sc] != origColor) return;

        image[sr][sc] = color;
        backtracking(image, sr+1, sc, color, origColor);
        backtracking(image, sr-1, sc, color, origColor);
        backtracking(image, sr, sc + 1, color, origColor);
        backtracking(image, sr, sc - 1, color, origColor);
        return;
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color) backtracking(image, sr, sc, color, image[sr][sc]); //if the fill color is the same as current, then we dont need to do anything, otherwise we will end up in an infinite loop of trying to 
        //fill the same color over and over again, so we can just check if the fill color is the same as the current color at the starting pixel, and if it is, then we can just return the image without doing anything, otherwise we can call the backtracking function to fill the image with the new color
        return image;
    }
};
// @lc code=end

