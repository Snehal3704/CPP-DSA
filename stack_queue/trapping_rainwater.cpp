#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int trap(vector<int> arr) {
            int n = arr.size();
            int leftmax = 0;
            int rightmax = 0;
    
            int left = 0;
            int right = n - 1;
            int sum = 0;
    
            while(left <= right){
                if(arr[left] <= arr[right]){
                    if(arr[left] >= leftmax){
                        leftmax = arr[left];
                    }
                    else{
                        sum += leftmax - arr[left];
                    }
                    left++;
                }
                else{
    
                    if(arr[right] >= rightmax){
                        rightmax = arr[right];
                    }
                    else{
                        sum += rightmax - arr[right];
                    }
                    right--;
                }
            }
            return sum;
        }

        vector<int> LGE(vector<int>arr){
            vector<int> res(arr.size());
            res[0] = arr[0];
        
            for(int i = 1  ; i < arr.size() ; i++){
                res[i] = max(arr[i] , res[i - 1]);
            }
            return res;
        }
    
        vector<int> RGE(vector<int> arr){
            int n = arr.size();
            vector<int> rightMax(arr.size());
            rightMax[n - 1] = arr[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i + 1], arr[i]);
            }
            return rightMax;
        }
    
        int brute(vector<int>& arr) {
            vector<int> get_left_max = LGE(arr);
            vector<int> get_right_max = RGE(arr);
            int sum = 0;
    
            for(int i = 0 ; i < arr.size() ; i++){
                int water = min (get_left_max[i],get_right_max[i]) - arr[i];
    
                sum +=water;
            }
            return sum;
        }
};


int main() {
    vector < int > arr;
    arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution obj;

    cout << "The water that can be trapped is " << obj.trap(arr) << endl;
  }

