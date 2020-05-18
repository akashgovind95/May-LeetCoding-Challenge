/*
Permutation in String
=====================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3333/
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
 
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    bool comp(vector<int> &s1map,vector<int> &s2map,string &s1){
        for(auto i : s1){
            if(s1map[i-'a']!=s2map[i-'a'])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size())
            return false;
        
        int s1Size = s1.size();
        int s2Size = s2.size();
        int toAdd,toRem;
        vector<int> s1map(26,0);
        vector<int> s2map(26,0);
        
        for(auto i : s1)
            s1map[i-'a']++;
        
        for(int i =0;i<s1Size;i++)
            s2map[s2[i]-'a']++;
        if(comp(s1map,s2map,s1))
            return true;
        
        for(int i=1;i<s2Size-s1Size+1;i++){
            
            toAdd=i+s1Size-1;
            toRem=i-1;
            s2map[s2[toRem]-'a']--;
            s2map[s2[toAdd]-'a']++;
            
            if(comp(s1map,s2map,s1))
                return true;
        }
        
        return false;
    }
};

int main(){
    vector<string> s1 = {"ab","ab"};
    vector<string> s2 = {"acccdcba","a"};
    for(int i=0;i<s1.size();i++){
        cout<<"Case: "<<i<<endl;
        cout<<"s1: "<<s1[i]<<endl;
        cout<<"s2: "<<s2[i]<<endl;
        cout<<"Contains permutation? Ans: "<<Solution().checkInclusion(s1[i],s2[i])<<endl;
    }
}