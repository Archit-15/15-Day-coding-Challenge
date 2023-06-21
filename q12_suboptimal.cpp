// VVI: When we sort a 2*2 vector then it gets  sorted accoridn to the firt element. if the first
// element is equal then they are sorted according to the 2nd element.
// {3,4},{1,2},{3,5},{2,4},{1,5} is sorted into -> {1,2},{1,5},{2,4},{3,4},{3,5}

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!ans.empty() && end <= ans.back()[1])   //back keyword returns the last element in the
        {               // vector, if it is a 2d array then it will return the last row and we can
            continue;   //access columns using simple indexing
        }
        for (int j = i + 1; j < n; ++j)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(intervals);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[0].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}