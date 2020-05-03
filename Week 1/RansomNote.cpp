/*
Ransom Note
============

URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/


Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true


*/
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int> m;
        
        for(auto i : magazine)
            m[i]++;
        
        for(auto i: ransomNote)
            if(m[i]--<=0)return false;
        
        return true;
    }
};

int main(){
    
    string s1 = "aa";
    string s2 = "aab";
    cout<<Solution().canConstruct(s1,s2)<<endl;

    s1 = "aa";
    s2 = "ab";
    cout<<Solution().canConstruct(s1,s2)<<endl;

    s1 = "bg";
    s2 = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";
    cout<<Solution().canConstruct(s1,s2)<<endl;

    return 0;
}