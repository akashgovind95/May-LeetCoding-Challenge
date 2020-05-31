/*
K Closest Points to Origin
==========================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3345/

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
(Here, the distance between two points on a plane is the Euclidean distance.)
You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

Example 1:
Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
*/
#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

class point{
    public:
        int x,y;
        float dis;
        point(int x,int y){
            this->x=x;
            this->y=y;
            float dis = sqrt(pow(x,2)+pow(y,2));
            this->dis=dis;
        }
    
};

struct comparator { 
    bool operator()(point const& p1, point const& p2){ 
        return p1.dis < p2.dis; 
    } 
};
class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>> points, int K) {
        
        priority_queue<point, vector<point>, comparator> pq;
        vector<vector<int>> res;
        for(auto i: points){
            point obj(i[0],i[1]);
            if(pq.size()<K)
                pq.push(obj);
            else if(pq.top().dis > obj.dis){
                pq.push(obj);
                pq.pop();
            }
        }
        
        while(pq.size()!=0){
            point obj = pq.top();
            pq.pop();
            res.push_back({obj.x,obj.y});
        }
        
        return res;
        
        
    }
};

int main(){
    vector<vector<int>> res = Solution().kClosest({{1,3},{-2,2}},1);
    for(auto i : res)
        cout<<i[0]<<" "<<i[1];
    cout<<endl;
}