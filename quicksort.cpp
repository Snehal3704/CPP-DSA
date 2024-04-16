#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int pertition(int *arr,int low , int high)
{
    int pivot = arr[low];
    int i = low,j = high;
    while(i<j)
    {
        while(arr[i] <= arr[low] and i<= high -1) 
        {
            i++;
        }
        while(arr[j] > arr[low] and j >= low +1)
        {
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;



}

void quicksort(int *arr,int low,int high) //or int* quicksort(int *arr,int low,int high){return arr;}
{
    if(low < high) 

    {
        int pertition_index = pertition ( arr,low,high);
        quicksort(arr,low,pertition_index -1);
        quicksort(arr,pertition_index +1 ,high);

    }
    

}

int main()
{
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

    quicksort(arr, 0, n - 1); //arr=quicksort(arr,0,n-1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  

    return 0;
}