
#include <limits.h>
#include <stdio.h>

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int max(int a, int b, int c){
    int currMax = max(a, b);
    currMax = max(currMax, c);

    return currMax;
}

int maxCrossingSum(int arr[], int left, int mid, int right)
{
	int sum = 0;
	int left_sum = INT_MIN;

	for (int i = mid; i >= left; i--) {
		sum = sum + arr[i];
		if (sum > left_sum){
			left_sum = sum;
        }
	}

	sum = 0;
	int right_sum = INT_MIN;

	for (int i = mid; i <= right; i++) {
		sum = sum + arr[i];
		if (sum > right_sum){
			right_sum = sum;
        }
	}

	return max(left_sum + right_sum - arr[mid], left_sum, right_sum);
}

int maxSubArraySum(int arr[], int left, int right)
{
	if (left > right)
		return INT_MIN;

    if(left == right){
        return arr[left];
    }

    int mid = (left + right) / 2;

    int leftMax = maxSubArraySum(arr, left, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, right);
    int midMax = maxCrossingSum(arr, left, mid, right);
    printf("leftMax = %d, left = %d, mid = %d\n", leftMax, left, mid);
    printf("rightMax = %d, mid+1 = %d, right = %d\n", rightMax, mid+1, right);
    printf("midMax = %d, left = %d, mid = %d, right = %d\n\n\n", midMax, left, mid, right);

    return(max(leftMax, rightMax, midMax));
}

int main()
{
	int arr[] = {24, -9, -39, 1, 41, 10, 23, -29, -15, -4};
	int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for(int i = 0; i < arrSize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

	int maxSum = maxSubArraySum(arr, 0, arrSize - 1);

	printf("Maximum sum of Subarray = %d\n", maxSum);
    
	return 0;
}
