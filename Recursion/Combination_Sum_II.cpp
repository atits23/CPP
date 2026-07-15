#include<bits/stdc++.h>
using namespace std;
void print_all_subsequence_with_repeat(vector<int> & arr,vector<int>& temp,int index,int target,vector<vector<int>>&ans){
    if(target==0){
            ans.push_back(temp);
        }
    for(int i=index;i<arr.size();i++){
        if(arr[i]>target){ break;}
        if(i!=index && arr[i]==arr[i-1]){continue;}
        temp.push_back(arr[i]);
        print_all_subsequence_with_repeat(arr,temp,i+1,target-arr[i],ans);
        temp.pop_back();
    }
}


int main(){
    vector<int> arr={1,1,2};
    vector<vector<int>>ans;
    vector<int> temp;
    int target=2;
    sort(arr.begin(),arr.end());
    print_all_subsequence_with_repeat(arr,temp,0,target,ans);
    for (auto &subseq : ans) {
    for (int num : subseq) {
        cout << num << " ";
    }
    cout << endl;}
    return 0;
}