/*
Course Schedule
==============
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should
also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    
    bool checkCycle(int idx, vector<vector<int>> &dependancy, vector<bool> &visited, vector<bool> &recursed){
        visited[idx]=true;
        recursed[idx]=true;
        for(auto i : dependancy[idx]){
            if(recursed[i]==true)
                return true;
            else if(visited[i]==false && checkCycle(i,dependancy,visited,recursed))
                return true;
        }
        recursed[idx]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
        
        vector<vector<int>> dependancy(numCourses);
        vector<bool> visited(numCourses,false);
        vector<bool> recursed(numCourses,false);
        for(auto i : prerequisites)
            dependancy[i[0]].push_back(i[1]);
        for(int i=0;i<numCourses;i++)
            if(checkCycle(i,dependancy,visited,recursed))
                return false;
        return true;
        
    }
};

int main(){
    cout<<Solution().canFinish(2, {{1,0},{0,1}})<<endl;
    cout<<Solution().canFinish(3, {{1,0},{0,2}});
}
