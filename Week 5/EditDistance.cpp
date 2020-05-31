/*
Edit Distance
=============
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3346/

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:
1. Insert a character
2. Delete a character
3. Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int helper(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i==0 || j==0)
            return i+j;
    
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
        
        if(word1[i-1]==word2[j-1])
            ans = helper(i-1,j-1,word1,word2,dp);
        else
            ans = 1 + min(helper(i-1,j-1,word1,word2,dp),min(helper(i-1,j,word1,word2,dp),helper(i,j-1,word1,word2,dp)));
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return helper(word1.size(),word2.size(),word1,word2,dp);
        
    }
};

int main(){
    cout<<Solution().minDistance("horse", "ros");
}

