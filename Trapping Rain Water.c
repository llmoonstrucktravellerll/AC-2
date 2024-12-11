int trap(int* arr, int n) {
    int left =0 ,right = n-1;
    int left_max=arr[left],right_max = arr[right],water=0;
    while(left <= right){
        if(arr[left]<=arr[right]){
            left_max  = (left_max>arr[left])?left_max:arr[left];
            int t = left_max - arr[left];
            water += t;
            left++;
        }
        else  if(arr[left]>arr[right]){
            right_max  = (right_max>arr[right]) ? right_max : arr[right];
            int t = right_max - arr[right];
            water += t;
            right--;
        }
    }
    return water;
}
