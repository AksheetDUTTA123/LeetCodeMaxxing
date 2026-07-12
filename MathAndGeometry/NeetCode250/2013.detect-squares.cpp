#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2013 lang=cpp
 *
 * [2013] Detect Squares
 */

// @lc code=start
class DetectSquares {
private:
    int counts[1001][1001] = {0}; //counts[x][y] = number of points at (x,y)
    std::vector<pair<int, int>> points; //store all points added so we can iterate through them when counting squares
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        if(counts[point[0]][point[1]] == 0){
            points.push_back({point[0], point[1]}); //only add to points vector if this is the first time we are adding this point
        }
        counts[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int totalSquares = 0;
        int x1 = point[0];
        int y1 = point[1];

        for(auto point : points){
            int x2 = point.first;
            int y2 = point.second;

            if(abs(x1 - x2) != abs(y1 - y2) || (x1 == x2 && y1 == y2)) continue; //if the points are not diagonal from each other, or if they are the same point, skip

            totalSquares += counts[x2][y1] * counts[x1][y2] * counts[x2][y2]; //the number of squares formed by these two points is the product of the number of points at the other two corners of the square, which are (x2, y1) and (x1, y2), and the number of points at (x2, y2) which is the diagonal point
        }
        return totalSquares;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

