/*
Maximum Sum Circular Subarray
=============================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3330/

Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.
Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:
Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3

Example 2:
Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

Example 3:
Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4

Example 4:
Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3

Example 5:
Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> A) {
        if(A.size() == 0) return 0;
        int sum = A[0];
        int maxSoFar = A[0];
        int maxTotal = A[0];
        int minSoFar = A[0];
        int minTotal = A[0];
        for(int i = 1; i< A.size();i++){
            maxSoFar = max(A[i], maxSoFar + A[i]);
            maxTotal = max(maxTotal, maxSoFar);
            
            minSoFar = min(A[i], minSoFar + A[i]);
            minTotal = min(minTotal, minSoFar);
            sum += A[i];

        }
        if(sum == minTotal) return maxTotal;
        return max(sum - minTotal, maxTotal);
    }
};

int main(){
    cout<<Solution().maxSubarraySumCircular({5, -3, 5});
}