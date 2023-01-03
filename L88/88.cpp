#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(nums1.begin(), nums1.end());
        int p0=0, p1=0, p2=0;
        while (p1<m and p2<n) {
            if (tmp[p1]<=nums2[p2]) {
                nums1[p0] = tmp[p1];
                p1++;
            } else {
                nums1[p0] = nums2[p2];
                p2++;
            }
            p0++;
        }
        if (p1<m) {
            for (p1; p1<m; p1++, p0++) {
                nums1[p0] = tmp[p1];
            }
        } else {
            for (p2; p2<n; p2++, p0++) {
                nums1[p0] = nums2[p2];
            }
        }
    }
};
