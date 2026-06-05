/* Binary Search in an Ascending / Non-Decreasing Array (with Duplicates)
||
|| Two Pointers
||
|| Subarray(l...r) = A smaller(Sub) Array inside an Array with all elements from Index l...r
||
|| Note: The array itself is a Subarray of it
||
|| If the middle element of Subarray(l...r) (sorted) is less than Target,|| the target does not exist in Subarray(l...mid)
|| We should look for Target in Subarray(mid + 1, r)
||
|| Likewise if the middle element is greater than Target, 
|| the target does not exist in Subarray(mid...r)
|| We should look for Target in Subarray(l, mid - 1)
||
|| So, we basically discard half the array every iteration
||
|| Notes: Duplicate blocks do not make a difference. They are treated the same.
||
|| Time Complexity: O(log N)
|| Space Complexity: O(N) Input / O(1) Algo
||
*/

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& arr, int target) {
    int l = 0;
    int r = arr.size() - 1;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        
        if(arr[mid] < target) 
            l = mid + 1;
        else if(target < arr[mid])
            r = mid - 1;
        else // if (arr[mid] == target)
            return mid;
    }

    return -1; // Target not found
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
