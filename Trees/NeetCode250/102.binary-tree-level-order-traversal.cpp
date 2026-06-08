#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result; //empty tree, return empty result, needed
        std::queue<TreeNode*> q1; //make a queue that stores for each level, we need first in first out.
        q1.push(root); //start with root
        while(!q1.empty()){
            int nodesInLevel = q1.size(); //at this moment, we know what nodes are in this level, needed for loop
            vector<int> levelNodes; //vector container that holds every node in this level
            for(int i = 0; i < nodesInLevel; i++){
                TreeNode* top = q1.front(); //pop the top and add to nodes in this level
                q1.pop();
                levelNodes.push_back(top -> val);
                if (top->left != nullptr) q1.push(top->left); //add the next levels nodes to the end of the queue, these will then get added for the next level once this level
                //has been added
                if (top->right != nullptr) q1.push(top->right);
            }
            result.push_back(levelNodes); //at the end of the loop, all nodes in that level has been add it, add vector to the ans vector 
            //that holds a vector for each level
        }
        return result;

    }
};
// @lc code=end

