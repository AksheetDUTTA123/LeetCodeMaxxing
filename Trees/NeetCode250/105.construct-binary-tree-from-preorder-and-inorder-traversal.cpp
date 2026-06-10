#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndexMap; //this will allow us to quickly find the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees, this will allow us to quickly find the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees

    TreeNode * buildTreeHelper(vector<int>& preorder, int left, int right){
        if(left > right) return nullptr; //base case for recursion, if the left index is greater than the right index, then it means that there are no nodes in this subtree, so we can return null

        int rootValue = preorder[preorderIndex++]; //get the value of the root node from the preorder traversal, this is important because the first value in the preorder traversal is always the root node, so we can get the value of the root node from the preorder traversal, and then we can use this value to find the index of the root node in the inorder traversal, this will allow us to split the inorder traversal into left and right subtrees

        TreeNode* root = new TreeNode(rootValue); //create a new tree node with the value of the root node

        int inorderIndex = inorderIndexMap[rootValue]; //get the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees, this will allow us to quickly find the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees

        root -> left = buildTreeHelper(preorder, left, inorderIndex - 1); //recursively build the left subtree, this will allow us to build the left subtree of the current root node, this will allow us to build the left subtree of the current root node
        root -> right = buildTreeHelper(preorder, inorderIndex + 1, right); //recursively build the right subtree, this will allow us to build the right subtree of the current root node, this will allow us to build the right subtree of the current root node

        return root; //return the current root node
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0; //reset the preorder index to 0, this is important because we need to start from the first value in the preorder traversal, this is important because the first value in the preorder traversal is always the root node, so we can get the value of the root node from the preorder traversal, and then we can use this value to find the index of the root node in the inorder traversal, this will allow us to split the inorder traversal into left and right subtrees
        for(int i = 0; i < inorder.size(); i++){
            inorderIndexMap[inorder[i]] = i; //build the index map for the inorder traversal, this will allow us to quickly find the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees, this will allow us to quickly find the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees
        }
        
        return buildTreeHelper(preorder, 0, inorder.size() - 1); //call the helper function to build the tree, this will allow us to build the tree from the preorder and inorder traversals, this will allow us to build the tree from the preorder and inorder traversals
    }
};
// @lc code=end

