#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
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
//postorder traversal, need to deal with leaves first before dealing with the root
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return nullptr;

        if(root -> left) root -> left = removeLeafNodes(root->left, target);
        if(root -> right) root -> right = removeLeafNodes(root->right, target);
        if(root->left == nullptr && root->right == nullptr && root->val == target){
            return nullptr; //if leaf node and the value of the leaf node is equal to the target, then we can delete the leaf node by returning nullptr, this will allow us to easily delete the leaf node, because when we return nullptr,
            // it will be assigned to the left or right child of the parent node, which will effectively delete the leaf node from the tree
        }
        return root;
    }
};
// @lc code=end

