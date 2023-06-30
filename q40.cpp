// Spiral Matrix I

#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

vector<int> spiral(vector<vector<int>> nums){
    vector<int> ans;
    int m = nums.size();
    int n = nums[0].size();
    int top = 0;
    int left = 0;
    int bottom = m-1;
    int right = n-1;

    while(top<=bottom && left<=right){
        //moving right
        for(int i=left;i<=right;++i){
            ans.push_back(nums[top][i]);
        }
        top++;

        //moving down
        for(int i=top;i<=bottom;++i){
            ans.push_back(nums[i][right]);
        }
        right--;

        //moving left
        if(top<=bottom){
            for(int i=right;i>=left;--i){
                ans.push_back(nums[bottom][i]);
            }
            bottom--;
        }

        //moving up
        if(left<=right){
            for(int i=bottom;i>=top;--i){
                ans.push_back(nums[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> nums = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
    };

    vector<int> ans =  spiral(nums);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }


    return 0;
}