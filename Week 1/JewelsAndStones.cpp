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