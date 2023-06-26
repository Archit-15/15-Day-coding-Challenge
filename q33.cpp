// 485. Max Consecutive Ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int num=0;
        int maxnum=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1){
                num++;
            }
            else{
                num = 0;
            }
            maxnum = max(num,maxnum);
        }
        return maxnum;
    }
};