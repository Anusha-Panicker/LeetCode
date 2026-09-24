double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    
    // Always perform binary search on the smaller array
    if (m > n) {
        return findMedianSortedArrays(nums2, n, nums1, m);
    }

    int left = 0;
    int right = m;

    while (left <= right) {

        // Partition nums1
        int partition1 = (left + right) / 2;

        // Partition nums2
        int partition2 = (m + n + 1) / 2 - partition1;

        // Elements on left side
        int maxLeft1;
        int maxLeft2;

        if (partition1 == 0)
            maxLeft1 = -1000000000;
        else
            maxLeft1 = nums1[partition1 - 1];

        if (partition2 == 0)
            maxLeft2 = -1000000000;
        else
            maxLeft2 = nums2[partition2 - 1];

        // Elements on right side
        int minRight1;
        int minRight2;

        if (partition1 == m)
            minRight1 = 1000000000;
        else
            minRight1 = nums1[partition1];

        if (partition2 == n)
            minRight2 = 1000000000;
        else
            minRight2 = nums2[partition2];

        // Correct partition
        if (maxLeft1 <= minRight2 &&
            maxLeft2 <= minRight1) {

            // Total number of elements is odd
            if ((m + n) % 2 == 1) {
                return (double)(
                    maxLeft1 > maxLeft2 ? maxLeft1 : maxLeft2
                );
            }

            // Total number of elements is even
            int leftMax = maxLeft1 > maxLeft2
                        ? maxLeft1 : maxLeft2;

            int rightMin = minRight1 < minRight2
                         ? minRight1 : minRight2;

            return ((double)leftMax + rightMin) / 2.0;
        }

        // Move partition in nums1
        else if (maxLeft1 > minRight2) {
            right = partition1 - 1;
        }

        else {
            left = partition1 + 1;
        }
    }

    return 0.0;
}