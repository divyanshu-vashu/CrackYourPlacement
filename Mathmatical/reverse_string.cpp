#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
public:
    string rev(string s1){
        vector<string> arr;
        string ans;
        string temp="";
        for(char c : s1){
            if(c==' '){
                arr.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }
        if(temp.length()!=0){
            arr.push_back(temp);
        }

        reverse(arr.begin(),arr.end());
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        ans+=arr[i];
        ans+=' ';
    }
    ans+=arr[n-1];
    return ans;
    }

    



};


using namespace std;

int main(){
    string s1="the man is solid";
    solution obj;
    string s2=obj.rev(s1);
    cout<<s2;
    return 0;
}