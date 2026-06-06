#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     if (root == nullptr) return result; //base case for recursion, if the node is null, return empty vector
    //    vector<int> leftSide = inorderTraversal(root->left); //recursively call the left side of the tree, this will return a vector of the left side of the tree in order
    //    result.insert(result.end(), leftSide.begin(), leftSide.end()); //add the result of the left side to the result vector, remember inorder is left, root, right
    // result.push_back(root->val); //push back the root value to the result vector
    //     vector<int> rightSide = inorderTraversal(root->right); //recursively call the right side of the tree, this will return a vector of the right side of the tree in order
    //     result.insert(result.end(), rightSide.begin(), rightSide.end());
    //     return result;
    //above was recursive solution

    //below is iterative solution

    vector<int> result;
    stack<TreeNode*> treeNodes; //for the iterative design, you need a stack to keep track of the nodes you have visited, 
    //this is because you need to go back up the tree after you have visited the left side, and then go to the right side, so you need to keep track of the nodes you have visited in order to go back up the tree
    TreeNode* curr = root; //start at the root node

    while(curr != NULL || !treeNodes.empty()){
        while(curr != NULL){ //while not at the end of the left side, keep going left and pushing the nodes into the stack
            treeNodes.push(curr);
            curr = curr -> left;
        }
        curr = treeNodes.top(); //get the top of the stack, this is the node you need to visit, because you have already visited the left side, so now you need to visit the root node
        treeNodes.pop();
        result.push_back(curr->val);
        curr = curr -> right; //after visiting the root node, you need to go to the right side, so you need to set the current node to the right child of the current node, 
        //this will allow you to go to the right side of the tree and repeat the process of going left and visiting the nodes until you reach the end of the tree
    }
    return result;
    }
};
// @lc code=end

