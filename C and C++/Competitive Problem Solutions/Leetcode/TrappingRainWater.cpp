/*
42. Trapping Rain Water: https://leetcode.com/problems/trapping-rain-water/
*/

/*
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int tw=0;
        int n=height.size();
        vector<int> l(n),r(n);
        if(!height.empty()) {
            l[0]=height[0];
            for(int i=1;i<n;i++)
                l[i]=max(height[i],l[i-1]);
            r[n-1]=height[n-1];
            for(int i=n-2;i>-1;i--)
                r[i]=max(height[i],r[i+1]);
            for(int i=0;i<n;i++)
                tw+=max((min(l[i],r[i])-height[i]),0);
        }
        return tw;
    }
};