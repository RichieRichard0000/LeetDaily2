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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,TreeNode*>parent;
        parent[root->val]=nullptr;
        int lvl1=0,lvl2=0;
        int lvl=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->val==x)lvl1=lvl;
                else if(front->val==y)lvl2=lvl;
                if(front->left){
                    parent[front->left->val]=front;
                    q.push(front->left);
                }
                if(front->right){
                    parent[front->right->val]=front;
                    q.push(front->right);
                }
            }
            lvl++;
        }
        if(parent[x]!=parent[y] && lvl1==lvl2)return true;
        return false;
    }
};