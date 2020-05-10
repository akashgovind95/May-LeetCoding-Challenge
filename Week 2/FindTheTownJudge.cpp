/*
Find the Town Judge
===================

URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3325/

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:
1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.
3. There is exactly one person that satisfies properties 1 and 2.

You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.
If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

Example 1:
Input: N = 2, trust = [[1,2]]
Output: 2

Example 2:
Input: N = 3, trust = [[1,3],[2,3]]
Output: 3

Example 3:
Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1

Example 4:
Input: N = 3, trust = [[1,2],[2,3]]
Output: -1

Example 5:
Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<int>inDegree(N+1);
        vector<int>outDegree(N+1);
        
        for(int i=0;i<trust.size();i++){
            inDegree[trust[i][1]]++;
            outDegree[trust[i][0]]++;
        }
        
        for(int i=1;i<=N;i++)
            if(inDegree[i]==N-1 && outDegree[i]==0)
                return i;
        return -1;
        
    }
};

int main(){
    vector<vector<int>> trust = {{1,3},{2,3}};
    cout<<"Town Judge: "<<Solution().findJudge(3,trust)<<endl;
    trust = {{1,2},{2,3}};
    cout<<"Town Judge: "<<Solution().findJudge(3,trust)<<endl;
}