#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // if(root == nullptr){
        //     return ans;
        // }
        // vector<int> leftside = postorderTraversal(root->left);
        // ans.insert(ans.end(), leftside.begin(), leftside.end());
        // vector<int> rightside = postorderTraversal(root->right);
        // ans.insert(ans.end(), rightside.begin(), rightside.end());
        // ans.push_back(root->val);
        // return ans;
         stack<TreeNode*> treeNodes; //for the iterative design, you need a stack to keep track of the nodes you have visited, 
        //this is because you need to go back up the tree after you have visited the left side, and then go to the right side, so you need to keep track of the nodes you have visited in order to go back up the tree
        TreeNode* curr = root; //start at the root node
        TreeNode* lastVisited = nullptr; //keep track of the last visited node, this is important because you need to know when you have visited the right side of the tree, so you can visit the root node after you have visited the right side, you can visit the root node,
        // but if you have not visited the right side, you cannot visit the root node, because you need to visit the right side before you can visit the root node in postorder traversal

     while(curr != NULL || !treeNodes.empty()){
        while(curr != NULL){ //while not at the end of the left side, keep going left and pushing the nodes into the stack
            treeNodes.push(curr);
            curr = curr -> left;
        }
        
        curr = treeNodes.top(); //get the top of the stack, this is the node you need to visit, because you have already visited the left side, so now you need to visit the root node
        if(curr -> right == NULL || curr -> right == lastVisited) {
            //if the right child is null or the right child is the last visited node, then you can visit the root node
        ans.push_back(curr->val);
        lastVisited = curr; //update the last visited node to the current node, because you have just visited the current node, so you need to update the last visited node to the current node, this will allow you to keep track of the last visited node, so you can know when you have visited the right side of the tree
        treeNodes.pop();
        curr = nullptr; //after visiting the root node, you need to set the current node to null, because you have already visited the current node, so you need to set the current node to null, this will allow you to go back up the tree and visit the next node in the stack, which is the parent node of the current node, this will allow you to visit the parent node after you have visited the left and right side of the tree
    }
    else{
        curr = curr -> right; //if the right child is not null and the right child is not the last visited node, then you need to go to the right side of the tree, so you need to set the current node to the right child of the current node,
    }
    }
    
        return ans;
            }

};
// @lc code=end

