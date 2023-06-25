class Solution {
public:
    int addDigits(int num) {
        while(num!=0){
            int sum = 0;
            int temp = num;
            while(temp!=0){
                sum = sum + temp%10;
                temp = temp/10;
            }
            num = sum;
            if(num<10){
                break;
            }
        }
        return num;
    }
};