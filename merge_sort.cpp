#include <iostream>
#include <vector>  // Include the necessary header for the vector class
using namespace std;

// Function prototypes
void mergesort(int *arr, int low, int high);
void merge(int *arr, int low, int mid, int high);

int main() {
    int n = 0;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];  // Correctly allocate the array with square brackets

    for (int i = 0; i < n; i++) {
        cout << "Enter the value for index " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergesort(arr, 0, n - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  

    return 0;
}


void mergesort(int *arr, int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}


void merge(int *arr, int low, int mid, int high) {
    vector<int> temp;  // temporary array
    int left = low;    // starting index of the left half of arr
    int right = mid + 1; // starting index of the right half of arr

    while(low <=mid and right <= high)
    {
        if(arr[left] <= arr[right]){
        temp.push_back(arr[left]);
        left++;
        }
        else{
        temp.push_back(arr[right]);
        right++;
        }
    }
    while(left <=mid)       // Copy remaining elements from left half, if any
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <=high)     // Copy remaining elements from right half, if any
    {
        temp.push_back(arr[right]);
        right++;
    }
    
    // Copy elements from temp array back to original array
    for (int i = 0; i < temp.size(); i++) {
        arr[low + i] = temp[i];
    }
}
