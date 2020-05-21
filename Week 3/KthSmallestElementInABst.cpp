/*
Kth Smallest Element in a BST
=============================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

Constraints:
The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/

#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode * left;
        TreeNode * right;
        TreeNode(int val){
            
            this->val=val;
            left=right=NULL;

        }
};

class Solution {
public:

    TreeNode * createTree(vector<int> & arr, int start, int end){
            
        if(start<=end){
            int mid = (start+end)/2;
            TreeNode* temp = new TreeNode(arr[mid]);
            temp->left = createTree(arr,start,mid-1);
            
            temp->right = createTree(arr,mid+1,end);
            return temp;
        }
        return NULL;
    }
    
    void kTrav(TreeNode * root, int k, vector<int> &res){
        if(root==NULL)
            return;
        kTrav(root->left,k,res);
        if(res.size()==k)
            return;
        res.push_back(root->val);
        kTrav(root->right,k,res);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        kTrav(root,k,res);
        if(k>res.size()){
            cout<<"K greater than the number of elements in the BST"<<endl;
            return -1;
        }
        return res[k-1];
        
    }
};

int main(){
    Solution obj;
    vector<int> input = {1,2,3,4,5,6,7,8,9};
    TreeNode * root = obj.createTree(input,0,input.size()-1); 
    cout<<obj.kthSmallest(root,5);
}




