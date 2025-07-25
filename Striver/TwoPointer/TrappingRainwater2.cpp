class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax = 0,rightmax=0,l=0,r=n-1;
        int water = 0;
        while(l<r){
            if(height[l]<height[r]){
                if(leftmax>height[l]){
                    water += leftmax-height[l];
                }else{
                    leftmax = height[l];
                }
                l++;
            }else{
                if(rightmax>height[r]){
                    water += rightmax-height[r];
                    }else{
                    rightmax = height[r];
                }
                r--;
            }
        }
        return water;

    }
};
