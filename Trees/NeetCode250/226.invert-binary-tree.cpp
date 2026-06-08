#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return root;
        }
        TreeNode* temp = root -> right; //need to store temporary variable to store the right child of the root node,
        // because you need to swap the left and right child of the root node, so you need to store the right child in a temporary variable, so you can assign it to the left child after you have assigned the left child to the right child
        root -> right = root -> left;
        root -> left = temp;
        invertTree(root->left); //after you have swapped the left and right child of the root node, 
        //you need to recursively call the function on the left and right child of the root node, because you need to 
        //invert the left and right child of the root node, so you need to recursively call the function on the left and right child of the root node, 
        //this will allow you to invert the left and right child of the root node, 
        //and then return the root node after you have inverted the left and right child of the root node
        invertTree(root->right);
        return root;
    }
};
// @lc code=end

