#include<bits/stdc++.h>
using namespace std;
//Concept of pick not pick
void print_all_subsequence(vector<int> & arr,vector<int> temp,int index){
    if(index==arr.size()){
        // cout<<"Printing Please wait"<<endl;
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<"";
        }
        cout<<endl;
        return;
    }
    
    print_all_subsequence(arr,temp,index+1);
    temp.push_back(arr[index]);
    print_all_subsequence(arr,temp,index+1);
    
}

int main(){
    vector<int> arr={1,2,3};
    vector<int> temp;
    print_all_subsequence(arr,temp,0);
    return 0;
}