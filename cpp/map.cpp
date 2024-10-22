#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<char,int> mp;
    string s="hello vashu";
    for(auto i:s){
        if(isalpha(i)){
            mp[i]++;
        }
    }
    for(auto k:mp){
        cout<<k.first<<k.second<<endl;
    }
    return 0;
}