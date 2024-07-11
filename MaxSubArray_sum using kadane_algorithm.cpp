#include <bits/stdc++.h>

using namespace std;


// Time Complexity = O(N*N)
// Space Complexity = O(1)
void bruteforce(vector<int> &arr, int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]

            // add all the elements of subarray:
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }

    // Added label for clarity
    cout << "Maximum subarray sum using brute force: " << maxi << endl;
}


// Time Complexity = O(N)
// Space Complexity = O(1)

// KADANE'S ALGORITHM

/* A subarray with a sum less than 0 will always reduce our answer 
and so this type of subarray cannot be a part of the subarray with maximum sum.
Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. 
Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. 
Among all the sums calculated, we will consider the maximum one.

Thus we can solve this problem with a single loop.*/

void optimal_Kadanes(vector<int> &arr, int n) {
    long long maxi = INT_MIN;
    long long sum = 0;
    int ansStart = -1, ansEnd = -1;
    int start = 0;

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i;

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // Uncomment the following check to consider the sum of the empty subarray
    // if (maxi < 0) maxi = 0;

    // Added label and fixed the loop condition to print the subarray correctly
    cout << "Subarray with the maximum sum: ";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }

    // Added label for clarity
    cout << endl << "Maximum subarray sum using Kadane's algorithm: " << maxi << endl;
}

int main() {
    // Fixed the prompt message
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    // Initialized the vector with size n
    vector<int> arr(n);

    // Fixed the prompt message
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Calling both functions for demonstration
    bruteforce(arr, n);
    optimal_Kadanes(arr, n);

    return 0;
}
