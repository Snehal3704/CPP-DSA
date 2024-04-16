#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high)
{
    vector<int> temp;
    int left=low ;
    int  right =mid+1;
    while(low <=mid and right <= high)
    {
       if( arr[left] <= arr[right])
       {
            temp.push_back(arr[left]);
            left++;
       }
       else{
            temp.push_back(arr[right]);
            right++;
       }
    }
     while (left <= mid) {          // after incrementing and pushing all right elements if any left side elements "left" then we push it
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {    //// after incrementing and pushing all left elements if any right side elements "left" then we push it
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
    
}
void mergesort(vector<int> &arr,int low,int high)
{
    if(low >= high)     return;
    int mid = (low + high )/2;

    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main()
{
    int size;
    vector<int> arr;
    cout<<"enter the array size";
    cin>>size;
    for(int i =0 ; i< size ; i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < size-1; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergesort(arr, 0, size - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < size-1; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}