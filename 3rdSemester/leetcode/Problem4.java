class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int l1 = nums1.length;
        int l2 = nums2.length;
        int[] res = new int[l1 + l2];
        int i1 = 0;
        int i2 = 0;
        for (int i = 0; i < l1 + l2; i++) {
            if (i1 >= l1) {
                res[i] = nums2[i2];
                i2++;
            } else if (i2 >= l2) {
                res[i] = nums1[i1];
                i1++;
            } else if (nums1[i1] < nums2[i2]) {
                res[i] = nums1[i1];
                i1++;
            } else {
                res[i] = nums2[i2];
                i2++;
            }
        }
        if ((l1 + l2) % 2 == 0) {
            return ((double) res[(l1 + l2) / 2] + (double)res[(l1 + l2) / 2 - 1]) / 2;
        } else {
            return res[(l1 + l2) / 2];
        }
    }
}