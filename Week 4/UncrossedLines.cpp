/*
Uncrossed Lines
===============
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3340/

We write the integers of A and B (in the order they are given) on two separate horizontal lines.
Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:
A[i] == B[j];

The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.
Return the maximum number of connecting lines we can draw in this way.

Example 1:
Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.

Example 2:
Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3

Example 3:
Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2
 
Note:

1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000

*/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    
    int recursion(int idx1, int idx2, vector<int> &A, vector<int> &B,vector<vector<int>> &dp){
        
        if(idx1==A.size() || idx2==B.size())
            return 0;
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        int res = 0;
        if(A[idx1]==B[idx2])
            res = 1+recursion(idx1+1,idx2+1,A,B,dp);
        else
            res = max(recursion(idx1+1,idx2,A,B,dp),recursion(idx1,idx2+1,A,B,dp));
        return dp[idx1][idx2] = res;  
        
    }

    int iterative(vector<int> &A, vector<int> &B,vector<vector<int>> &dp){

        for(int i=1;i<=A.size();i++){
            for(int j=1;j<=B.size();j++){
                if(A[i-1]==B[j-1])
                    dp[i][j] =1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
            }
        }

        return dp[A.size()][B.size()];

    }


    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        
        /*
        
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,-1));
        return recursion(0,0,A,B,dp);
        */
        
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,0));
        return iterative(A,B,dp);
        
        
    }
};

int main(){
    vector<int> A = {1,3,7,1,7,5};
    vector<int> B = {1,9,2,5,1};
    cout<<"A: ";
    for(auto i : A)
        cout<<i<<" ";
        
    cout<<endl<<"B: ";
    for(auto i : B)
        cout<<i<<" ";

    cout<<endl<<Solution().maxUncrossedLines(A,B);
}