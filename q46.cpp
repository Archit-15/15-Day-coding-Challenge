// Subset Sums
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void rec(int arr[],int N,int ind,int sum,vector<int> &ans){
    if(ind==N){
        ans.push_back(sum);
        return ;
    }
    //Picking the index
    rec(arr,N,ind+1,sum+arr[ind],ans);

    //Not picking index
    rec(arr,N,ind+1,sum,ans);
}

vector<int> SubsetSum(int arr[],int N){
    vector<int> ans;
    rec(arr,N,0,0,ans);
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{   
    int N = 2;
    int ans[] = {2,3};
    vector<int> res = SubsetSum(ans,N);
    for(int i=0;i<res.size();++i){
        cout<<res[i]<<" ";
    }
    return 0;
}