// 287. Find the Duplicate Number
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int duplicate(vector<int> nums){
    for(int i=0;i<nums.size();++i){
        int index = abs(nums[i]);
        if(nums[index]<0){
            return index;
        }
        else{
            nums[index] = -nums[index];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums {1,3,4,2,2};
    int ans = duplicate(nums);
    cout<<ans;
    return 0;
}