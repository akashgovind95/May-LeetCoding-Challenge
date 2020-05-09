/*
Valid Perfect Square
====================

URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/

Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Output: true

Example 2:
Input: 14
Output: false

*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0)
            return false;
        if(num==1)
            return true;
        int start = 0;
        int end = num/2;
        while(start<=end){
            double mid = (start+end)/2;
            if(mid==num/mid)
                return true;
            if(mid>num/mid)
                end=mid-1;
            else
                start=mid+1;
        }
        return false;
    }
};

int main(){
    cout<<Solution().isPerfectSquare(16)<<endl;
    cout<<Solution().isPerfectSquare(5)<<endl;
}