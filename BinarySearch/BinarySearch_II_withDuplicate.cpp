/* Binary Search in a Non-Decreasing Rotated Array (With Duplicates)
||
|| Two Pointers
||
|| Subarray(l...r) = A smaller(Sub) Array inside an Array with all elements from Index l...r
||
|| Note: The array itself is a Subarray of it.
||
|| After rotation, the array can be thought of two sorted Subarrays stacked together.
|| And note that all elements in the first sorted Subarray are strictly greater than all elements in the second sorted Subarray (due to rotation).
|| We use the first element (of the first Subarray) as our Anchor to determine the Subarray
||
|| Now, if both the target and middle element are in the same Subarray, BinarySearch the target. If mid is not in the same Subarray as Target, move towards the correct Subarray
|| And if there is block of duplicates of the Anchor (making determination of the subarray ambiguos), move to the previous element.
||
|| So, we discard half the array every iteration or a block of duplicates equal to the Anchor
||
|| Note: Even if there is no rotation, the code handles it as then both target and middle element would fall in the same subarray.
|| Note: Any duplicate block other than that of the Anchor is treated as if a single element 
||
|| Time Complexity: O(log (N - K) + K), K is traversed duplicates of the Anchor
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

        int saveMid = mid;
        while(mid > l && arr[mid] == arr[0]) mid--;
        
        bool midInRot = arr[mid] < arr[0];
        
        if (!(targetInRot ^ midInRot)) {
            if (arr[mid] < target)
                l = saveMid + 1;
            else if (target < arr[mid])
                r = mid - 1;
            else // if (arr[mid] == target)
                return mid;
        } else if (targetInRot /* && !midInRot*/) { 
            l = saveMid + 1; 
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
