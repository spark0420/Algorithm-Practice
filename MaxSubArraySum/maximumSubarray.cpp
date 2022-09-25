
#include <limits.h>
#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int max(int a, int b, int c){
     return max(max(a, b), c);
}


int maxCrossingSum(int arr[], int l, int m, int h)
{
	// Include elements on left of mid.
	int sum = 0;
	int left_sum = INT_MIN;
	for (int i = m; i >= l; i--) {
		sum = sum + arr[i];
		if (sum > left_sum)
			left_sum = sum;
	}

	// Include elements on right of mid
	sum = 0;
	int right_sum = INT_MIN;
	for (int i = m; i <= h; i++) {
		sum = sum + arr[i];
		if (sum > right_sum)
			right_sum = sum;
	}

	// Return sum of elements on left and right of mid
	// returning only left_sum + right_sum will fail for
	// [-2, 1]
	return max(left_sum + right_sum - arr[m], left_sum, right_sum);
}

// Returns sum of maximum sum subarray in aa[l..h]
int maxSubArraySum(int arr[], int left, int right)
{
	//Invalid Range: low is greater than high
	if (left > right)
		return INT_MIN;
	// Base Case: Only one element
	if (left == right)
		return arr[left];

	// Find middle point
	int mid = (left + right) / 2;

	/* Return maximum of following three possible cases
			a) Maximum subarray sum in left half
			b) Maximum subarray sum in right half
			c) Maximum subarray sum such that the subarray
	crosses the midpoint */
	return max(maxSubArraySum(arr, left, mid - 1),
			maxSubArraySum(arr, mid + 1, right),
			maxCrossingSum(arr, left, mid, right));
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int arr[] = {24, -9, -39, 1, 41, 10, 23, -29, -15, -4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int max_sum = maxSubArraySum(arr, 0, n - 1);

	printf("Maximum contiguous sum is %d\n", max_sum);
	getchar();
    
	return 0;
}
