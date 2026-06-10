#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
private:
    long long prev = LLONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        if(!isValidBST(root->left)) return false;

        if(root->val <= prev)   return false;
        prev = root -> val;

        if(!isValidBST(root->right)) return false;

        return true;
    }
     
};
// @lc code=end

