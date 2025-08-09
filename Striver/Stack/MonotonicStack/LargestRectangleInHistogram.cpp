class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int maxarea = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || heights[s.top()]>=heights[i])){
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;  
                maxarea = max(maxarea, height * width);
            }
           if (i < n) s.push(i);
        }
        return maxarea;
    }
};
