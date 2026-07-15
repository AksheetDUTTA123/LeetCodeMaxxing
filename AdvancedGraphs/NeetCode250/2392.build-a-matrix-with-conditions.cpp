#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2392 lang=cpp
 *
 * [2392] Build a Matrix With Conditions
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        //we do topological sort on both rowConditions and colConditions, and then we place the numbers in the matrix according to their row and column positions
        vector<vector<int>> rowAdj(k+1), colAdj(k+1);
        vector<int> rowIndegree(k + 1, 0), colIndegree(k + 1, 0);
        vector<vector<int>> res(k, vector<int>(k, 0));
        for(auto condition : rowConditions){
            rowAdj[condition[0]].push_back(condition[1]);
            rowIndegree[condition[1]]++;
        }
        for(auto condition : colConditions){
            colAdj[condition[0]].push_back(condition[1]);
            colIndegree[condition[1]]++;
        }

        queue<int> rowQ, colQ;
        vector<int> rowOrder, colOrder;
        int rowCtr = 0;
        int colCtr = 0;
        for(int i = 1; i < rowIndegree.size(); i++){
            if(rowIndegree[i] == 0) rowQ.push(i);
        }
        for(int i = 1; i < colIndegree.size(); i++){
            if(colIndegree[i] == 0) colQ.push(i);
        }
        while(!rowQ.empty()){
            auto front = rowQ.front();
            rowQ.pop();
            rowOrder.push_back(front);
            rowCtr++;
            for(int neighbor : rowAdj[front]){
                rowIndegree[neighbor]--;
                if(rowIndegree[neighbor] == 0) rowQ.push(neighbor);
            }

        }

        while(!colQ.empty()){
            auto front = colQ.front();
            colQ.pop();
            colOrder.push_back(front);
            colCtr++;
            for(int neighbor : colAdj[front]){
                colIndegree[neighbor]--;
                if(colIndegree[neighbor] == 0) colQ.push(neighbor);
            }
        }
        if(rowCtr != k || colCtr != k) return {};
        vector<int> colPos(k + 1, 0);
        for(int i = 0; i < colOrder.size(); i++){
            colPos[colOrder[i]] = i; //store the column position of each number in colPos, so we can place the numbers in the matrix according to their column positions
            //example: if colOrder = [3, 1, 2], then colPos[3] = 0, colPos[1] = 1, colPos[2] = 2, so we can place the numbers in the matrix according to their column positions
        }
        for(int i = 0; i < rowOrder.size(); i++){
            //roworder stores the numbers in the order they should be placed in the rows, so we can iterate through rowOrder and place the numbers in the matrix according to their column positions stored in colPos
            int rowNum = rowOrder[i]; //get the number that should be placed in the current row, and then get its column position from colPos, and place it in the matrix
            int colNum = colPos[rowNum]; //get the column position of the number that should be placed in the current row, and then place it in the matrix
            res[i][colNum] = rowNum;
        }
        return res;
    }
};
// @lc code=end

