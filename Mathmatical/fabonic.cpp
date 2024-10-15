#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    if(n == 1) {
        cout<<1;
        return 0;
    }
    
    if(n == 2) {
        cout<<1 <<" "<< 1;
        return 0;
    }
    
    int a = 1, b = 1, temp;
    cout << 1 << " " << 1 << " ";
    
    for(int i = 2; i < n; i++){
        temp = a + b;
        a = b;
        b = temp;
        cout << temp << " ";
    }
    
    return 0;
}
