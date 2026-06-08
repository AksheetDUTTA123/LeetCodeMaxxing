#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    //THIS QUESTION IS DIFFICULT, REVIEW THIS CLEARLY
    Node* constructTree(vector<vector<int>>& grid, int r1, int c1, int r2, int c2){
        bool same = true;
        //check the corners to find if the n by n grid is a subtree or not
        for(int i = r1; i <= r2; i++){
            for (int j = c1 ; j <= c2; j++){
                if (grid[i][j] != grid[r1][c1]){
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }
        if(same){
            return new Node(grid[r1][c1] == 1, true); //val is 1, isLeaf is true, because if all the values in the grid are the same, then this is a leaf node, and the value of the node is the value of the grid, which is either 0 or 1,
            // so we can just check if it is equal to 1 to get the boolean value for the node
        }

        //what if not the same, this is where we need to divide the grid into 4 subgrids and recursively call the constructTree function on each subgrid,
        // and then create a new node with the value of the current grid, which is not a leaf node, and the children of the node are the nodes returned by the recursive calls on the subgrids

        int midRow = r1 + (r2 - r1) / 2;
        int midCol = c1 + (c2 - c1) / 2;

        Node* root = new Node(true, false); //given in the problem, we know that the value of the node is true, and the node is not a leaf node, because we are going to divide the grid into 4 subgrids, so we know that this node is not a leaf node, and the value of the node is true, because it does not matter what the value of the node is, 
        //because it is not a leaf node, so we can just set it to true

        root->topLeft = constructTree(grid, r1, c1, midRow, midCol);
        root->topRight = constructTree(grid, r1, midCol + 1, midRow, c2);
        root->bottomLeft = constructTree(grid, midRow + 1, c1, r2, midCol);
        root->bottomRight = constructTree(grid, midRow + 1, midCol + 1, r2, c2);

        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructTree(grid, 0, 0, grid.size() -1, grid[0].size() - 1);
    }
};
// @lc code=end

