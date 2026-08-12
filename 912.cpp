#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& arr,int low,int mid,int high){
        vector<int> temp;
        int left = low; int right = mid + 1;

        while(left <= mid && right <= high){
            if(arr[left] <= arr[right])
            temp.push_back(arr[left++]);
            else 
            temp.push_back(arr[right++]);
        }

        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        while(right <= high){
            temp.push_back(arr[right++]);
        }

        for(int i = low;i <= high;i++){
            arr[i] = temp[i-low];
        }
    }
    void mergeSort(vector<int>& arr,int low,int high){
        if(low >= high)
        return;
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);

        return nums;
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
    sol.sortArray(arr);
    for(int nums : arr){
        cout << nums <<" ";
    }
}