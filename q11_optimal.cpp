// Moore's voting algorithm : It beleives the idea that if an element is present >n/2 times , then
// it would be impossible to cancel it and if it does get canceled mid way then it just means that
// all the remaining elements are that elemnt to bring it in majority. If it gets canceled again ,
// then it means it just wasn't the majority element and if some random element gets selected then
// it is checked again

#include<iostream>
#include<map>
#include<vector>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int cnt = 0;
    int el;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (cnt == 0)
        {
            el = nums[i];
            cnt++;
        }
        else if (el == nums[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int cnt1 = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (el == nums[i])
        {
            cnt1++;
        }
    }
    if (cnt1 > nums.size() / 2)
    {
        return el;
    }
    return -1;
}

int main(){
    vector<int> nums = {1,2,2,2,2,2,3,4};
    int ans = majorityElement(nums);
    cout<<ans;
    return 0;
}