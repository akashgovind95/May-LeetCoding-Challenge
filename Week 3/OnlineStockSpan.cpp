#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class StockSpanner {
public:
    stack<int> prices, weights;
    StockSpanner() {
    }
    
    int next(int price) {
        int w =1;
        while(!prices.empty() && price>=prices.top()){
            prices.pop();
            w+=weights.top();
            weights.pop();
        }
        prices.push(price);
        weights.push(w);
        return w;
    }
  
};

int main(){
    StockSpanner obj;
    vector<string> command = {"StockSpanner","next","next","next","next","next","next","next"};
    vector<vector<int>> input = {{},{100},{80},{60},{70},{60},{75},{85}};
    for(int i=0;i<command.size();i++){
        if(command[i]=="next")
            cout<<obj.next(input[i][0])<<endl;
    }

}