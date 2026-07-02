#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class UnionFind{
    private:
        vector<int> rank;
        vector<int> parent;

    public:
        UnionFind(int n){
            rank.resize(n, 0);
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int i){
                if(parent[i] == i){
                    return i;
                }
                return parent[i] = find(parent[i]);
        }

        bool unite(int i, int j){
            int rootI = find(i);
            int rootJ = find(j);

            if(rootI == rootJ) return false;

            if(rank[rootI] < rank[rootJ]){
                parent[rootI] = rootJ;
            }
            else if (rank[rootI] > rank[rootJ]){
                parent[rootJ] = rootI;
            }
            else{
                parent[rootJ] = rootI;
                rank[rootI]++;
            }
            return true;
        }
};
//need union find to group emails together, 
//and then sort the emails in each group and add the name to the front of the list of emails for that group.
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToId; //need to map emails to ids, 
        //because we need to use the ids in the union find data structure, 
        //and we need to use the emails to get the name of the account
        unordered_map<string, string> emailToName;
        //need to map emails to names, 
        //because we need to get the name of the account from the email,
        int idCt = 0;
        for(auto account : accounts){
            string name = account[0];
            for(int i = 1; i < account.size(); i++){
                string email = account[i];
                if(emailToId.find(email) == emailToId.end()){
                    emailToId[email] = idCt++;
                    emailToName[email] = name;
                }
            }
        }

        UnionFind dsu(idCt); //DSU the total number of emails found


        for(auto account : accounts){ //for each account,
        // we will union the first email with all the other emails in that account. 
            string firstEmail = account[1];
            int firstId = emailToId[firstEmail];

            for(int i = 2; i < account.size(); i++){
                string nextEmail = account[i];
                int nextId = emailToId[nextEmail];
                dsu.unite(firstId, nextId);
            }
        }

        unordered_map<int, vector<string>> connectedComps; //here, we will map the root id of 
        //each connected component to the list of emails in that component
        //the rootID is the representative of the connected component, 
        //and all emails that have the same rootID are in the same connected component. In other words, the rootID associates all emails that are connected to each other through the union find structure, which is by the name of the account they belong to. 
        //So, if two emails have the same rootID, it means they are connected through the union find structure and belong to the same account.
        for (auto pair : emailToId){
            string email = pair.first;
            int id = pair.second;
            int rootID = dsu.find(id);
            connectedComps[rootID].push_back(email);
        }

        vector<vector<string>> mergedActs;
        for (auto& pair : connectedComps){
            auto& emails = pair.second;
            sort(emails.begin(), emails.end()); //sort vector in lexicographical order
            vector<string> account;

            string name = emailToName[emails[0]]; //get the name of the account from the first email in the sorted list of emails, because all emails in the same connected component have the same name, 
            //so we can just use the first email to get the name of the account.
            account.push_back(name);
            account.insert(account.end(), emails.begin(), emails.end());
            mergedActs.push_back(account);
        }
    return mergedActs;

    }
};
// @lc code=end

