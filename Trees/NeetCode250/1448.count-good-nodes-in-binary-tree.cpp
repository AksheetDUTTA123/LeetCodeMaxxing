#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root-> val); //start with the root
    }

private:
    int countGoodNodes(TreeNode* root, int maxSoFar){
        if(root == nullptr) return 0;

        int good = 0;
        if(root ->val >= maxSoFar){
            good = 1; //if it is good, just increment counter by 1, so if a node is good, good always gets incremented by 1 in the recursive call
            maxSoFar = root->val;  //update the max value, future nodes downstream get checked with this
        }
         good += countGoodNodes(root->left, maxSoFar); //this is an idea of preorder traversal, check the root and then check the left and right child, 
         //because you need to check the value of the current node before you check the left and right child, because if the value of the current node is not good, 
         //then you can return 0 immediately without checking the left and right child, so this is a preorder traversal question, because you need to check the value of the current node before you 
         //check the left and right child
        good += countGoodNodes(root->right, maxSoFar);

    return good;



    }
};
// @lc code=end

