#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int n){
    vector<int> divisor;
    for(int i=1;i<(n/2);i++){
        if(n%i==0){
            divisor.push_back(i);
        }
    }
    return divisor;
}

int randomNum(int n){
    vector<int> div = divisors(n);
    int x = div.size();
    int idx = rand()%x; // number generating from 0 to x-1. That will behave as a index of the given calculated vector.
    return div[idx]; 
}
int main(){
    cout<<"Enter the number "<<endl;
    int n;cin>>n;
    cout<<"Random number will be "<<randomNum(n)<<endl;
    cout<<"Random number will be "<<randomNum(n)<<endl;
    cout<<"Random number will be "<<randomNum(n)<<endl;
    return 0;
}