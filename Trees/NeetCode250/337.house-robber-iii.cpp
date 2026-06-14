#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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

//this question is a postorder traversal, because you need to calculate the maximum amount of money that can be robbed for the left and right child of the current node before you can calculate the maximum amount of money that can be robbed for the current node, because the maximum amount of money that can be robbed for the current node is the maximum of the two cases, if we rob the current node, then we can only add the value of the current node to the maximum amount of money that can be robbed for the left and right child of the current node when they are not robbed, if we do not rob the current node, then we can add the maximum amount of money that can be robbed for the left and right child of the current node, because if we do not rob the current node, then we can rob both the left and right child of the current node, so we can add the maximum amount of money that can be robbed for
// the left and right child of the current node
class Solution {
private:
    std::pair<int,int> robHelper(TreeNode* root){
        if (root == nullptr){
            return {0, 0};
        }
        //simple trick to remember, store {if robbed, if skipped}
        //and add .second if we rob the current node, because the second is if we skip the left and right children, which is needed when we rob the current node

        //the left number in the pair is the max amnt of money that can be robbed if the current node is not robbed,
        // and the right number in the pair is the max amnt of money that can be robbed if the current node is robbed, this will allow us to easily calculate the max amnt of money that can be robbed for the current node, because if the current node is not robbed, then we can rob both the left and right child of the current node, so we can add the max amnt of money that can be robbed for the left and right child of the current node, if the current node is robbed, then we cannot rob the left and right child of the current node, so we can only add the value of the current node to the max amnt of money that can be robbed for the left and right child of the current node when they are not robbed

        std::pair<int, int> left = robHelper(root->left); //this will return a pair of integers, the first integer is the maximum amount of money that can be robbed if the current node is not robbed, and the second integer is the maximum amount of money that can be robbed if the current node is robbed, 
        //this will allow us to easily calculate the maximum amount of money that can be robbed for the current node, because if the current node is not robbed, then we can rob both the left and right child of the current node, so we can add the maximum amount of money that can be robbed for the left and 
        //right child of the current node, if the current node is robbed, then we cannot rob the left and right child of the current node, so we can only add the value of the current node to the maximum amount of money that can be robbed for the left and right child of the current node when they are not robbed
        std::pair<int, int> right = robHelper(root->right);
        int robCurrent = root->val + left.second + right.second; //if we rob the current node, then we cannot rob the left and right child of the current node, so we can only add the value of the current node to the maximum amount of money that can be robbed for the left and right child 
        //of the current node when they are not robbed

        //root->val is current node, and we add left.second and right.second because
        //left.first is the max amount of money if we rob that node, and left.second is the max amount of money if we skip that node
        //we add .second because root->val is the house we rob, and left.second and right.second is the max amount of money we can rob if we skip the left and right child of the current node, because we cannot rob the left and right child of the current node if we rob the current node, so we can only add the value 
        //of the current node to the maximum amount of money that can be robbed for the left and right child of the current node when they are not robbed
        int notRobCurrent = max(left.second, left.first) + max(right.second, right.first);
        //left.first and right.first is the max amount of money that can be robbed if we rob the left and right child of the current node.
        //there is a case where we rob the left child and not rob the right child, and there is a case where we rob the right child and not rob the left child, so we need to take the maximum of the two cases, so we can add the maximum amount of money that can be robbed for the left and right child of the current node, because if we do not rob the current node, then we can rob both the left and right child of the current node, so we can add the maximum amount of money that can be robbed for the left and right child of the current node 
        return {robCurrent, notRobCurrent};
    }
public:
    int rob(TreeNode* root) {
        std::pair<int, int> result = robHelper(root);
        return std::max(result.first, result.second); //the maximum amount of money that can be robbed for the current node is the maximum of the two cases, if we rob the current node, then we can only add the value of the current node to the maximum amount of money that can be robbed for the left and right child of the current node when they are not robbed, if we do not rob the current node, then we can add the maximum amount of money that can be robbed for the left and right child of the current node, because if we do not rob the current node, then we can rob both the left and right child of the current node, so we can add the maximum amount of money that can be robbed for the left and right child of the current node
        //this is for the root node, this is like the last step of the postorder traversal, because we need to calculate the maximum amount of money that can be robbed for the left and right child of the current node before we can calculate the maximum amount of money that can be robbed for the current node, because the maximum amount 
        //of money that can be robbed for the current node is the maximum of the two cases, if we rob the current node, then we can only add the value of the current node to the maximum amount of money that can be robbed for the left and right child of the current node when they are not robbed, if we do not rob the current node, then we can add the maximum amount of money that can be robbed for the left and right child of the current node, because if we do not rob the current node, then we can rob both the left and right child of the current node, so we can add the maximum amount of money that can be robbed for the left and right child of the current node
    }
};
// @lc code=end

