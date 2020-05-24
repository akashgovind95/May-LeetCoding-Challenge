/*
Interval List Intersections
===========================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3338/

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
Return the intersection of these two interval lists.
(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  
The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  
For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

 

Example 1:
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
 

Note:
0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& A, vector<vector<int>>& B){
        int i=0,j=0;
        vector<vector<int>> res;
        
        while(i<A.size() && j<B.size())
            if(A[i][0]<B[j][0])
                res.push_back(A[i++]);
            else
                res.push_back(B[j++]);   
        
        while(i<A.size())
            res.push_back(A[i++]);
        
        while(j<B.size())
            res.push_back(B[j++]);
        
        return res;
   
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.size()==0 || B.size()==0)
            return {};
        vector<vector<int>> merged = merge(A,B);
        vector<vector<int>> res;
        
        int i=0,j=1;
        while(j<merged.size()){
            if(merged[i][1]>=merged[j][0] && merged[i][1]>=merged[j][1]){
                res.push_back(merged[j]);
                j++;
            }
            else if(merged[i][1]>=merged[j][0]){
                res.push_back({merged[j][0],merged[i][1]});
                i=j++;
            }
            else
                i=j++;
                
        }
        
        return res;
    }

    vector<vector<int>> intervalIntersectionUsingStack(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.size()==0 || B.size()==0)
            return {};
        vector<vector<int>> merged = merge(A,B);
        vector<vector<int>> res;
        stack<vector<int>> s;
        s.push(merged[0]);
        
        for(int i=1;i<merged.size();i++){
            vector<int> top = s.top();
            if(top[1]>=merged[i][0] && top[1]>=merged[i][1]){
                res.push_back(merged[i]);
            }
            else if(top[1]>=merged[i][0]){
                res.push_back({merged[i][0],top[1]});
                s.top()[1] = merged[i][1];
            }
            else
                s.push(merged[i]);
        }
        return res;
        
    }
};

int main(){
    vector<vector<int>> A = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> B = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> res = Solution().intervalIntersection(A,B);
    for(auto i : res)
        cout<<"["<<i[0]<<","<<i[1]<<"] ";
    cout<<endl;
    res = Solution().intervalIntersectionUsingStack(A,B);
    for(auto i : res)
       cout<<"["<<i[0]<<","<<i[1]<<"] ";
     
}