#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
       int N = nums.size();
       int count = 0;
       for(int i = 0;i < N - 1;i++){
        if(nums[i] > nums[ i + 1])
        count ++;
       }
       if (nums[N - 1] > nums[0]) {
        count++;
    }
        return count <=1;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    Solution sol;
    int ans = sol.check(arr);
    cout << (ans ? "True" : "False");
}