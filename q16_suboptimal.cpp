//  Majority Element II n/3

#include <iostream>
#include <vector>
#include<map>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int minmum = nums.size() / 3 + 1;
    vector<int> ans;
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); ++i)
    {
        mpp[nums[i]] = mpp[nums[i]] + 1;
        if (minmum == mpp[nums[i]])
        {
            ans.push_back(nums[i]);
        }
        if (ans.size() == 2)
        {
            break;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 2, 3}; 
    vector<int> ans = majorityElement(nums);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}