double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        int *temp = nums1;
        nums1 = nums2;
        nums2 = temp;

        int t = nums1Size;
        nums1Size = nums2Size;
        nums2Size = t;
    }

    int low = 0, high = nums1Size;
    int total = nums1Size + nums2Size;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (total + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int right1 = (cut1 == nums1Size) ? INT_MAX : nums1[cut1];

        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int right2 = (cut2 == nums2Size) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if (total % 2 == 0) {
                int left = left1 > left2 ? left1 : left2;
                int right = right1 < right2 ? right1 : right2;
                return (left + right) / 2.0;
            }

            return left1 > left2 ? left1 : left2;
        }

        if (left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }

    return 0.0;
}
