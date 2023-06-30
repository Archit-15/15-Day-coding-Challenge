// 42. Trapped rain water


class Solution {
public:
        int trap(vector<int>& height) {
        int n = height.size();
        int maxleft[n];
        int maxright[n];
        maxleft[0] = height[0];
        for(int i=1;i<height.size();++i){
            maxleft[i] = max(height[i],maxleft[i-1]);
        }
        maxright[n-1] = height[n-1];
        for(int i=n-2;i>=0;--i){
            maxright[i] = max(maxright[i+1],height[i]);
        }
        int watertrapped = 0;
        for(int i=0;i<height.size();++i){
            watertrapped += min(maxright[i],maxleft[i]) - height[i];
        }
        return watertrapped;
    }
};