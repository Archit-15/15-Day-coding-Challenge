// We will take 2 elements as element 1 and element 2 and we will check for both of them at once. If both
// of them are preseent n/3 times that means together they are present as n/3 + n/3 times. Which means
// no other element can cancel them on their own
// Majority Element II n/3

#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int minmum = nums.size() / 3 + 1;
    vector<int> ans;
    int cnt1 = 0;
    int cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (cnt1 == 0 && el2 != nums[i])
        {
            el1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0 && el1 != nums[i])
        {
            el2 = nums[i];
            cnt2 = 1;
        }
        else if (el1 == nums[i])
        {
            cnt1++;
        }
        else if (el2 == nums[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    int fincnt1 = 0;
    int fincnt2 = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (el1 == nums[i])
        {
            fincnt1++;
        }
        if (el2 == nums[i])
        {
            fincnt2++;
        }
    }
    if (fincnt1 >= minmum)
    {
        ans.push_back(el1);
    }
    if (fincnt2 >= minmum)
    {
        ans.push_back(el2);
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

int main()
{
    vector<int> nums = {3, 2, 3}; 
    vector<int> ans = majorityElement(nums);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}