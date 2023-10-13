/*
An array is monotonic if it is either monotone increasing or monotone decreasing.
An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
Given an integer array nums, return true if the given array is monotonic, or false otherwise.
*/

#include <bits/stdc++.h>
using namespace std;
bool isMonotonic(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return true;
    }
    bool check = true;
    bool check1 = true;

    if (is_sorted(nums.begin(), nums.end()) == false)
    {
        check = false;
    }

    reverse(nums.begin(), nums.end());

    if (is_sorted(nums.begin(), nums.end()) == false)
    {
        check1 = false;
    }

    return check || check1;
}

// O(N) approach :
bool isMonotonic(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return true;
    }

    // 0 means nothing, 1 means increasing and -1 means decreasing.
    int direction = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            if (direction == 0)
            {
                direction = 1;
            }
            else if (direction == -1)
            {
                return false;
            }
        }
        else if (nums[i] < nums[i - 1])
        {
            if (direction == 0)
            {
                direction = -1;
            }
            else if (direction == 1)
            {
                return false;
            }
        }
    }
    return true;
}