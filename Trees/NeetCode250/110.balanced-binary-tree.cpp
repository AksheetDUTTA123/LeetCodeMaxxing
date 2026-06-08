#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int getHeight(TreeNode* root){
        //this is where postorder traversal comes in, because you need to calculate the height of the left and right child of the root node before you can calculate the height of the root node, because the height of the root node is the maximum height of the left and right child of the root node plus one,
        // so you need to calculate the height of the left and right child of the root node before you can calculate the height of the root node

        if (root == nullptr){
            return 0;
        }
        int left = getHeight(root -> left); //recursively call the left side of the tree, this will return the height of the left child of the root node
        if (left == -1) return -1; //call this like an early exit, if the left child of the root node is not balanced, then whole tree is not balanced, just return -1 and this will go through the entire recursive stack and return -1 for all the nodes, this will allow you to easily check if the tree is balanced or not, because if the getHeight function returns -1, 
        //then it means that the tree is not balanced, so you can return false in the isBalanced function, otherwise you can return true in the isBalanced function
        int right = getHeight(root -> right);
        if (right == -1) return -1;
        if(abs(left - right) > 1){
            return -1; //at this moment, this is the detection of the first unbalanced node, if the height difference between the left and right child of the root node is greater than one, then it means that the tree is not balanced, so you can return -1 to indicate that the tree is not balanced.
        }
        return 1 + max(left,right);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        int height = getHeight(root); //call it on the root node, and if -1 returned, not balanced, if any other number returned, then it is balanced and we get the height of the tree
        if(height == -1){
            return false;
        }
        return true;
    }
};
// @lc code=end

