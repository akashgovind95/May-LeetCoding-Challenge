/*
Contiguous Array
================
URL: Contiguous Array
https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3341/

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution{
public:
	int findMaxLength(vector<int> nums){
        unordered_map<int,int> m;
        int sum=0;
        int maxLen = 0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==0?-1:1;
            if(m.count(sum)>0)
                maxLen = max(maxLen, i-m[sum]);
            else
                m[sum]=i;
        }
        return maxLen;
	}
};

int main(){
    cout<<Solution().findMaxLength({0,1,0});

}
