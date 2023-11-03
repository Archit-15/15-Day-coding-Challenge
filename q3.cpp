#include<iostream>
#include<vector>
using namespace std;

void printvect(vector<int> nums){
    for(int i=0;i<nums.size();++i){
        cout<<nums[i]<<" ";
    }
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(vector<int> &nums){
    int low = 0;
    int high = nums.size()-1;
    int mid = 1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(&nums[mid],&nums[low]);
            ++low;
            ++mid;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else if(nums[mid]==2){
            swap(&nums[mid],&nums[high]);
            --high;
        }
    }
}

int main()
{
    vector<int> nums = {1,1,0,0,2,1,2,1,1,0};
    sort012(nums);
    printvect(nums);
    return 0;
}