 /*
 Find All Anagrams in a String
 =============================
 URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
            return {};
        vector<int> res;
        vector<int> pmap(26,0);
        vector<int> smap(26,0);
        
        for(auto i: p)
            pmap[i-'a']++;
        
        for(int i=0;i<p.size();i++)
            smap[s[i]-'a']++;
        if(pmap==smap)
            res.push_back(0);
        
        for(int i=1;i<s.size()-p.size()+1;i++){
            int p1 = i+p.size()-1;
            int p2 = i-1;
            smap[s[p1]-'a']++;
            smap[s[p2]-'a']--;
            if(pmap==smap)
                res.push_back(i);
        }
        
        return res;
        
    }
};

int main(){
    string s = "abcab";
    string p = "abc";
    vector<int> res = Solution().findAnagrams(s,p);
    cout<<"S: "<<s<<endl;
    cout<<"P: "<<p<<endl;
    cout<<"Indices found: ";
    for(auto i : res){
        cout<<i<<" ";
    }
}

