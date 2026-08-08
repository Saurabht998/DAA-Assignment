int findKthLargest(int* nums, int numsSize, int k) {
    int left = 0, right = numsSize - 1;
    int target = k - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int pivot = nums[mid];

        int i = left, j = left, p = right;

        while (j <= p) {
            if (nums[j] > pivot) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j++;
            } else if (nums[j] < pivot) {
                int temp = nums[j];
                nums[j] = nums[p];
                nums[p] = temp;
                p--;
            } else {
                j++;
            }
        }

        if (target < i)
            right = i - 1;
        else if (target > p)
            left = p + 1;
        else
            return nums[target];
    }

    return -1;
}
