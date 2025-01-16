#include <vector>
using namespace std;

// Struggles with large vectors

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        if (height.size() == 2) {
            return min(height[0], height[1]);
        }

        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                // left bar = height[i]
                // right bar = height[j]
                // width = j - i
                int water_contained = (j - i) * min(height[i], height[j]);
                if (water_contained > max_water) max_water = water_contained;
            }
        }
        return max_water;
    }
};