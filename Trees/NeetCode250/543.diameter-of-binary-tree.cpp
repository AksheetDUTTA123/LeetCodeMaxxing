#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
int maxDiameter = 0;
int maxDepth(TreeNode* root){
        if (root == nullptr){
            return 0; 
        }

        int leftDepth = maxDepth(root->left); //recursively call the left side of the tree, this will return the maximum depth of the left side of the tree
        int rightDepth = maxDepth(root->right); //recursively call the right side of the tree, this will return the maximum depth of the right side of the tree

        int currentDiameter = leftDepth + rightDepth;
        maxDiameter = max(maxDiameter, currentDiameter);
        return std::max(leftDepth,rightDepth) + 1;

    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        //this is a postorder traversal question, because you need to calculate the maximum depth of the left and right child of the root node before you can calculate the diameter of the tree, 
        //because the diameter of the tree is the maximum depth of the left side of the tree plus the maximum depth of the right side of the tree, so you need to calculate the maximum depth of the left and right child of the root node before 
        //you can calculate the diameter of the tree, so this is a postorder traversal question, because you need to calculate the maximum depth of the left and right child of the root node before you can calculate the diameter of the tree
        maxDepth(root); //call the maxDepth function to calculate the maximum depth of the tree, this will also update the maxDiameter variable with the maximum diameter of the tree,
        // because the diameter of the tree is the maximum depth of the left side of the tree plus the maximum depth of the right side of the tree, so you need to call the maxDepth function to calculate the maximum depth of the tree, and then return the maxDiameter variable after you have calculated the maximum depth of the tree
        return maxDiameter;
    }
};
// @lc code=end

