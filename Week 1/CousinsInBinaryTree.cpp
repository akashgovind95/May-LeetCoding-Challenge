/*
Cousins in Binary Tree
======================

URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
Return true if and only if the nodes corresponding to the values x and y are cousins.


Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
*/


#include<iostream>
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
    
    pair<int,TreeNode*> getDepthAndParent(TreeNode * root, int x, int depth, int &nodeDepth){
        if(root==NULL)
            return make_pair(-1,root);
        if((root->left && root->left->val ==x) || (root->right && root->right->val ==x)){
            nodeDepth = depth+1;
            return make_pair(nodeDepth,root);
        }
        pair<int, TreeNode *> left = getDepthAndParent(root->left,x,depth+1,nodeDepth);
        pair<int, TreeNode *> right = getDepthAndParent(root->right,x,depth+1,nodeDepth);
        
        if(left.second!=NULL)
            return left;
        return right;
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int nodeDepth = 0;
        pair<int,TreeNode*> DepthAndParentOfx = getDepthAndParent(root,x,0,nodeDepth);
        nodeDepth = 0;
        pair<int,TreeNode*> DepthAndParentOfy = getDepthAndParent(root,y,0,nodeDepth);
        if(DepthAndParentOfx.first==DepthAndParentOfy.first && DepthAndParentOfx.second!=DepthAndParentOfy.second)
            return true;
        return false;
        
    }
};

int main(){

    TreeNode* root = new TreeNode(50); 
    root->left = new TreeNode(30); 
    root->right = new TreeNode(70); 
    root->left->right = new TreeNode(40); 
    root->left->left = new TreeNode(20); 
    root->right->left = new TreeNode(60); 
    root->right->right = new TreeNode(80); 

    int node1 = 20;
    int node2 = 60;
    
    cout<<"Case 1"<<endl;
    cout<<"Node 1:"<<node1<<endl;
    cout<<"Node 2:"<<node2<<endl;
    cout<<"Is Cousin? Ans: "<<Solution().isCousins(root,node1,node2)<<endl;
    
    
    node1 = 20;
    node2 = 40;
    cout<<"Case 2"<<endl;
    cout<<"Node 1:"<<node1<<endl;
    cout<<"Node 2:"<<node2<<endl;
    cout<<"Is Cousin? Ans: "<<Solution().isCousins(root,node1,node2)<<endl;
}

