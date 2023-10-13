/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
the smallest in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Constraints:
1 <= s.length <= 104
s consists of lowercase English letters.
*/

// The result can be many possible subsequences, but we have to give the smallest lexicographically subsequence.
#include <bits/stdc++.h>
using namespace std;
string removeDuplicateLetters(string s)
{
    vector<int> lastIndex(26, -1);
    for (int i = 0; i < s.length(); i++)
    {
        lastIndex[s[i] - 'a'] = i;
    }

    vector<bool> vis(26, false);
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (vis[s[i] - 'a'])
        {
            continue;
        }
        while (!st.empty() && i < lastIndex[st.top() - 'a'] && st.top() > s[i])
        {
            vis[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(s[i]);
        vis[s[i] - 'a'] = true;
    }

    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}