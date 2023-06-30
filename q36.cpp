//15. 3Sum
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ThreeS(vector<int> nums){
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();++i){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j = i+1;
        int k = nums.size() - 1;
        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp = {nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                while(j<k && nums[j]==temp[1]){
                    j++;
                }
                while(j<k && nums[k]==temp[2]){
                    k--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = ThreeS(nums);
    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[0].size();++j){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}