#include<bits/stdc++.h>
using namespace std;
void print_all_subsequence_with_repeat(vector<int> & arr,vector<int>& temp,int index,int target,set<vector<int>>&ans){
    if(target==0){
        ans.insert(temp);
        return;
    }
    if(index>arr.size()){return;}
    if(arr[index]<=target){
    temp.push_back(arr[index]);
    print_all_subsequence_with_repeat(arr,temp,index+1,target-arr[index],ans);
    temp.pop_back();}
    print_all_subsequence_with_repeat(arr,temp,index+1,target,ans);
}


int main(){
    vector<int> arr={10,1,2,7,6,1,5};
    set<vector<int>>ans;
    vector<int> temp;
    int target=8;
    print_all_subsequence_with_repeat(arr,temp,0,target,ans);
    for (auto &subseq : ans) {
    for (int num : subseq) {
        cout << num << " ";
    }
    cout << endl;
}

    return 0;
}