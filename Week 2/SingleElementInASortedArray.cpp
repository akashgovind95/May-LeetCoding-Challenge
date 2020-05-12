/*

Single Element in a Sorted Array
================================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. 
Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
*/

#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int> nums) {
        
        int start = 0;
        int end = nums.size()-1;
        while(start<end){
            int mid=(start+end)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) 
                return nums[mid];
            
            if(nums[mid]==nums[mid-1])
                mid--;
            
            if(mid%2==0)
                start=mid+2;
            else
                end=mid-1;
        }
        return nums[start];
        
    }
};

int main(){

    cout<<Solution().singleNonDuplicate({1,1,2,3,3,4,4,8,8})<<endl;
    cout<<Solution().singleNonDuplicate({3,3,7,7,10,11,11})<<endl;
    

}