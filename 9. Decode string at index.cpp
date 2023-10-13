/*
You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:
If the character read is a letter, that letter is written onto the tape.
If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
Given an integer k, return the kth letter (1-indexed) in the decoded string.

Example 1:
Input: s = "leet2code3", k = 10
Output: "o"
Explanation: The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".

Example 2:
Input: s = "ha22", k = 5
Output: "h"
Explanation: The decoded string is "hahahaha".
The 5th letter is "h".
*/

#include <bits/stdc++.h>
using namespace std;

string getString(char ch)
{
    string s(1, ch);
    return s;
}
string decodeAtIndex(string s, int k)
{
    if (k == 1)
    {
        return getString(s[0]);
    }
    long long int length = 0;
    int i = 0;

    while (length < k)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            length *= (s[i] - '0');
        }
        else
        {
            length++;
        }
        i++;
    }

    for (int j = (i - 1); j >= 0; j--)
    {
        if (s[j] >= '0' && s[j] <= '9')
        {
            length /= (s[j] - '0');
            k %= length;
        }
        else
        {
            if (k == 0 || k == length)
            {
                return getString(s[j]);
            }
            length--;
        }
    }
    return "";
}