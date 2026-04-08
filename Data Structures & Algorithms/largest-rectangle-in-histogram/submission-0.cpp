class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk; //indices
        vector<int> left(n, -1); //indices
        vector<int> right(n, n); //indices

        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            if(!stk.empty())
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        while(!stk.empty()) {stk.pop();}

        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            if(!stk.empty())
            {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        int max_area = 0;
        for(int i=0;i<n;i++)
        {
            left[i]++;
            right[i]--;
            int area = (right[i]-left[i]+1) * heights[i];
            max_area = max(max_area, area);
        }

        return max_area;
    }
};
