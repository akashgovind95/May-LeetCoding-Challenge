/*
Flood Fill
==========
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. 
Replace the color of all of the aforementioned pixels with the newColor.
At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]],sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void fillColorHelper(vector<vector<int>>& image, int currRow, int currCol, int totalRows, int totalCols, int originalColor, int newColor){
        if(currRow>=totalRows || currRow<0 || currCol>=totalCols || currCol<0 || image[currRow][currCol]!=originalColor)
            return;
        
        image[currRow][currCol] = newColor;
        fillColorHelper(image,currRow+1,currCol,totalRows,totalCols,originalColor,newColor);
        fillColorHelper(image,currRow-1,currCol,totalRows,totalCols,originalColor,newColor);
        fillColorHelper(image,currRow,currCol+1,totalRows,totalCols,originalColor,newColor);
        fillColorHelper(image,currRow,currCol-1,totalRows,totalCols,originalColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty())
            return image;
        int totalRows = image.size();
        int totalCols = image[0].size();
        if(image[sr][sc]==newColor)
            return image;
        fillColorHelper(image,sr,sc,totalRows,totalCols,image[sr][sc],newColor);
        return image;
    }

    void PrintImage(vector<vector<int>> image){
        for(auto row : image){
            for(auto col : row)
                cout<<col<<" ";
            cout<<endl;
        }
    }
};

int main(){

    vector<vector<int>> image = {{0,0,0},{0,1,1}};
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    cout<<"Before flood fill:"<<endl;
    Solution().PrintImage(image);
    Solution().floodFill(image,sr,sc,newColor);
    cout<<"after flood fill:"<<endl;
    Solution().PrintImage(image);
}