#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int num_ways(int target,vector<int>&arr,vector<long long>&dp){
    if(target<0) return 0;
    if(target==0)return 1;
    if(dp[target]!=-1)return dp[target];
    int ways=0;
    for(int i=0;i<arr.size();i++){
            ways=(ways+num_ways(target-arr[i],arr,dp))%mod;
    }

    return dp[target]=(ways)%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    vector<int>dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=x;i++){
        long long ways=0;
        for(int j=0;j<arr.size();j++){
            if(i-arr[j]>=0) ways=(ways+dp[i-arr[j]]);
            if(ways>=mod)ways-=mod;
        }
    dp[i]=(ways);
    }
    cout<<dp[x]<<endl;

}