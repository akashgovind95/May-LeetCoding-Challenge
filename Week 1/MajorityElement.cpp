/*
Majority Element
================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int val;
        int half = nums.size()/2;
        for(auto i : nums){
            m[i]++;
            if(m[i]>half)
                return i;
        }
        return 0;
    }
};

int main(){

    vector<int> nums = {3,2,3};
    cout<<Solution().majorityElement(nums)<<endl;

    nums = {2,2,1,1,1,2,2};
    cout<<Solution().majorityElement(nums)<<endl;

    return 0;   
}