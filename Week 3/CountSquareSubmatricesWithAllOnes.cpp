/*
Count Square Submatrices with All Ones
======================================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        for( int i = 0; i < m; i++ )
            for( int j = 0; j < n; j++ ) {  
                if(i>0 && j>0 && matrix[i][j]==1)
                    matrix[i][j] = min(matrix[i - 1][j], min(matrix[i - 1][j - 1], matrix[i][j - 1])) + 1;
                result += matrix[i][j];
            }
        return result;
    }
};

int main(){

    vector<vector<int>> matrix ={{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    cout<<Solution().countSquares(matrix); //Expected op: 15


}