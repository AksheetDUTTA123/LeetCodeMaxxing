#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        while(!q.empty()){
            int currSizeQ = q.size();
            double currSum = 0;
            for(int i = 0; i < currSizeQ; i++){
                auto top = q.front();
                q.pop();
                currSum += (double) top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            res.push_back((double) (currSum / currSizeQ));
        }
        return res;
    }
};
// @lc code=end

