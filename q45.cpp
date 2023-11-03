// 33. Search in Rotated Sorted Array
#include<iostream>
#include<vector>
using namespace std;

int RotatedSearch(vector<int> nums, int target){
    int low = 0;
    int high = nums.size()-1;
    while(low<=high){
        int mid = (low + high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[low] <= nums[mid]){
            if(nums[low] <= target && nums[mid] > target){
                high = mid -1;
            }
            else{
                low  = mid + 1;
            }
        }
        else{
            if(nums[mid]< target && nums[high]>=target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {42,45,47,1,2,3,4};
    int ans = RotatedSearch(nums,47);
    cout<<ans;
    return 0;
}