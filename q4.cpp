// 53. Maximum Subarray (Kadane's Algo)
#include<iostream>
#include<vector>
using namespace std;

int kadanes(vector<int> &arr){
    int current_sum = 0;
    int max_sum = INT_MIN;
    for(int i=0;i<arr.size();++i){
        current_sum = current_sum + arr[i];
        if(max_sum<current_sum){
            max_sum = current_sum;
        }
        if(current_sum<0){
            current_sum = 0;
        }
    }
    return max_sum;
}

int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = kadanes(arr);
    cout<<ans;
    return 0;
}