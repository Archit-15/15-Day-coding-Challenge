// Activty Selection (N jobs in a room)

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct Meeting{
    int start;
    int end;
    int position;
};

bool comp(Meeting A,Meeting B){
    if(A.end < B.end) return true;
    else if(A.end > B.end) return false;
    else if(A.position < B.position) return true;
    return false;
}

int ActivitySelection(int start[],int end[],int n){
    struct Meeting ms[n];
    for(int i=0;i<n;++i){
        ms[i].start = start[i];
        ms[i].end = end[i];
        ms[i].position = i+1;
    }
    sort(ms,ms+n,comp);
    int ans = 1;
    int limit = ms[0].end;
    for(int i=1;i<n;++i){
        if(ms[i].start>limit){
            limit = ms[i].end;
            ans++;
        }
    }
    return ans;
}

int main()
{
    int N = 6;
    int start[] = {1,3,0,5,8,5};
    int end[] =  {2,4,6,7,9,9};

    int ans = ActivitySelection(start,end,N);
    cout<<ans;
    return 0;
}