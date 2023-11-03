// Job Sequencing Problem

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};

bool comp(Job A, Job B){
    return A.profit > B.profit;
}

vector<int> JobSequencing(Job arr[],int n){
    int profit = 0;
    int jobs = 0;
    sort(arr,arr+n,comp);
    int maxD = arr[0].dead;
    for(int i=0;i<n;++i){
        maxD = max(arr[i].dead,maxD);
    }
    int deadlines[maxD+1];
    for(int i=0;i<maxD+1;++i){
        deadlines[i] = -1;
    }
    for(int i=0;i<n;++i){
        for(int j = arr[i].dead;j>0;--j){
            if(deadlines[j]==-1){
                deadlines[j] = i;
                jobs++;
                profit = profit + arr[i].profit;
                break;
            }
        }
    }
    vector<int> ans = {jobs,profit};
    return ans;
}


int main()
{
    int N = 4;
    struct Job j[N];
    j[0].id = 1;
    j[0].dead = 4;
    j[0].profit = 20; 

    j[1].id = 2;
    j[1].dead = 1;
    j[1].profit = 10; 


    j[2].id = 3;
    j[2].dead = 1;
    j[2].profit = 40; 


    j[3].id = 4;
    j[3].dead = 1;
    j[3].profit = 30; 

    vector<int> ans =  JobSequencing(j,N);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}