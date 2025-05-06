#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            //we need to somehow store old and new number both in a number so that if needed the past no we can get the past no
            //first thought is just add old and new number but after addition if we need past number we doesnot know how we get addition 
            //ex old = 5 , new =4 add = 9
            //if we need arr[arr[i]] then we get 9 and we doesnot know how we get 9 it can be 2 + 7 =9 or 3 + 6 = 9 or 4 + 5 =9
            // so we use a = bq +r
            //a / b = q
            //a % b = r
            // old + new * n = x(as ques says element is 0 to n-1 so we can pickup any number after n)
            // x / n = old
            //x % n = new
    
            int n = nums.size();
            for(int i= 0 ; i  < n ; i++){
                //nums[i] will store nums[nums[i]]
                // we are storing num[i] as a number so that we get the original and new number so nums[i] will have mix number of old and new
                int original = nums[nums[i]] % n;
    
                //storing new nums[i](which have both old and new val)
    
                nums[i] = nums[i] + n * original;
    
    
            }
    
            for(int i = 0 ; i < n ; i++){
                // to get new value from the specia l no we do x / n
                nums[i] = nums[i] / n;
            }
            return nums;
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {5, 0, 1, 2, 3, 4};
    vector<int> ans = sol.buildArray(nums);
    for(int num : ans)
        cout << num << " ";
    return 0;
}
