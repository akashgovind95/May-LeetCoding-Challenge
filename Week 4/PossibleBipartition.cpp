/*
Possible Bipartition
=====================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3342/

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.


Example 1:
Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]

Example 2:
Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:
Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 
Constraints:
1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
*/


#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    
    bool bfs(int node, queue<pair<int,int>> &q, unordered_map<int,int> &isVis, unordered_map<int,vector<int>> &haters){
    
        int i=node;
        isVis[i]=1;
        q.push(make_pair(i,1));
                    
        while(!q.empty()){
                
            pair<int,int> temp = q.front();
            q.pop();
    
            for(auto j: haters[temp.first]){
                if(isVis.count(j)>0){
                    if(isVis[j] == temp.second)
                        return false;
                }
                else{
                    int newVal = temp.second==1?0:1;
                    q.push(make_pair(j,newVal));
                    isVis[j]=newVal;
                }
            }
        }
        
        return true;
    
    }
    bool possibleBipartition(int N, vector<vector<int>> dislikes) {
        unordered_map<int,vector<int>> haters;
        unordered_map<int,int> isVis; 
    
        for(auto i : dislikes){
            haters[i[0]].push_back(i[1]);
            haters[i[1]].push_back(i[0]);
        }
        
        queue<pair<int,int>> q;  
        
        for(int i=1;i<=N;i++){
            if(isVis.count(i)==0 && !bfs(i,q,isVis, haters))
                return false;
            
        }
        
        return true;
        
        
    }
};

int main(){

    cout<<Solution().possibleBipartition(5, {{1,2},{2,3},{3,4},{4,5},{1,5}});
}
