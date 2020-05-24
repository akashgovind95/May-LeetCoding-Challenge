/*
Construct Binary Search Tree from Preorder Traversal
====================================================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/

Return the root node of a binary search tree that matches the given preorder traversal.
(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  
Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)
It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:
Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Constraints:
1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode * const_bst(vector<int> &vec, int &idx, int parentValue ){ //pv=parent_value
        
        int currVal = vec[idx];
        TreeNode * node = new TreeNode(currVal);
        
        if(idx+1<vec.size() && vec[idx+1]<currVal){
            idx++;
            node->left=const_bst(vec,idx,currVal);
        }
        if(idx+1<vec.size() && vec[idx+1]>currVal && vec[idx+1]<parentValue){
            idx++;
            node->right=const_bst(vec,idx,parentValue);
        }        
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return const_bst(preorder, idx, INT_MAX);
    }

    void printLevelOrderTraversal(TreeNode * root){
        if(root==NULL){
            cout<<"Tree is empty";
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                cout<<front->val<<" ";
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
        } 
    }
};

int main(){
    vector<int> preorder = {8,5,1,7,10,12};
    TreeNode * root = Solution().bstFromPreorder(preorder);
    Solution().printLevelOrderTraversal(root);


}