#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
//this is a preorder traversal question, the way you could tell here is that you need to check the value of the current node before you check the left and right child, because if the value of the current node is not the same,
// then you can return false immediately without checking the left and right child, so this is a preorder traversal question, because you need to check the value of the current node before you check the left and right child, if it was a postorder traversal question, 
//then you would need to check the left and right child before you check the value of the current node, and if it was an inorder traversal question, then you would need to check the left child before you check the value of the current node, and then check the right child after you check the value of the current node
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true; //empty tree

        if((p == nullptr || q == nullptr) || p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end

