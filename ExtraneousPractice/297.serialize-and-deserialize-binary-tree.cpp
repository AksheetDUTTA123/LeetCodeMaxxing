#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string curr = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if(front == nullptr) curr += "#,";
            else{
                curr += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            }
        }
        return curr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#,") return nullptr;
        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto top = q.front();
            q.pop();

            if(getline(ss, item, ',')){
                if(item != "#"){
                    top->left = new TreeNode(stoi(item));
                    q.push(top->left);
                }
            }

            if(getline(ss, item, ',')){
                if(item != "#"){
                    top->right = new TreeNode(stoi(item));
                    q.push(top->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

