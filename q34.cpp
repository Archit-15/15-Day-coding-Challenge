//268. Missing Number
// There can be twon solutions one is O(n^2) and other is O(2n) with extra space O(n) due to hashing

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;     //Sum of n natural numbers
        int actsum = 0;
        for(int i=0;i<nums.size();++i){
            actsum = actsum + nums[i];
        }
        return sum - actsum;
    }
};