#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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

private: //this question is a postorder traversal question, we need to deal with the left and right subtrees 
//before dealing with the root node, because we need to calculate the maximum path sum of the left and right subtrees before we can calculate 
//the maximum path sum of the root node
int globalMax = INT_MIN;
    int pathFromSubTree(TreeNode* root){
        if(root == nullptr) return 0;

        int leftSum = max(0, pathFromSubTree(root->left)); //get the leftSum of the leftSubtree, ignore if negative
        int rightSum = max(0, pathFromSubTree(root->right));
        int bridgeSum = root->val + leftSum + rightSum; //calculate the path sum of the path that goes through the root node, which is the value of the root node plus the leftSum and rightSum
        //the bridge tells us the maximum path sum of the path that goes through the root node, which is the value of the root node plus the leftSum and rightSum, we need to compare this with the globalMax,
        // because this could be the maximum path sum of the entire tree

        //bridgeSum is if this is where we are allowing the path to split, we can only split once, we can only split at one node, which is the root node in this case, we cannot split at any other node in the left or right subtrees, 
        //because that would violate the definition of a path, which is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them, and a path can only split at one node, which is the root node in this case
        globalMax = max(globalMax, bridgeSum);
        return root->val + max(leftSum, rightSum); //we return this because this is the maximum path sum of the path that goes from the root node to any leaf node in the subtree, 
        //we return this to the node above, because we assume that the node above will have the option to split, if the node above decides to split, then it will use the leftSum and rightSum that we calculated here, if the node above decides not to split, then it will just use the maximum path sum of the path that goes from the root node to any leaf node in the subtree, which is what we are returning here

    }
public:
    int maxPathSum(TreeNode* root) {
        pathFromSubTree(root); //kick off recursion
        return globalMax; //this is the stored answer
    }
};
// @lc code=end

