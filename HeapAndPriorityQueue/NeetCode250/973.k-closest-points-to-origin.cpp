#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
//this first solution is not optimal, it is O(nlogn) because we are sorting the entire array of points, we can optimize this to O(nlogk)
// by using a max heap of size k to store the k closest points, and then we can iterate through the points and compare the distance of each point to the distance of the farthest point in the heap, if the distance of the current point is less than the distance of the farthest point in the heap, 
//then we can remove the farthest point from the heap and add the current point to the heap, this way we can maintain a heap of size k that contains the k closest points, and at the end we can return the points in the heap as the result
// class Solution {
// private:
//     static bool comparator(const vector<int>& v1, const vector<int>& v2){
//         int dist1 =((v1[0] * v1[0]) + (v1[1] * v1[1]));
//         int dist2 = ((v2[0] * v2[0]) + (v2[1] * v2[1])); //dont use sqrt, doesnt make difference and decimals would cause rounding issues
        
//             return dist1 < dist2; //return true, strict weak ordering
//         }

// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         std::sort(points.begin(), points.end(), comparator); //sort with comparator

//         return vector<vector<int>>(points.begin(), points.begin() + k);       
//     }
// };

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparator = [](const vector<int>& v1, const vector<int>& v2){
            int dist1 =((v1[0] * v1[0]) + (v1[1] * v1[1]));
            int dist2 = ((v2[0] * v2[0]) + (v2[1] * v2[1])); //dont use sqrt, doesnt make difference and decimals would cause rounding issues
        
            return dist1 < dist2; //return true, strict weak ordering
        };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> pq; //this is how to declare a priority queue with a custom comparator,
        // we need to use decltype to specify the type of the comparator, and we need to pass the comparator as an argument to the constructor of the priority queue, 
        //this will allow us to use the custom comparator to compare the elements in the priority queue, and we can use this priority queue to store the k closest points, and then we can iterate through the points and compare
        // the distance of each point to the distance of the farthest point in the heap, if the distance of the current point is less than the distance of the farthest point in the heap, then we can remove the farthest point 
        //from the heap and add the current point to the heap, this way we can maintain a heap of size k that contains the k closest points, and at the end we can return the points in the heap as the result
        for(vector<int> point : points){
            pq.push(point);
            if(pq.size() > k){ //if size greater than k, remove the farthest point from the heap, which is the point at the top of the heap, 
            //because we are using a max heap, the point at the top of the heap is the point with the largest distance from the origin, so if we have more than 
            //k points in the heap, we can remove the point at the top of the heap to maintain a heap of size k that contains the k closest points
                pq.pop();
            }
        }
        
        vector<vector<int>> result;
        while(pq.size() > 0){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;     
    }
};
// @lc code=end

