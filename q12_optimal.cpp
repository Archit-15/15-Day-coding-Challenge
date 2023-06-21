// 56. Merge overlapping intervals
// time complexity : O(nlogn + n)

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i)
    {
        if (ans.empty() || ans.back()[1] < intervals[i][0])
        {
            ans.push_back(intervals[i]);    //Accessing a 2d vector with just one index will access
        }                                   //the whole row.
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[0].size(); ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}