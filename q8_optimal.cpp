// 1. twosum

#include<iostream>
#include<vector>
#include<map>
using namespace std;

 vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            int a = nums[i];
            int more = target - a;
            if(mpp.find(more)!=mpp.end()){
                ans =  {i,mpp[more]};
                break;
            }
            mpp[a] = i;
        }
        return ans;
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