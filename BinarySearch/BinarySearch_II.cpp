/* Binary Search in an Ascending Rotated Array (Strictly Increasing)
||
|| Two Pointers
||
|| Subarray(l...r) = A smaller(Sub) Array inside an Array with all elements from Index l...r
||
|| Note: The array itself is a Subarray of it.
||
|| After rotation, the array can be thought of two sorted Subarrays stacked together.
|| And note that all elements in the first sorted Subarray are strictly greater than all elements in the second sorted Subarray (due to rotation).
||
|| Now, if both the target and middle element are in the same Subarray, BinarySearch the target.
|| And if mid is not in the same Subarray as Target, move towards the correct Subarray
|| 
|| So, we discard half the array every iteration
||
|| Note : Even if there is no rotation, the code handles it as then both target and middle element would fall in the same subarray.
||
|| Time Complexity: O(log N)
|| Space Complexity: O(N) Input / O(1) Algo
||
*/

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    
    bool targetInRot = target < arr[0];
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        bool midInRot = arr[mid] < arr[0];
        
        if (!(targetInRot ^ midInRot)) {
            if (arr[mid] < target)
                l = mid + 1;
            else if (target < arr[mid])
                r = mid - 1;
            else // if (arr[mid] == target)
                return mid;
        } else if (targetInRot /* && !midInRot*/) { 
            l = mid + 1; 
        } else if (midInRot /* && !targetInRot*/) {
            r = mid - 1;
        }
    }
    
    return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, target;
	cin >> n >> target;
	
	vector<int> arr(n, 0);
	for(int &a : arr) cin >> a;

	int tar_indx = search(arr, target); 
	
	if(tar_indx != -1) cout << "Found in indx: " << tar_indx << '\n';
	else cout << "Target not found.\n";

	return 0;
}
