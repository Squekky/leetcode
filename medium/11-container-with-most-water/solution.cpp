#include <vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        if (height.size() == 2) {
            return min(height[0], height[1]);
        }

        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int width = right - left;
            int water_contained = width * min(height[left], height[right]);
            if (water_contained > max_water) max_water = water_contained;
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_water;
    }
};