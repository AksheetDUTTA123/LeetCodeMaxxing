#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = INT_MAX;
        int right = INT_MAX;
        if(!root->left && !root->right) return 1; //depth of 1 at leaf node
        if(root-> left) left = minDepth(root->left);
        if(root->right) right = minDepth(root->right);
        return std::min(left, right) + 1;

    }
};
// @lc code=end

