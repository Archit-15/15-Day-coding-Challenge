#include<iostream>
#include<map>
#include<vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); ++i)
    {
        mpp[nums[i]] = mpp[nums[i]] + 1;
    }
    for (auto &it : mpp)
    {
        if (it.second > nums.size() / 2)
        {
            return it.first;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1,2,2,2,2,2,3,4};
    int ans = majorityElement(nums);
    cout<<ans;
    return 0;
}