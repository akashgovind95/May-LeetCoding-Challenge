/*
**Jewels and Stones**
Leetcode URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0

*/
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        unordered_map<char,int> jewels;
        int count = 0;
        
        for(auto i : J)
            jewels[i]=1;
        for(auto i : S)
            if(jewels.count(i)>0)
                count+=1;
        return count;
        
    }
};

int main(){
    cout<<Solution().numJewelsInStones("aA","aAAbbbb");
    return 0 ;
}