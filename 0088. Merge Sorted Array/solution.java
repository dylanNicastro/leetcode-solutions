class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        m--;
        n--;
        int total = m+n+1;
        while (n >= 0) {
            if (m >= 0 && nums1[m] > nums2[n]) {
                nums1[total] = nums1[m];
                total--;
                m--;
            }
            else {
                nums1[total] = nums2[n];
                total--;
                n--;
            }
        }
    }
}