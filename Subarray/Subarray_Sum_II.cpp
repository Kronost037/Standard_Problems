/* Subarray Sum Equals K (Handles Negative Integers)
||
|| Prefix Sums
|| 
|| Subarray(L...R) = A smaller(Sub) array inside an array with all elements from Index L...R
|| Subarray-Sum(L...R) = Sum of elements in Subarray(L...R) 
|| Pref[i] = Subarray-Sum(0...i)
||
|| Subarray-Sum(L...R) = Pref[R] - Pref[L - 1]
|| We want Subarray-Sum(L...R) = Target --> Pref[R] - Pref[L - 1] = Target --> Pref[R] - Target = pref[L - 1]
|| So, If ( Sum till R ) - Target == ( Sum till some indices before R ), cnt += how many such indices exist
||
|| Pref[R] - x = pref[L - 1] --> cnt += sumFrequemcy[pref[l - 1]
|| 
|| Note: Prefix Array is not explicitly required. We only need Pref[R], sum upto current index
|| Time Complexity: O(Nlog N)
|| Space Complexity: O(N) 
||
*/

#include <bits/stdc++.h>

using namespace std;

// Counts subarrays whose elements sum to the target.
long long subarraySum(vector<int> &arr, long long target) {
    int n = arr.size();
    long long cnt = 0;
    long long sum = 0;

    // {PrefixSum : OccurrenceCount}
    map<long long, int> sumFreq;

    // Base Case: An empty subarray has a sum of 0. Count subarrays starting at index 0.
    sumFreq[0] = 1;

    for (int R = 0; R < n; R++) {
        sum += arr[R];
        long long need = sum - target;
        cnt += sumFreq[need];
        sumFreq[sum]++;
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    long long cnt = subarraySum(arr, target);
    cout << cnt << '\n';

    return 0;
}

// Problem Links:
// https://cses.fi/problemset/task/1661
// https://leetcode.com/problems/subarray-sum-equals-k
