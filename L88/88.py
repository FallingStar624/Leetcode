from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        p0, p1, p2 = 0, 0, 0
        tmp = nums1[:m]
        while p1 < m and p2 < n:
            if tmp[p1] <= nums2[p2]:
                nums1[p0] = tmp[p1]
                p1 += 1
            else:
                nums1[p0] = nums2[p2]
                p2 += 1
            p0 += 1

        if p1 < m:
            nums1[p0:] = tmp[p1:]
        elif p2 < n:
            nums1[p0:] = nums2[p2:]
        else:
            pass
