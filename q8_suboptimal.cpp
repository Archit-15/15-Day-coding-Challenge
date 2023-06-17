// 1. twosum

#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> fin;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                fin = {i, j};
                return fin;
            }
        }
    }
}

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans; 
    ans = twoSum(nums,target);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}