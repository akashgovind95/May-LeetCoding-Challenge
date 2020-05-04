/*
Number Complement
=================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/

Solution
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 
*/
#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int num) {
          if(num==0)
        return 1;
      int numberOfBits = ceil(log(num)/log(2));
      int ans = 0;
      for(int i=0;i<numberOfBits;i++)
        if((1<<i & num)==0)
          ans = ans | 1<<i;
      return ans;
    }
};

int main(){
    
    cout<<Solution().bitwiseComplement(5)<<endl; //OP: 2
    cout<<Solution().bitwiseComplement(7)<<endl; //OP: 0
    cout<<Solution().bitwiseComplement(10)<<endl; //OP: 5
    return 0;
}