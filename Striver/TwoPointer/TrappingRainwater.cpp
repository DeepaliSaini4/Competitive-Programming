class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int n = height.size();
        vector<int>suffix(n);
        suffix[0] = 0;
        for(int i=1;i<n;i++){
            suffix[i] = max(height[i-1],suffix[i-1]);
        }
        vector<int>prefix(n);
        prefix[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            prefix[i] = max(height[i+1],prefix[i+1]);
        }
        int water = 0;
        for(int i=1;i<n-1;i++){
            int trapped=(min(prefix[i],suffix[i]))-height[i];
            if(trapped>0) water+=trapped;
        }
        return water;

    }
};
