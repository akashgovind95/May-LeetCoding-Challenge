/*
Implement Trie (Prefix Tree)
===========================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/

Implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:
You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

#include<iostream>
#include<vector>
using namespace std;

class trieDS{
    public:
        int ch;
        bool isWord;
        vector<trieDS*> next;
        
    trieDS(char ch){
        this->ch=ch;
        isWord=false;
        next = vector<trieDS*>(26,NULL);
    }
    
};
class Trie {
public:
    /** Initialize your data structure here. */
    
    trieDS * root;
    Trie() {
        root = new trieDS('#'); 
    }
    
    void insert(string word) {
    
        trieDS * traverser = root;
        
        for(auto i : word){
            if(traverser->next[i-'a']!=NULL)
                traverser=traverser->next[i-'a'];
            else{
                trieDS * temp = new trieDS(i);
                traverser->next[i-'a'] = temp;
                traverser = temp;
            }
        }
        traverser->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        trieDS * traverser = root;
        
        for(auto i : word){
            if(traverser->next[i-'a']==NULL)
                return false;
            else
                traverser = traverser->next[i-'a'];
        }
        
        return traverser->isWord;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        trieDS * traverser = root;
        
        for(auto i : prefix){
            if(traverser->next[i-'a']==NULL)
                return false;
            else
                traverser = traverser->next[i-'a'];
        }
        
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    Trie *obj;
    vector<string> funcToCall = {"Trie","insert","search","search","startsWith","insert","search"};
    vector<string>  valueToPass = {"","apple","apple","app","app","app","app"};
    for(int i =0;i<funcToCall.size();i++){

        if(funcToCall[i]=="Trie")
            obj = new Trie();
        else if(funcToCall[i]=="insert")
            obj->insert(valueToPass[i]);
        else if(funcToCall[i]=="search")
            cout<<"Is '"<<valueToPass[i]<<"' in the trie? Ans: "<<obj->search(valueToPass[i])<<endl;
        else if(funcToCall[i]=="startsWith")
            cout<<"Are there words starting with '"<<valueToPass[i]<<"'? Ans: "<<obj->startsWith(valueToPass[i])<<endl;

    }

}