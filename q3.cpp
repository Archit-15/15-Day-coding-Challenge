#include<iostream>
#include<vector>
using namespace std;

void printvect(vector<int> nums){
    for(int i=0;i<nums.size();++i){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a,int *b){
    int temp =  *a;
    *a = *b;
    *b = temp;
}

void sortColors(vector<int>& nums) {
    int low = 0;
    int high = nums.size()-1;
    int mid = 0;
    while(mid<=high){
        if(nums[mid]==0){
            swap(&nums[low],&nums[mid]);
            ++mid;
            ++low;
        }
        else if(nums[mid]==1){
            ++mid;
        }
        else if(nums[mid]==2){
            swap(&nums[high],&nums[mid]);
            --high;
        }
    }
}

int main()
{
    vector<int> nums = {0,1,0,2,1,0,1,2};
    cout<<"Printing vector before sorting: "<<endl;
    printvect(nums);
    sortColors(nums);
    cout<<"Printing vector after sorting: "<<endl;
    printvect(nums);
    return 0;
}