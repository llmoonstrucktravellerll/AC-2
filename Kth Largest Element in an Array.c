void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int *nums, int left, int right, int index)
{
    int pivot = nums[index];

    left -= 1;
    right += 1;

    while (true) {
        do {
            left += 1;
        } while (nums[left] > pivot);
        do {
            right -= 1;
        } while (nums[right] < pivot);

        if (left >= right)
            return right;

        swap(&nums[left], &nums[right]);
    }
}

int _select(int *nums, int left, int right, int k)
{
    if (left == right)
        return nums[left];

    int pivotIndex = partition(nums, left, right, left + (right - left) / 2);
    
    if (k <= pivotIndex)
        return _select(nums, left, pivotIndex, k);
    else
        return _select(nums, pivotIndex + 1, right, k);
}

int quickselect(int *nums, int size, int k)
{
    return _select(nums, 0, size - 1, k - 1);
}

int findKthLargest(int *nums, int numsSize, int k){
    if (nums == NULL || k > numsSize)
        return -1;
    return quickselect(nums, numsSize, k);
}
