#include<bits/stdc++.h>
int Mod=1e9+7;
using namespace std;
// int count_ways(vector<int>& dice,int n,vector<int>& dp){
//     if(n==0){
//         return 1;
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     int total_ways=0;
//     for(int i=0;i<6;i++){
//         if(n-dice[i]>=0){
//             total_ways+=count_ways(dice,n-dice[i],dp)%Mod;
//         }
//     }
//     return dp[n]=total_ways%Mod;
// }
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    vector<int>dice={1,2,3,4,5,6};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        long long total_ways=0;
        for(int j=0;j<6;j++){
        if(i-dice[j]>=0){
            total_ways+=dp[i-dice[j]]%Mod;
        }
    }
        dp[i]=total_ways%Mod;
    }
    int ways=dp[n];
    cout<<ways<<endl;

}