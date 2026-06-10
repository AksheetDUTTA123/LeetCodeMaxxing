#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr; //in terms of traversal, this is a inorder traversal question, because you need to check the left and right child of the current node before you check the value of the current node, because if the value of the current node 
        //is between the values of p and q, then you can return the current node as the ancestor, but if you check the value of the current node before you check the left and right child, then you might miss the ancestor if it is not between the values of p and q, so this is an inorder traversal question, because you need to check the left and right child of the current node before you check the value of the current node
        TreeNode* curr = root;
        while(curr != nullptr){ //keep traversing until condition met, this is the iterative solution, you can also do this recursively by checking the same conditions in the recursive calls
        if(p->val > curr->val && q->val > curr -> val){ //if both p and q are greater than what we are checking
        //we know that the ancestor will be on the right side of the tree, so we need to move to the right child of the current node, because the ancestor will be on the right side of the tree, 
        //so we need to move to the right child of the current node, this will allow us to keep traversing down the tree until we find the ancestor
            curr = curr -> right;
        }
        else if(p->val < curr -> val && q -> val < curr -> val){
            curr = curr -> left;
        }
        else{
            return curr; //if we reach here, it means that we have found the ancestor, because if p and q are on different sides of the current node, then the current node is the ancestor, because it is the lowest node that has both p and q as descendants,
            // so we can return the current node as the ancestor
        }
        }
        return curr;
    }
};
// @lc code=end

