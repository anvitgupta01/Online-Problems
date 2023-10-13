/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "God Ding"
Output: "doG gniD"
*/

#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    vector<string> v;
    for (int i = (s.length() - 1); i >= 0; i--)
    {
        string word = "";
        while (i >= 0 && s[i] != ' ')
        {
            word += s[i];
            i--;
        }
        v.push_back(word);
    }

    string ans = "";
    for (int i = (v.size() - 1); i >= 0; i--)
    {
        ans += v[i];
        if (i != 0)
        {
            ans += " ";
        }
    }
    return ans;
}

int main(){
    string s;
    getline(cin,s);
    cout<<reverseWords(s)<<endl;
    return 0;
}