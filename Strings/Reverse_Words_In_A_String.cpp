#include<bits/stdc++.h>

string reverseString(string &s){
               istringstream iss(s);
        vector<string> words;
        string word;
        while(iss>>word){
            words.insert(words.begin(),word);
        }
        string ans = "";
        for(int i=0; i<words.size(); i++){
            ans += words[i];
            if(i!=words.size()-1){
                ans += " ";
            }
        }   
    return ans; 

}