// 4 sum
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> f4sum(vector<int> nums, int target){
    vector<vector<int>> result;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();++i){
        for(int j=i+1;j<nums.size();++j){
            int target2 = target - nums[i] - nums[j];
            int front = j+1;
            int back = nums.size()-1;
            while(front<back){
                int twosum = nums[front]+nums[back];
                if(twosum<target2){
                    front++;
                }
                else if(twosum>target2){
                    back--;
                }
                else{
                    vector<int> quad(4,0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[front];
                    quad[3] = nums[back];
                    result.push_back(quad);
                    while(front<back && nums[front]==quad[2]){
                        ++front;
                    }
                    while(front<back && nums[back]==quad[3]){
                        --back;
                    }
                }
            }
            while(j+1<nums.size() && nums[j]==nums[j+1]){
                j++;
            }
        }
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            ++i;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> ans = f4sum(nums,0);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[0].size();++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}