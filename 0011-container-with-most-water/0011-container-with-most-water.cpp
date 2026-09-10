class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;  // Left pointer starts from beginning
        int right = height.size() - 1; // Right pointer starts from end
        
        int maxWater = 0;
        // Continue until pointers meet
        while (left < right) {
            int width = right - left;  // Distance between two lines
            int h = min(height[left], height[right]);  // Water level depends on smaller height
            int area = width * h;
            maxWater = max(maxWater, area);

            /*
             If left height is smaller,
             move left pointer because area
             is limited by the smaller height.
            */
            if (height[left] < height[right]) {
                left++;
            }

            /*
             Otherwise move right pointer
             to try finding a taller line.
            */
            else {
                right--;
            }
        }
        return maxWater;
    }
};