/*
Sort Characters By Frequency
============================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3337/

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input:
"tree"
Output:
"eert"
Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input:
"cccaaa"
Output:
"cccaaa"
Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input:
"Aabb"
Output:
"bbAa"
Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int> charCount;
        vector<string> charByCount(s.size()+1,"");
        string res = "";
        
        for(auto ch : s)
            charCount[ch]++;
        
        for(auto ch: charCount )
            charByCount[ch.second]+=string(ch.second,ch.first);
        
        for(auto ch : charByCount)
            if(ch.size()!=0)
                res = ch+res;
        
        return res;
        
    }
};

int main(){
    cout<<Solution().frequencySort("aabccc")<<endl; //expected op: cccaab
}