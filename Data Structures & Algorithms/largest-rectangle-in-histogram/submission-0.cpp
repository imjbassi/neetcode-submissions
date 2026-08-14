class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;  // holds INDICES, heights at those indices stay increasing
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            // Use height 0 as a sentinel when i == n, forcing everything left to resolve
            int currHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && heights[st.top()] > currHeight) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};