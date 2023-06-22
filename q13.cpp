//128. Longest Consecutive Sequence

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int last = INT_MIN;
    int cnt = 0;
    int longest = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] - 1 == last)
        {
            last = nums[i];
            cnt = cnt + 1;
        }
        else if (nums[i] != last)
        {
            cnt = 1;
            last = nums[i];
        }
        longest = max(cnt, longest);
    }
    return longest;
}

int main()
{
    vector<int> cons {100,4,200,1,3,2};
    int ans = longestConsecutive(cons);
    cout<<ans;
    return 0;
}