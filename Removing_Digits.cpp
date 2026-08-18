#include<bits/stdc++.h>
using namespace std;
int min_steps(int n,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int num=n;
    int ans=1e9;
    while(num!=0){
        int digit=num%10;
        if(n-digit>=0 && digit!=0)ans=min(ans,1+min_steps(n-digit,dp));
        num/=10;
    }
    return dp[n]=ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++){
        int num=i;
        int ans=1e9;
        while(num!=0){
            int digit=num%10;
            if(i-digit>=0 && digit!=0)ans=min(ans,1+dp[i-digit]);
            num/=10;
        }
        dp[i]=ans;
    }
    
    cout<<dp[n]<<endl;
    return 0;
}