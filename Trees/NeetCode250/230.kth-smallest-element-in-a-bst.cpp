#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    //to optimize, store the size of the left subtree in each node, then you can just compare k with the size of the left subtree to know whether to go left, right, or return the current node, this will allow you to find the kth smallest element in O(log n) time, because you will only need to go down the tree once, and you will not need to do an inorder traversal of the entire tree, this is a very clever optimization that can be done if you are allowed to modify the tree structure, but since we are not allowed to modify the tree structure in this question, we will just do an inorder traversal of the tree and keep track of how many nodes we have visited until we reach the kth smallest node, this will allow us to find the kth smallest node in O(n) time, because we may need to visit all the nodes in the tree in the worst case
    //use of binary search tree properties, we know that the left side of the tree will have smaller values than the root node, and the right side of the tree will have larger values than the root node, so we can use this property to our advantage when doing the inorder traversal, because we want to start from the smallest element and work our way up by then traversing in increasing order, so we can do an inorder traversal of the tree and keep track of how many nodes we have visited until we reach the kth smallest node, this will allow us to find the kth smallest node in O(n) time, because we may need to visit all the nodes in the tree in the worst case
private:
    int result = -1;
    void inorder(TreeNode* root, int &k){
        if (root == nullptr || k == 0) return;

        if(root->left) inorder(root->left, k); //do inorder traversal, go to the leftmost first, we want to start from the smallest element and work our way up by then traversing in increasing order
        k--; //decrement k, because we have visited one more node, so we need to decrement k by 1, this will allow us to keep track of how many nodes we have visited, and when k reaches 0, it means that we have visited the kth smallest node, so we can set the result to the value of the current node and return

        if(k == 0){ //if k is 0, it means that we have visited the kth smallest node, so we can set the result to the value of the current node and return, this will allow us to return the value of the kth smallest node after we have visited it
            result = root -> val;
            return;
        }
        
        inorder(root->right, k); //after we have visited the current node, we need to go to the right side of the tree, because the right side of the tree will have the larger values, so we need to go to the right side of the tree and continue the inorder traversal until we have visited the kth smallest node
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
// @lc code=end

