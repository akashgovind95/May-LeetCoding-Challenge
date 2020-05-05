/*
First Unique Character in a String
==================================

URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/

Solution
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
 public:
     int firstUniqChar(string s) {
         vector<int> v;
         for(int i = 0;i<26;i++)
             v.push_back(0);
         for(auto i : s){
             v[i - 'a']++;
         }
         for(int i=0;i<s.size();i++){
             if(v[s[i]-'a']==1) return i;
         }
         return -1;
     }
 };

 int main(){
     cout<<Solution().firstUniqChar("leetcode")<<endl;
     cout<<Solution().firstUniqChar("loveleetcode")<<endl;
 }