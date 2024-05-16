#include<bits/stdc++.h>
using namespace std;

void getpermutations( vector<int> &arr, int size, int ind) {

    if(ind == size){
        cout<<"[";

        for(auto it : arr){
            cout<<it;
        }
        cout<<"]";
        cout<<endl;
        
        return;
    }

    for(int i = ind ; i< size ; i++){
        swap(arr[ind],arr[i]);
        
        getpermutations(arr,size, ind + 1);
        swap(arr[ind],arr[i]);

    }
    


}

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    cout << "Enter values: ";
    vector<int> arr(size);

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    
    vector<int> temp;

    getpermutations(arr, size, 0);


    return 0;
}
