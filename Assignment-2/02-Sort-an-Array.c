void merge(int *nums, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];

    while (i <= mid && j <= right) {
        if (nums[i] < nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while (i <= mid)
        temp[k++] = nums[i++];

    while (j <= right)
        temp[k++] = nums[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        nums[i] = temp[k];
}

void sort(int *nums, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    sort(nums, left, mid);
    sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    sort(nums, 0, numsSize - 1);
    return nums;
}
