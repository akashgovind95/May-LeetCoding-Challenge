/*
Remove K Digits
================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

#include<iostream>
using namespace std;
class Solution {
public:
string removeKdigits(string num, int k) {
    int n  = num.size();
    if(k>=n)return "0";
    string s = "";
    for(auto i : num){
        while(s.size() && s.back()>i && k){ s.pop_back(); k--;}
        if(i=='0'){
            if(s.size()!=0)
                s.push_back(i);
        }
        else
            s.push_back(i);
    }
    while(k--)
        s.pop_back();
    return s.length() != 0 ? s:"0";
}

};

int main(){
    cout<<Solution().removeKdigits("1432219",3)<<endl;
    cout<<Solution().removeKdigits("10200",1)<<endl;
    cout<<Solution().removeKdigits("12345",2)<<endl;
}