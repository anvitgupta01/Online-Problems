/*
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

// Solution Code :
#include <bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t)
{
    if (!s.size())
    {
        return true;
    }

    int j = 0;
    for (int i = 0; i < t.length(); i++)
    {
        if (j < s.size() && t[i] == s[j])
        {
            j++;
        }
    }
    if (j != s.size())
    {
        return false;
    }
    return true;
}