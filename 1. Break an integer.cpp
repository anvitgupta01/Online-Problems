/*
Problem statement :
Given a number n, the task is to break n in such a way that multiplication of its parts is maximized. 
*/

/*
Approach :
Now we know from maxima-minima concept that, If an integer need to break in two parts, then to maximize their product those part should be equal. Using this concept lets break n into (n/x) x’s then their product will be x(n/x), now if we take derivative of this product and make that equal to 0 for maxima, we will get to know that value of x should be e (base of the natural logarithm) for maximum product. As we know that 2 < e < 3, so we should break every Integer into 2 or 3 only for maximum product. 
Next thing is 6 = 3 + 3 = 2 + 2 + 2, but 3 * 3 > 2 * 2 * 2, that is every triplet of 2 can be replaced with tuple of 3 for maximum product, so we will keep breaking the number in terms of 3 only.

In short, procedure to get maximum product is as follows – Try to break integer in power of 3 only and when integer remains small (<5) then use brute force. 
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n){
    if(n==0 || n==1)
    {
        return n;
    }
    if(n==2){
        return 1;
    }
    if(n==3){
        return 2;
    }
    int q = n/3; int r = n%3;
    if(r==0){
        return pow(3,q);
    }
    else if(r==1){
        return (pow(3,q-1)*4);
    }
    return (2*pow(3,q));
}

int main(){
    int n;cin>>n;
    cout<<solve(n)<<endl;
}