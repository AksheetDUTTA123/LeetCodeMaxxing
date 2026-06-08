#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(key > root -> val){
            root -> right = deleteNode(root->right, key);
        }
        else if(key < root -> val){
            root -> left = deleteNode(root->left, key);
        }
        else{
            //here we got to delete a node, how is this done?
            //what if a leaf node, this just becomes a nullptr because nothing below it
            if(root-> left == nullptr){
                TreeNode *temp = root -> right;
                delete root; 
                return temp; //return right child
                
            }
            else if (root -> right == nullptr){
                TreeNode *temp = root -> left;
                delete root;
                return temp; //return left child
            }

            //if node has two children, find the smallest in right subtree (inorder traversal)
            TreeNode* successor = root -> right;
            while(successor->left != nullptr){
                successor = successor->left;
            }

            //now, we have found the smallest in the right subtree;

            root ->val = successor->val; //update current nodes value with the value of the successor we want to update with (smallest in right subtree)

            root ->right = deleteNode(root->right, successor->val); //now we have to go in and delete that value in the right subtree, since we have already updated the root's value.
            //very clever!
        }
        return root;
    }
};
// @lc code=end

