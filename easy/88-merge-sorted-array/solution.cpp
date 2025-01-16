#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos_full = m + n - 1;
        int pos_n1 = m - 1;
        int pos_n2 = n - 1;

        while (pos_n1 >= 0 && pos_n2 >= 0) {
            if (nums1[pos_n1] > nums2[pos_n2]) {
                nums1[pos_full] = nums1[pos_n1];
                pos_n1--;
            } else {
                nums1[pos_full] = nums2[pos_n2];
                pos_n2--;
            }
            pos_full--;
        }

        while (pos_n2 >= 0) {
            nums1[pos_full] = nums2[pos_n2];
            pos_n2--;
            pos_full--;
        }
    }
};