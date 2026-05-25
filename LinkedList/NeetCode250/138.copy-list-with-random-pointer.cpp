#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap; //this is a mapping of old nodes to new nodes, so we can easily assign the next and random pointers in the second pass
        Node* curr = head;
        while(curr){
            Node * newNode = new Node(curr->val); //make a new node with the same value as the current node
            nodeMap[curr] = newNode;// map the current node to the new node that we just made
            curr = curr -> next; //move to the next node in the LL
        }
        curr = head; //reset current back to the beginning of the LL
        while(curr){
            nodeMap[curr]-> next = nodeMap[curr->next]; //assign the next pointer of the new node to the new node that corresponds to the next node of the current node
            nodeMap[curr]->random = nodeMap[curr->random]; //assign the random pointer of the new node to the new node that corresponds to the random node of the current node
            curr = curr -> next;
        }
        return nodeMap[head];
    }
};
// @lc code=end

