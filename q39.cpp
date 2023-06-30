#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> plusone(vector<int> nums){
    int n = nums.size();
    int carry = 1;
    for(int i = n-1;i>=0;--i){
        int ans = nums[i] + carry;
        carry = ans/10;
        nums[i] = ans%10;
    }
    if(carry!=0){
        reverse(nums.begin(),nums.end());
        nums.push_back(carry);
        reverse(nums.begin(),nums.end());
    }
    return nums;
}

int main()
{
    vector<int> nums = {1,9,9};

    nums = plusone(nums);

    for(int i=0;i<nums.size();++i){
        cout<<nums[i];
    }

    return 0;
}