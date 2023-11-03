//Combination sum
#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

void helper(vector<int> &candidates,int target,vector<vector<int>> &ans,int ind,vector<int> &ds){
    if(ind == candidates.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return ;
    }
    //Picking the index
    if(candidates[ind]<=target){
        ds.push_back(candidates[ind]);
        helper(candidates,target-candidates[ind],ans,ind+1,ds);
        ds.pop_back();
    }

    //Not picking the index
    helper(candidates,target,ans,ind+1,ds);
}

vector<vector<int>> CombinationSum(vector<int> candidates,int target){
    vector<vector<int>> ans;
    vector<int> ds;
    helper(candidates,target,ans,0,ds);
    return ans;
}

int main()
{
    vector<int> candidates = {2,3,6,7}; 
    int target = 7;
    vector<vector<int>> ans = CombinationSum(candidates,target);
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[0].size();++j){
            cout<<ans[i][j]<<" ";
        }
    }
    return 0;
}